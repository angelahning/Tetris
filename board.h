#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include <memory>
#include "line.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

//forward declaration of relate classes
class Block;
class Level;

class Board{
  std::vector<std::shared_ptr<Line>> theBoard;
  std::shared_ptr<TextDisplay> textDisplay;
  std::shared_ptr<GraphicsDisplay> graphicsDisplay;
  std::shared_ptr<Block> currentBlock;
  std::shared_ptr<Block> hintBlock;
  std::shared_ptr<Block> holdBlock;
  int hintTopPos = 0;
  int hintBotPos = 0;
  std::shared_ptr<Block> nextBlock;
  std::vector<std::shared_ptr<Block>> blockOnBoard;
  int currentScore;
  int highScore;
  int currentLevel;
  bool textOnly;
  bool blockOnHold;
  // try putting down the block at a certain location
  bool tryPutDown(int topPos, int botPos);
  // set all active cells on board to empty and inactive
  void clearActive(int topPos, int botPos);
  // check if any line is full
  bool checkForFullLine(int topPos, int botPos);
  // this makes line from topPos to botPos to notifyObservers
  void notifyDisplay(int topPos, int botPos);
  // this adds score if a row is cleared
  void rowClearedAddScore(int);
  // this adds score if some blocks is cleared
  void blockClearedAddScore();
  // functions supporting hint
  int getLowestPos();
  int getLowestPosOnDir(char dir, int &leftEnd);
  bool putHintDown(int moveRightTimes, int rotateTimes, int moveDownTimes);
public:
  Board();
  void init(bool textOnlyMode);
  // update current block
  bool sendCurrentBlock(std::shared_ptr<Block> block, bool switchBlock);
  // update next block
  void sendNextBlock(std::shared_ptr<Block> block);
  // display hint on the board for current block
  void hint(const Block &b);
  // moves current block for given times
  void move(char dir, int times);
  // rotates current block for given times
  void rotate(char dir, int times);
  // drops current block
  bool drop(bool &rowCleared);
  // drops a star block on the board
  void dropStarBlock(bool &rowCleared);
  // change level
  void levelChange(int level);
  // display hint
  void hint();
  // clear hint
  void clearHint();
  // hold current block, sub in next block;
  bool hold(std::shared_ptr<Level> level);
  // let graphic display lost
  void sendLostToGraphic();
  // prints textDisplay
  friend std::ostream &operator<<(std::ostream &out, const Board &board);
};

#endif
