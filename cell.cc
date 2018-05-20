#include <iostream>
#include "cell.h"

using namespace std;

//cell constructor
Cell::Cell(){
  this->type = ' ';
  this->active = false;
  this->hint = false;
}

//cell copy constructor
Cell::Cell(const Cell &other){
  this->type = other.type;
}

//cell move consturctor
Cell::Cell(Cell &&other){
  this->type = other.type;
}

//cell copy assignment
Cell &Cell::operator=(const Cell &other){
  this->type = other.type;
  return *this;
}

//cell move assignment
Cell &Cell::operator=(Cell &&other){
  this->type = other.type;
  return *this;
}

//setter function that set current cell to type
void Cell::setType(char type){
  this->type = type;
}

//clear(empty) the current cell
void Cell::setEmpty(){
  this->type = ' ';
  this->hint = false;
}

//getter function that get current cell type
char Cell::getType(){
  return this->type;
}

//predicate function that check if the current cell is empty or not
bool Cell::isEmpty(){
  if (this->type == ' '){
    return true;
  } else {
    return false;
  }
}

//setter function that set current cell to hint type
void Cell::setHint(){
  this->hint = true;
}

//predicate function that check if cell is hint cell
bool Cell::isHint(){
  return this->hint;
}

//set current cell active
void Cell::setActive(){
  this->active = true;
}

//predicate function that check if the current cell is active or not
bool Cell::isActive(){
  return this->active;
}

//set current cell inactive
void Cell::setInactive(){
  this->active = false;
}
