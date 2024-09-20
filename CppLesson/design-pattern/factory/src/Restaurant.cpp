#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "Restaurant.hpp"
#include <iostream>
#include <string>

Restaurant::~Restaurant() {}
Restaurant::Restaurant() {}

/**
 * This method receive the customer order and sent to kitchen
 * The the Chef prepare the burger and deliver it to the dinner room.
 * */
void Restaurant::service(const std::string &burger) {
  orderStatus = true;
  prepare(notes(burger));
}

/**
 * This function register the following information i n the database system
 *  orderNumber
 *  tableNumber
 *  orderTimeStamp
 *  requestCode
 * */
void Restaurant::registerOrder() {}

/**
 * This function generate the bill and show these information a below
 *  orderNumber
 *  tableNumber
 *  orderTimeStamp
 *  requestCode
 * */
void Restaurant::orderDetails() {}

/**
 * This method inform if the order is delivered or not
 * Allowing the Chef tracking all order during the service.
 * */
bool Restaurant::isOrderDelivered() { return orderStatus; }

#endif