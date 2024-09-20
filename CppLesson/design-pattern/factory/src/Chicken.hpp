#include "IBurger.hpp"

class Chicken : public IBurger {

public:
  Chicken();
  ~Chicken();
  void delivery() override;
};
