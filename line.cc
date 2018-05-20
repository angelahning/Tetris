#include <iostream>
#include "line.h"
#include "cell.h"

using namespace std;

//Line constructor
Line::Line(){
  for(int i = 0; i < 11; ++i){
    auto p = make_shared<Cell>();
    this->content.emplace_back(p);
  }
  this->isPoped = false;
}


Line::Line(int lineNumber): lineNumber{lineNumber} {
  for(int i = 0; i < 11; ++i){
    auto p = make_shared<Cell>();
    this->content.emplace_back(p);
  }
  this->isPoped = false;
}

//line copy constructor
Line::Line(const Line &other){
  for (int i = 0; i < 11; ++i){
    auto p = make_shared<Cell>(*other.content[i]);
    this->content.emplace_back(p);
  }
}

//line move consturctor
Line::Line(Line &&other){
  for (int i = 0; i < 11; ++i){
    auto p = other.content[i];
    this->content.emplace_back(p);
  }
  other.content.clear();
}

//line copy assignment
Line &Line::operator=(const Line &other){
  this->content.clear();
  for (int i = 0; i < 11; ++i){
    auto p = make_shared<Cell>(*other.content[i]);
    this->content.emplace_back(p);
  }
  return *this;
}

//line move assignment
Line &Line::operator=(Line &&other){
  this->content.clear();
  for (int i = 0; i < 11; ++i){
    auto p = other.content[i];
    this->content.emplace_back(p);
  }
  return *this;
}

//getter function return the content of current line
vector<shared_ptr<Cell>> &Line::getContent(){
  return this->content;
}

//try to merge two line together, if success that merge to one line
//    and return true, else return false
bool Line::merge(Line &l){
  vector<shared_ptr<Cell>> otherLineContent = l.getContent();
  for (int i = 0; i < 11; ++i){
    bool selfCellEmpty = this->content[i]->isEmpty();
    bool otherCellEmpty = otherLineContent[i]->isEmpty();
    if (this->content[i]->isHint()){
      selfCellEmpty = true;
    }
    if (selfCellEmpty && !otherCellEmpty){
      if (otherLineContent[i]->isHint()){
        this->content[i]->setHint();
      }
      this->content[i]->setType(otherLineContent[i]->getType());
      this->content[i]->setActive();
    } else if (!selfCellEmpty && !otherCellEmpty){
      return false;
    } else {
      this->content[i]->setInactive();
    }
  }
  return true;
}

//clear active cells and set them to empty
void Line::clearActive(){
  for (int i = 0; i < 11; ++i){
    if (this->content[i]->isActive()){
      this->content[i]->setEmpty();
      this->content[i]->setInactive();
    }
  }
}

void Line::clearHint(){
  for (int i = 0; i < 11; ++i){
    if (this->content[i]->isHint()){
      this->content[i]->setEmpty();
      this->content[i]->setInactive();
    }
  }
}

//make current line inactive
void Line::setAllInactive(){
  for (int i =0; i < 11; ++i){
    this->content[i]->setInactive();
  }
}

//predicate function that check current line is full or not
bool Line::isFull(){
  for (int i = 0; i < 11; ++i){
    if (this->content[i]->isEmpty()){
      return false;
    }
  }
  return true;
}

//setter function to set the range from start to end(inclusive) in current
//    line to type
void Line::setContent(int start, int end, char type){
  for (int i = start; i <= end; ++i){
    this->content[i]->setType(type);
  }
}

//setter function that set linenumber to n
void Line::setLineNumber(int n){
  this->lineNumber = n;
}

//getter function that get current lineNumber
int Line::getLineNumber(){
  return this->lineNumber;
}

//set the whole line to empty line
void Line::clearContent(){
  for(auto it: this->content){
    it->setEmpty();
  }
}

//getter function that get current popState
bool Line::popState(){
  return this->isPoped;
}

//setter function that set PopState to state
void Line::setPopState(bool state){
  this->isPoped = state;
}


int Line::getFill(){
  int fill = 0;
  for(auto cell: this->content){
    if (!cell->isEmpty()){
      ++fill;
    }
  }
  return fill;
}

//overload function opreator<< in order to cout a line
ostream &operator<<(ostream &out, Line &line){
  for (int i = 0; i < 11; ++i){
    out << "Index: " << i << endl;
    out << "Content: " << line.getContent()[i]->getType() << endl;
    out << "Status: " << line.getContent()[i]->isActive() << endl;
  }
  return out;
}
