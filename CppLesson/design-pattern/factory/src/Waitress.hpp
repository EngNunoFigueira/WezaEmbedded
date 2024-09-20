#include "Menu.hpp"
#include <iostream>
#include <string>

class Waitress {

public:
  Waitress();
  ~Waitress();
  int notes(const std::string& burger);

private:
  int menu;
};