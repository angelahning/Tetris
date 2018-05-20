#include <iostream>
#include "subject.h"
#include "line.h"

using namespace std;

//public notifyObservers
void Subject::notifyObservers(){
  for (auto &ob: this->observers){
    ob->doNotify(*this);
  }
}

//attach observers into observers observer collection
void Subject::attach(shared_ptr<Observer> ob){
  this->observers.emplace_back(ob);
}
