#include "Kitchen.hpp"
#include "Waitress.hpp"
#include <iostream>
#include <string>

class Restaurant : public Menu, public Waitress, public Kitchen {

private:
  int orderNumber{};
  int tableNumber{};
  bool orderStatus{};
  long orderTimeStamp{};

public:
  Restaurant();
  ~Restaurant();
  void orderDetails();
  void registerOrder();
  bool isOrderDelivered();
  void service(const std::string& burger);
};