#ifndef WAITRESS_HPP
#define WAITRESS_HPP

#include "Waitress.hpp"
#include <iostream>
#include <string>

Waitress::Waitress() {}
Waitress::~Waitress() {}
int Waitress::notes(const std::string& burger) {
  int itenRequest{0};
  char menuCode{burger[0]};

  switch (menuCode) {
  case 'b':
    return 1;
    break;
  case 'v':
    return 2;
    break;
  case 'c':
    return 3;
    break;
  default:
    return 4;
    break;
  }
}
#endif // end file