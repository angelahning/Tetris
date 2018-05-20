#include <iostream>
#include "board.h"
#include "levelfour.h"
#include "block.h"
#include "starblock.h"

using namespace std;

//Board consturctor
Board::Board(){
  this->highScore = 0;
}

//intialize a board
void Board::init(bool textOnlyMode){
  this->theBoard.clear();
  this->textDisplay = make_shared<TextDisplay>(18, 11);
  this->textOnly = textOnlyMode;
  if (!this->textOnly){
    this->graphicsDisplay = make_shared<GraphicsDisplay>();
  }
  for (int i = -3; i < 0; ++i){
    auto p = make_shared<Line>(i);
    p->attach(this->textDisplay);
    if (!this->textOnly){
      p->attach(this->graphicsDisplay);
    }
    this->theBoard.emplace_back(p);
  }
  for(int i = 0; i < 15; ++i){
    auto p = make_shared<Line>(i);
    p->attach(this->textDisplay);
    if (!this->textOnly){
      p->attach(this->graphicsDisplay);
    }
    this->theBoard.emplace_back(p);
  }
  this->blockOnHold = false;
  this->currentScore = 0;
  if (!this->textOnly){
    graphicsDisplay->drawScore(this->currentScore);
    graphicsDisplay->drawHighScore(this->highScore);
    graphicsDisplay->drawLevel(this->currentLevel);
  }
}


bool Board::sendCurrentBlock(std::shared_ptr<Block> block, bool switchBlock){
  if (switchBlock){
    int prevBlockTop = this->currentBlock->getTopPos();
    int prevBlockBot = this->currentBlock->getBotPos();
    this->clearActive(prevBlockTop, prevBlockBot);
    this->notifyDisplay(prevBlockTop, prevBlockBot);
  }
  this->currentBlock = block;
  int blockTopPos = this->currentBlock->getTopPos();
  int blockBotPos = this->currentBlock->getBotPos();
  bool success = this->tryPutDown(blockTopPos, blockBotPos);
  if (!success){
    return false;
  }
  this->notifyDisplay(blockTopPos, blockBotPos);
  return true;
}


void Board::sendNextBlock(std::shared_ptr<Block> block){
  this->nextBlock = block;
  if (!this->textOnly){
    graphicsDisplay->drawNext(this->nextBlock);
  }
}

//public notify function to send notification to the observers
void Board::notifyDisplay(int topPos, int botPos){
  for(int i = topPos + 3; i <= botPos + 3; ++i){
    this->theBoard[i]->notifyObservers();
  }
}

//clear all current blocks' activity
void Board::clearActive(int topPos, int botPos){
  for (int i = topPos + 3; i <= botPos + 3; ++i){
    this->theBoard[i]->clearActive();
  }
}

//predicate function that try to put a block down, it success then
//    mutate the board and return true, else nothing change and return false
bool Board::tryPutDown(int topPos, int botPos){
  vector<shared_ptr<Line>> blockComponent = this->currentBlock->getComponent();
  for (int i = topPos + 3; i <= botPos + 3; ++i){
    bool success = this->theBoard[i]->merge(*blockComponent[i - topPos - 3]);
    if (!success){
      this->clearActive(topPos, botPos);
      return false;
    }
  }
  return true;
}

//if a row is ready to clear, clear it and add corresponding score and send notification
void Board::rowClearedAddScore(int numberOfLinesCleared){
  int scoreAdd = (this->currentLevel + numberOfLinesCleared) * (this->currentLevel + numberOfLinesCleared);
  this->currentScore += scoreAdd;
  if (this->highScore < this->currentScore){
    this->highScore = this->currentScore;
  }
  if (!this->textOnly){
    graphicsDisplay->drawScore(this->currentScore);
    graphicsDisplay->drawHighScore(this->highScore);
  }
}

