#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>
#include <iostream>
#include <string>
#include "line.h"
#include "cell.h"

//forward declare friend class
class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

class Block: public Observer {
  //private field for block as an Observer
  int timesNeedToPop = 0;
  int currentLevel;
  void notify(Subject& s) override;
protected:
  //protected field for block set for different type of block
  char type; //track the type
  int topPos, bottomPos; //track the y axis pos
  int leftEnd, rightEnd; //track the x axis pos
  std::vector<std::shared_ptr<Line>> component;
  Block(char blockType, int level); //consturctor
  int min3(int a, int b, int c); //protected helper function
  int max3(int a, int b, int c); //protected helper function
public:
  //public function for other file to use
  void doRotate(char dir); //public rotate function
  void doMove(char dir); //public move function
  void verticalMove(char dir); //public vertical move function
  int getTopPos(); //public getter function to get topPos
  int getBotPos(); //public getter function to get bottomPos
  int getLevel(); //public getter function to get level
  char getType(); //public getter function to get type
  int getBottomFill(); //public getter function to get if BottomFill
  std::vector<std::shared_ptr<Line>> getComponent(); //public getter function to get component
  void setTimesNeedToPop(int times); //public setter function to set TimesNeedToPop
  void setHint(); //public setter function to set current block to hint block('?')
  bool isCleared(); //predicate function to check block is cleared or not
private:
  virtual void rotate(char dir) = 0; //private virtue rotate function
  virtual void move(char dir) = 0; //private virtue move function
  //declare friend class
  friend Level;
  friend LevelZero;
  friend LevelOne;
  friend LevelTwo;
  friend LevelThree;
  friend LevelFour;
  //declare friend function
  friend std::ostream& operator<<(std::ostream& out, Block& b);
};

#endif
