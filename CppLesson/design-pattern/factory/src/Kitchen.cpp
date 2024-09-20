#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Kitchen.hpp"
#include "Beef.hpp"
#include "Chicken.hpp"
#include "Veggie.hpp"
#include <iostream>
#include <string>

Kitchen::Kitchen() {
  // Nothing todo...
}

Kitchen::~Kitchen() {
  // Nothing todo...
}

std::unique_ptr<IBurger> Kitchen::prepare(const int& menuItem) {

  std::unique_ptr<IBurger> burger{nullptr};

  switch (menuItem) {
  case BEEF:
    burger = std::make_unique<Beef>();
    burger->delivery();
    break;
  case VEGGIE:
    burger = std::make_unique<Veggie>();
    burger->delivery();
    break;
  case CHICKEN:
    burger = std::make_unique<Chicken>();
    burger->delivery();
    break;
  default:
    break;
  }

  return burger;
}

#endif