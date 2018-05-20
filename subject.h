#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>
#include "observer.h"
#include "cell.h"

class Subject {
  std::vector<std::shared_ptr<Observer>> observers;
public:
  void notifyObservers(); //public notifyObservers
  void attach(std::shared_ptr<Observer> ob); //attach observers into observers observer collection
  virtual int getLineNumber() = 0; //pure virtual getter function to concrete subject class line
  virtual std::vector<std::shared_ptr<Cell>> &getContent() = 0; //pure virtual getter function to concrete subject class line
  virtual bool popState() = 0; //pure virtual getter function to concrete subject class line
};

#endif
