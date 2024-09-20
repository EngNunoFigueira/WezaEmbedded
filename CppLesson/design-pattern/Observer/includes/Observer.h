#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include"Observer.h"

class Observer
{
public:
  Observer();
  Observer(int & a);
  void create();
  bool notify();
  bool remove();
  virtual ~Observer();
private:
  int aa{0};

};
#endif  
