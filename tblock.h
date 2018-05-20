#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

//forward declaration of friend class
class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

class TBlock: public Block {
  const char type = 'T';
public:
  TBlock(int level); //StarBlock constructor
  void rotate(char dir) override; //StarBlock rotate
  void move(char dir) override; //StarBlock move
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
