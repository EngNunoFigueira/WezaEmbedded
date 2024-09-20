#include "IBurger.hpp"
#include <iostream>
#include <string>

using namespace std;

class Veggie : public IBurger {

public:
  Veggie();
  ~Veggie();
  void delivery() override;
};