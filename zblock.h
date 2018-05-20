#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"

//forward declaration of friend class
class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

class ZBlock: public Block {
  const char type = 'Z';
public:
  ZBlock(int level); //ZBlock constructor
  void rotate(char dir) override; //ZBlock rotate
  void move(char dir) override; //ZBlock move
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
