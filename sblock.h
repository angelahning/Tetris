#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"

//forward declaration of friend class
class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

class SBlock: public Block {
  const char type = 'S';
public:
  SBlock(int level); //SBlock constructor
  void rotate(char dir) override; //SBlock rotate
  void move(char dir) override; //SBlock move
private:
  //declaration of friend class
  friend Level;
  friend LevelZero;
  friend LevelOne;
  friend LevelTwo;
  friend LevelThree;
  friend LevelFour;
};


#endif
