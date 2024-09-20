#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "Chicken.hpp"
#include <iostream>
#include <string>

Chicken::Chicken() {
  // Nothing todo
}
Chicken::~Chicken() {
  // Nothing todo
}

void Chicken::delivery() {
  std::cout << "Delivery Chicken Burger" << std::endl;
}

#endif