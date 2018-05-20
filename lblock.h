#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"

//forward declaration of friend class
class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

class LBlock: public Block {
  const char type = 'L';
public:
  LBlock(int level); //LBlock consturctor
  void rotate(char dir) override; //LBlock rotate
  void move(char dir) override; //LBlock move
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
