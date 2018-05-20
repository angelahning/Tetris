#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"

//forward declaration of friend class
class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;


class OBlock: public Block {
  const char type = 'O';
public:
  OBlock(int level); //Oblock constructor
  void rotate(char dir) override; //Oblock rotate
  void move(char dir) override; //Oblock move
private:
  //declaration of friend class
  friend Level;
  friend LevelOne;
  friend LevelTwo;
  friend LevelThree;
  friend LevelFour;
};


#endif