//move the current block on the Board
void Board::move(char dir, int times){
  if (times > 14){
    times = 14;
  }
  int blockTopPos = this->currentBlock->getTopPos();
  int blockBotPos = this->currentBlock->getBotPos();
  int initTopPos = blockTopPos;
  int initBotPos = blockBotPos;
  this->clearActive(blockTopPos, blockBotPos);
  bool success = true;
  switch(dir){
    case 'l':{
      for (int i = 0; i < times; ++i){
        this->clearActive(blockTopPos, blockBotPos);
        this->currentBlock->doMove('l');
        success = this->tryPutDown(blockTopPos, blockBotPos);
        if (!success){
          break;
        }
      }
      if (!success){
        this->currentBlock->doMove('r');
        success = this->tryPutDown(blockTopPos, blockBotPos);
      }
      break;
    }
    case 'r':{
      for (int i = 0; i < times; ++i){
        this->clearActive(blockTopPos, blockBotPos);
        this->currentBlock->doMove('r');
        success = this->tryPutDown(blockTopPos, blockBotPos);
        if (!success){
          break;
        }
      }
      if (!success){
        this->currentBlock->doMove('l');
        success = this->tryPutDown(blockTopPos, blockBotPos);
      }
      break;
    }
    case 'd':{
      for (int i = 0; i < times; ++i){
        this->clearActive(blockTopPos, blockBotPos);
        this->currentBlock->verticalMove('d');
        blockTopPos = this->currentBlock->getTopPos();
        blockBotPos = this->currentBlock->getBotPos();
        success = this->tryPutDown(blockTopPos, blockBotPos);
        if (!success){
          break;
        }
      }
      if (!success){
        this->currentBlock->verticalMove('u');
        blockTopPos = this->currentBlock->getTopPos();
        blockBotPos = this->currentBlock->getBotPos();
        success = this->tryPutDown(blockTopPos, blockBotPos);
      }
      break;
    }
  }
  this->notifyDisplay(initTopPos, initBotPos);
  this->notifyDisplay(blockTopPos, blockBotPos);
}

//rotate the current block on the Board
void Board::rotate(char dir, int times){
  int blockTopPos = this->currentBlock->getTopPos();
  int blockBotPos = this->currentBlock->getBotPos();
  int initTopPos = blockTopPos;
  int initBotPos = blockBotPos;
  this->clearActive(blockTopPos, blockBotPos);
  if (dir == 'l'){
    for (int i = 0; i < times; ++i){
      this->currentBlock->doRotate('l');
    }
  } else if (dir == 'r'){
    for (int i = 0; i < times; ++i){
      this->currentBlock->doRotate('r');
    }
  }
  blockTopPos = this->currentBlock->getTopPos();
  blockBotPos = this->currentBlock->getBotPos();
  bool success = this->tryPutDown(blockTopPos, blockBotPos);
  while (!success){
    if (dir == 'l'){
      this->currentBlock->doRotate('r');
    } else if (dir == 'r'){
      this->currentBlock->doRotate('l');
    }

    blockTopPos = this->currentBlock->getTopPos();
    blockBotPos = this->currentBlock->getBotPos();
    success = this->tryPutDown(blockTopPos, blockBotPos);
  }
  int notifyTopPos = initTopPos;
  int notifyBotPos = initBotPos;
  if (initTopPos > blockTopPos){
    notifyTopPos = blockTopPos;
  }
  if (initBotPos < blockBotPos){
    notifyBotPos = blockBotPos;
  }
  this->notifyDisplay(notifyTopPos, notifyBotPos);
}

//predicate function that check a line is full(ready to clear) or not
bool Board::checkForFullLine(int topPos, int botPos){
  vector<int> linesToBePop;
  for (int i = topPos + 3; i <= botPos + 3; ++i){
    if (this->theBoard[i]->isFull()){
      linesToBePop.emplace_back(i);
    }
  }
  int numberOfLinesToBePop = linesToBePop.size();
  if (numberOfLinesToBePop > 0) {
    this->rowClearedAddScore(numberOfLinesToBePop);
    if (this->highScore < this->currentScore){
      this->highScore = this->currentScore;
    }
    for (auto lineNumber: linesToBePop){
      this->theBoard[lineNumber]->setPopState(true);
      this->theBoard[lineNumber]->notifyObservers();
      this->theBoard.erase(this->theBoard.begin() + lineNumber);
      auto p = make_shared<Line>();
      p->attach(this->textDisplay);
      if (!this->textOnly){
        p->attach(this->graphicsDisplay);
      }
      auto start = this->theBoard.begin() + 3;
      this->theBoard.insert(start, p);
    }
    int currentLineNumber = -3;
    for (auto lines: this->theBoard){
      if (currentLineNumber >= 0){
        lines->setLineNumber(currentLineNumber);
        lines->notifyObservers();
      }
      ++currentLineNumber;
    }
    this->blockClearedAddScore();
    return true;
  } else {
    return false;
  }
}

