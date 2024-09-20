#ifndef MENU_HPP
#define MENU_HPP

#include "Menu.hpp"
#include <iostream>
#include <string>

Menu::Menu() {}
Menu::~Menu() {}
Menu::Menu(std::pair<std::string, int> _requested) : selectedItem{_requested} {
  // nothing todo.
}

std::pair<std::string, int> Menu::getItem() { return selectedItem; }

#endif