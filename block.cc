#include "block.h"

using namespace std;

//produce the minimum number among three integers
int Block::min3(int a, int b, int c) {
  int m = min(a, b);
  return ((m > c) ? c : m);
}

//produce the maximum number among three integers
int Block::max3(int a, int b, int c) {
  int m = max(a, b);
  return ((m < c) ? c : m);
}

//Block Constructor
Block::Block(char blockType, int level) {
  type = blockType;
  currentLevel = level;
  switch(type) {
    case 'I':
    {
      auto l = make_shared<Line>();
      l->setContent(0, 3, 'I');
      component.emplace_back(l);
      topPos = 0;
      bottomPos = 0;
      leftEnd = 0;
      rightEnd = 3;
      break;
    }
    case 'J':
    {
      auto l1 = make_shared<Line>();
      l1->setContent(0, 0, 'J');
      component.emplace_back(l1);
      auto l2 = make_shared<Line>();
      l2->setContent(0, 2, 'J');
      component.emplace_back(l2);
      topPos = 0;
      bottomPos = 1;
      leftEnd = 0;
      rightEnd = 2;
      break;
    }
    case 'L':
    {
      auto l1 = make_shared<Line>();
      l1->setContent(2, 2, 'L');
      component.emplace_back(l1);
      auto l2 = make_shared<Line>();
      l2->setContent(0, 2, 'L');
      component.emplace_back(l2);
      topPos = 0;
      bottomPos = 1;
      leftEnd = 0;
      rightEnd = 2;
      break;
    }
    case 'O':
    {
      auto l1 = make_shared<Line>();
      l1->setContent(0, 1, 'O');
      component.emplace_back(l1);
      auto l2 = make_shared<Line>();
      l2->setContent(0, 1, 'O');
      component.emplace_back(l2);
      topPos = 0;
      bottomPos = 1;
      leftEnd = 0;
      rightEnd = 1;
      break;
    }
    case 'Z':
    {
      auto l1 = make_shared<Line>();
      l1->setContent(0, 1, 'Z');
      component.emplace_back(l1);
      auto l2 = make_shared<Line>();
      l2->setContent(1, 2, 'Z');
      component.emplace_back(l2);
      topPos = 0;
      bottomPos = 1;
      leftEnd = 0;
      rightEnd = 2;
      break;
    }
    case 'S':
    {
      auto l1 = make_shared<Line>();
      l1->setContent(1, 2, 'S');
      component.emplace_back(l1);
      auto l2 = make_shared<Line>();
      l2->setContent(0, 1, 'S');
      component.emplace_back(l2);
      topPos = 0;
      bottomPos = 1;
      leftEnd = 0;
      rightEnd = 2;
      break;
    }
    case 'T':
    {
      auto l1 = make_shared<Line>();
      l1->setContent(0, 2, 'T');
      component.emplace_back(l1);
      auto l2 = make_shared<Line>();
      l2->setContent(1, 1, 'T');
      component.emplace_back(l2);
      topPos = 0;
      bottomPos = 1;
      leftEnd = 0;
      rightEnd = 2;
      break;
    }
    case '*':
    {
      auto l = make_shared<Line>();
      l->setContent(5, 5, '*');
      component.emplace_back(l);
      topPos = 0;
      bottomPos = 0;
      leftEnd = 5;
      rightEnd = 5;
      break;
    }
  }
}

//as an observer, block will keep track notification
//    from whoFrom to track timesNeedToPop
void Block::notify(Subject& whoFrom){
  if (whoFrom.popState()){
    this->timesNeedToPop -= 1;
  }
}

//based on timesNeedToPop to determine the block
//    is completely cleared or not
bool Block::isCleared(){
  return this->timesNeedToPop == 0;
}

//setter function that set timesNeedToPop based on times
void Block::setTimesNeedToPop(int times){
  this->timesNeedToPop = times;
}

//public rotate block function
void Block::doRotate(char dir) {
  rotate(dir);
}

//public move block function
void Block::doMove(char dir) {
  move(dir);
}

//public vertical move block function
void Block::verticalMove(char dir) {
  if(dir == 'u') {
    if((topPos - 1) < -3) {
      return;
    } else {
      topPos--;
      bottomPos--;
    }
  } else if(dir == 'd') {
    if((bottomPos + 1) > 14) {
      return;
    } else {
      topPos++;
      bottomPos++;
    }
  }
}

//getter function: produce the component of current block
vector<shared_ptr<Line>> Block::getComponent() {
  return component;
}

//getter function: produce the topPos of current block
int Block::getTopPos(){
  return this->topPos;
}

//getter function: produce the bottomPos of current block
int Block::getBotPos(){
  return this->bottomPos;
}

//getter function: produce the level of current block
int Block::getLevel() {
  return currentLevel;
}

//getter function: produce the type of current block
char Block::getType() {
  return type;
}

//getter function: produce the type of current block
int Block::getBottomFill(){
  int size = this->component.size();
  return this->component[size - 1]->getFill();
}

//setter function: set the current block to hint block (change type to '?')
void Block::setHint() {
  int size = this->component.size();
  for(int i = 0; i < size; i++) {
    vector<shared_ptr<Cell>> cells = (component[i])->getContent();
    for(int j = 0; j < 11; j++) {
      if(!(cells[j]->isEmpty())) {
        cells[j]->setType('?');
        cells[j]->setHint();
      }
    }
  }
}

//overload function opreator<< in order to cout a block
ostream& operator<<(ostream& out, Block& b) {
  string s = "";
  int size = (b.component).size();
  for(int i = 0; i < size; i++) {
    vector<shared_ptr<Cell>> cells = ((b.component)[i])->getContent();
    for(int j = (b.leftEnd); j <= (b.rightEnd); j++) {
      s += cells[j]->getType();
    }
    s += "\n";
  }
  out << s;
  return out;
}