//if a block is completly cleared, clear it and add corresponding score and send notification
void Board::blockClearedAddScore(){
  vector<int> blocksToBePop;
  int size = this->blockOnBoard.size();
  int clearTimes = 0;
  for (int i = 0; i < size; ++i){
    if (this->blockOnBoard[i]->isCleared()){
      blocksToBePop.emplace_back(i);
      ++clearTimes;
    }
  }
  for (auto blockIndex: blocksToBePop){
    this->currentScore += (1 + this->blockOnBoard[blockIndex]->getLevel()) * (1 + this->blockOnBoard[blockIndex]->getLevel());
  }
  while (clearTimes > 0){
    int index;
    int remainSize = this->blockOnBoard.size();
    for (int i = 0; i < remainSize; ++i){
      if (this->blockOnBoard[i]->isCleared()){
        index = i;
      }
    }
    this->blockOnBoard.erase(this->blockOnBoard.begin() + index);
    --clearTimes;
  }
  if (this->highScore < this->currentScore){
    this->highScore = this->currentScore;
  }
  if (!this->textOnly){
    graphicsDisplay->drawScore(this->currentScore);
    graphicsDisplay->drawHighScore(this->highScore);
  }
}

//drop the current block on the Board
bool Board::drop(bool &rowCleared){
  int blockTopPos = this->currentBlock->getTopPos();
  int blockBotPos = this->currentBlock->getBotPos();
  if (blockBotPos == 14){
    for(int i = blockTopPos + 3; i <= blockBotPos + 3; ++i){
      this->theBoard[i]->setAllInactive();
      this->theBoard[i]->attach(this->currentBlock);
    }
    this->currentBlock->setTimesNeedToPop(blockBotPos - blockTopPos + 1);
    this->blockOnBoard.emplace_back(this->currentBlock);
    rowCleared = this->checkForFullLine(blockTopPos, blockBotPos);
    return true;
  }
  this->clearActive(blockTopPos, blockBotPos);
  int maxDownTime = 14 - blockBotPos;
  this->move('d', maxDownTime);
  blockTopPos = this->currentBlock->getTopPos();
  blockBotPos = this->currentBlock->getBotPos();
  if (blockTopPos < 0){
    return false;
  }
  for(int i = blockTopPos + 3; i <= blockBotPos + 3; ++i){
    this->theBoard[i]->setAllInactive();
    this->theBoard[i]->attach(this->currentBlock);
  }
  this->currentBlock->setTimesNeedToPop(blockBotPos - blockTopPos + 1);
  this->blockOnBoard.emplace_back(this->currentBlock);
  rowCleared = this->checkForFullLine(blockTopPos, blockBotPos);
  return true;
}

//getter function that return the lower position, easy to get best hint
int Board::getLowestPos(){
  int blockTopPos = this->currentBlock->getTopPos();
  int blockBotPos = this->currentBlock->getBotPos();
  bool success;
  for (int j = 0; j < 14; ++j){
    this->clearActive(blockTopPos, blockBotPos);
    this->currentBlock->verticalMove('d');
    blockTopPos = this->currentBlock->getTopPos();
    blockBotPos = this->currentBlock->getBotPos();
    success = this->tryPutDown(blockTopPos, blockBotPos);
    if (!success){
      break;
    }
  }
  if (!success){
    this->currentBlock->verticalMove('u');
    blockTopPos = this->currentBlock->getTopPos();
    blockBotPos = this->currentBlock->getBotPos();
    success = this->tryPutDown(blockTopPos, blockBotPos);
  }
  return blockBotPos;
}

