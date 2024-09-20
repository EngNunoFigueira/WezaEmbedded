#include "IBurger.hpp"
#include "Menu.hpp"
#include <iostream>
#include <memory>
#include <string>

class Kitchen {
public:
  Kitchen();
  ~Kitchen();
  std::unique_ptr<IBurger> prepare(const int& menuItem);

private:
  enum productId { BEEF = 1, VEGGIE = 2, CHICKEN = 3 };
};