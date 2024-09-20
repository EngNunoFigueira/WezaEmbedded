#include "Restaurant.hpp"
#include <exception>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main(int argc, char **argv) {

  Restaurant bkg {};
  std::string burger = (argc >= 2) ? argv[1] : "Chicken";
  std::cout << "Implementation of Design Pattern Factory" << std::endl;
  std::cout << "Request a "<<burger <<" burger." <<std::endl;
  bkg.service(burger);

  return 0;
}


//clear && sudo clang-format-10 -i *.cpp *.hpp && sudo g++ -g -time main.cpp main.cpp Restaurant.cpp Menu.cpp Waitress.cpp Kitchen.cpp -o manTest -std=c++17

// clear && sudo clang-format-10 -i main.cpp && sudo g++ -g -time main.cpp Menu.cpp Restaurant.cpp Kitchen.cpp IBurger.hpp  Beef.cpp Veggie.cpp  Chicken.cpp -o manTest -std=c++17


