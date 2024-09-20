#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#pragma once

class Menu {

private:
  /**
   * This variable, of type map, represent the menu requested.
   * The waitress sent the info to the kichen to be prepared in 5 minutes.
   * */
  std::pair<std::string, int> selectedItem{};

  /**
   * The Map represent each item in the menu
   * describing the iten code and the price.
   * map["iten code"] = price
   * */
  const std::vector<std::map<std::string, double>> request{
      {{"beef", 17.80}, {"veggie", 15.80}, {"chicken", 12.70}}};

public:
  ~Menu();
  Menu();

  /**
   * The constructor received customer request iten.
   * */
  Menu(std::pair<std::string, int> _requested);

  /**
   * This method return the requested burger.
   * */
  std::pair<std::string, int> getItem();
};