//getter function that return the position of a block with lower position, easy to get best hint
int Board::getLowestPosOnDir(char dir, int &leftEnd){
  int lowestPos = 0;
  for (int i = 0; i < 11; ++i){
    if (i == 0){
      int currentPos = this->getLowestPos();
      if (lowestPos < currentPos){
        lowestPos = currentPos;
        leftEnd = i;
      }
    } else {
      this->currentBlock->doMove(dir);
      int currentPos = this->getLowestPos();
      if (lowestPos < currentPos){
        lowestPos = currentPos;
        leftEnd = i;
      }
    }
  }
  int blockTopPos = this->currentBlock->getTopPos();
  int blockBotPos = this->currentBlock->getBotPos();
  this->clearActive(blockTopPos, blockBotPos);
  return lowestPos;
}

//predicate function that try to put a hint block down to the board, if it success
//    then return true, else false
bool Board::putHintDown(int moveRightTimes, int rotateTimes, int moveDownTimes){
  for (int i = 0; i < rotateTimes; ++i){
    this->currentBlock->doRotate('r');
  }
  for (int i = 0; i < moveRightTimes; ++i){
    this->currentBlock->doMove('r');
  }
  for (int i = 0; i < moveDownTimes; ++i){
    if (this->currentBlock->getBotPos() == moveDownTimes){
      break;
    }
    this->currentBlock->verticalMove('d');
  }
  int topPos = this->currentBlock->getTopPos();
  int botPos = this->currentBlock->getBotPos();
  this->hintTopPos = topPos;
  this->hintBotPos = botPos;
  this->currentBlock->setHint();
  bool success = this->tryPutDown(topPos, botPos);
  this->notifyDisplay(topPos, botPos);
  return success;
}

//give the best hint based on the current board and current block
void Board::hint(){
  int currentTopPos = this->currentBlock->getTopPos();
  int currentBotPos = this->currentBlock->getBotPos();
  const char blockType = this->currentBlock->getType();
  const char direction = 'r';
  LevelFour lv;
  this->clearActive(currentTopPos, currentBotPos);
  this->hintBlock = this->currentBlock;
  this->currentBlock = lv.doGenerate(blockType);
  int leftEnd[4] = {0};
  int lowPos[4] = {0};
  int height[4] = {0};
  int bottomFill[4] = {0};
  int hintPos = 0;
  int hintEnd = 0;
  int hintRotate = 0;
  int hintHeight = 5;
  int hintBottomFill = 0;
  if (blockType == 'T' || blockType == 'J' || blockType == 'L'){
    lowPos[0] = getLowestPosOnDir(direction, leftEnd[0]);
    height[0] = this->currentBlock->getBotPos() - this->currentBlock->getTopPos();
    bottomFill[0] = this->currentBlock->getBottomFill();
    for (int i = 1; i < 4; ++i){
      this->currentBlock = lv.doGenerate(blockType);
      for (int j = 0; j < i; ++j){
        this->currentBlock->doRotate('r');
        height[i] = this->currentBlock->getBotPos() - this->currentBlock->getTopPos();
        bottomFill[i] = this->currentBlock->getBottomFill();
      }
      lowPos[i] = getLowestPosOnDir(direction, leftEnd[i]);
    }
  } else {
    lowPos[0] = getLowestPosOnDir(direction, leftEnd[0]);
    height[0] = this->currentBlock->getBotPos() - this->currentBlock->getTopPos();
    bottomFill[0] = this->currentBlock->getBottomFill();
    this->currentBlock = lv.doGenerate(blockType);
    this->currentBlock->doRotate('r');
    lowPos[1] = getLowestPosOnDir(direction, leftEnd[1]);
    height[1] = this->currentBlock->getBotPos() - this->currentBlock->getTopPos();
    bottomFill[1] = this->currentBlock->getBottomFill();
  }
  for (int i = 0; i < 4; ++i){
    if (hintPos < lowPos[i]){
      hintPos = lowPos[i];
      hintEnd = leftEnd[i];
      hintRotate = i;
      hintHeight = height[i];
      hintBottomFill = bottomFill[i];
    } else if (hintPos == lowPos[i] && hintHeight > height[i]){
      hintPos = lowPos[i];
      hintEnd = leftEnd[i];
      hintRotate = i;
      hintHeight = height[i];
      hintBottomFill = bottomFill[i];
    } else if (hintPos == lowPos[i] && hintHeight == height[i] && hintBottomFill < bottomFill[i]){
      hintPos = lowPos[i];
      hintEnd = leftEnd[i];
      hintRotate = i;
      hintHeight = height[i];
      hintBottomFill = bottomFill[i];
    }
  }
  this->currentBlock = lv.doGenerate(blockType);
  this->putHintDown(hintEnd, hintRotate, hintPos);
  this->currentBlock = this->hintBlock;
  currentTopPos = this->currentBlock->getTopPos();
  currentBotPos = this->currentBlock->getBotPos();
  this->tryPutDown(currentTopPos, currentBotPos);
  this->notifyDisplay(currentTopPos, currentBotPos);
}

