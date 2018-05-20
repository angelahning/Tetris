#ifndef _LINE_H_
#define _LINE_H_
#include <vector>
#include <iostream>
#include <memory>
#include "subject.h"

class Cell;

class Line: public Subject{
  std::vector<std::shared_ptr<Cell>> content;
  int lineNumber;
  bool isPoped;
public:
  Line(); //Line constructor
  Line(int lineNumber);
  Line(const Line &other); //line copy constructor
  Line(Line &&other); //line move consturctor
  Line &operator=(const Line &other); //line copy assignment
  Line &operator=(Line &&other); //line move assignment
  bool merge(Line &l); //try to merge two line together, if success that merge to one line and return true, else return false
  bool isFull(); //predicate function that check current line is full or not
  void setContent(int start, int end, char type); //setter function to set the range from start to end(inclusive) in current line to type
  void setLineNumber(int n);  //setter function that set linenumber to n
  int getLineNumber() override; //getter function that get current lineNumber
  std::vector<std::shared_ptr<Cell>> &getContent() override; //getter function return the content of current line
  bool popState() override; //getter function that get current popState
  void setPopState(bool state); //setter function that set PopState to state
  void clearContent(); //set the whole line to empty line
  void clearActive(); //clear active cells and set them to empty
  void clearHint(); //clear hint cells and set them to empty
  void setAllInactive(); //make current line inactive
  int getFill();
  friend std::ostream &operator<<(std::ostream &out, Line &line); //overload function opreator<< in order to cout a line
};

#endif
