#ifndef _OBSERVER_H_
#define _OBSERVER_H_

//forward declaration of superclass
class Subject;

class Observer {
  virtual void notify(Subject &) = 0; //pure virtual notify function
public:
  //public notify function
  void doNotify(Subject &whoNotified){
    this->notify(whoNotified);
  }
  //public default destructor
  virtual ~Observer();
};

#endif
