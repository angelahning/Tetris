#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"

//forward declare friend class
class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

class IBlock: public Block {
  const char type = 'I';
public:
  IBlock(int level); //IBlock Constructor
  void rotate(char dir) override; //IBlock rotate
  void move(char dir) override; //IBlock move
private:
  //declare friend class
  friend Level;
  friend LevelZero;
  friend LevelOne;
  friend LevelTwo;
  friend LevelThree;
  friend LevelFour;
};


#endif
