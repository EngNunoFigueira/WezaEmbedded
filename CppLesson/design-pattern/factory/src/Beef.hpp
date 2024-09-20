#include "IBurger.hpp"
#include <iostream>
#include <string>

using namespace std;

class Beef : public IBurger {

public:
  Beef();
  ~Beef();
  void delivery() override;
};