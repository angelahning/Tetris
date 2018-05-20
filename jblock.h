#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"

//forward declration of friend class
class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

class JBlock: public Block {
  const char type = 'J';
public:
  JBlock(int level); //JBlock constructor
  void rotate(char dir) override; //JBlock rotate
  void move(char dir) override; //JBlock move
private:
  //declration of friend class
  friend Level;
  friend LevelZero;
  friend LevelOne;
  friend LevelTwo;
  friend LevelThree;
  friend LevelFour;
};


#endif