//clear the hint off the board once the player move the block
void Board::clearHint(){
  for (int i = this->hintTopPos + 3; i <= this->hintBotPos + 3; ++i){
    this->theBoard[i]->clearHint();
  }
  this->notifyDisplay(this->hintTopPos, this->hintBotPos);
}

//drop corresponding star block at harder level(4)
void Board::dropStarBlock(bool &rowCleared){
  LevelFour lv;
  this->currentBlock = lv.genStarBlock();
  this->drop(rowCleared);
}

//setter function that change current level
void Board::levelChange(int level){
  this->currentLevel = level;
  if (!this->textOnly){
    graphicsDisplay->drawLevel(level);
  }
}

//Extra feature: hold the current block and use the next block at current turn
//    player can switch the holding block back and switch it
//    with the current block at that turn
bool Board::hold(shared_ptr<Level> level){
  if (this->blockOnHold){
    int lastTopPos = this->currentBlock->getTopPos();
    int lastBotPos = this->currentBlock->getBotPos();
    int blockType = this->currentBlock->getType();
    this->clearActive(lastTopPos, lastBotPos);
    this->currentBlock = this->holdBlock;
    this->holdBlock = level->doGenerate(blockType);
    this->notifyDisplay(lastTopPos, lastBotPos);
    int currentTopPos = this->currentBlock->getTopPos();
    int currentBotPos = this->currentBlock->getBotPos();
    this->tryPutDown(currentTopPos, currentBotPos);
    this->notifyDisplay(currentTopPos, currentBotPos);
    if(!this->textOnly){
      this->graphicsDisplay->drawHold(this->holdBlock);
    }
    return true;
  } else {
    this->blockOnHold = true;
    int lastTopPos = this->currentBlock->getTopPos();
    int lastBotPos = this->currentBlock->getBotPos();
    int blockType = this->currentBlock->getType();
    this->clearActive(lastTopPos, lastBotPos);
    this->holdBlock = level->doGenerate(blockType);
    this->notifyDisplay(lastTopPos, lastBotPos);
    if(!this->textOnly){
      this->graphicsDisplay->drawHold(this->holdBlock);
    }
    return false;
  }
}

void Board::sendLostToGraphic(){
  this->graphicsDisplay->endGame();
}

//overload function opreator<< in order to cout a board
ostream &operator<<(ostream &out, const Board &board){
  out << endl;
  out << "Level:    " << board.currentLevel << endl;
  out << "Score:    " << board.currentScore << endl;
  out << "Hi Score: " << board.highScore << endl;
  out << "-----------" << endl;
  out << (*board.textDisplay);
  out << "-----------" << endl;
  out << "Next:      " << endl;
  out << (*board.nextBlock);
  out << "Hold:      " << endl;
  if (board.blockOnHold){
    out << (*board.holdBlock);
  } else {
    out << endl;
  }
  out << endl;
  return out;
}
