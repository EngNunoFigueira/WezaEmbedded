#ifndef DBCONTEXT_H
#define DBCONTEXT_H

#include"DbContext.h"
//#include"ObserverPattern.h"
#include<iostream>
#include<vector>


using namespace std;

class DbContext //: public ObserverPattern
{
public:
  DbContext();
  DbContext(std::string dbNServerName, int portNumber, std::string password, std::string username, std::string vpn);
  // Function to attach an element to starting observe
  //void attachObserver(ObserverPattern *observerPattern);
  // Function to dettach an element to stpo observe
  //void detachObserver(ObserverPattern *observerPattern);
  void connect();
  bool disconect();
  virtual ~DbContext();
  // Function to notify the observer when the VPN change status occure.
  void notify();
  //std::string getVPN();
  //void setVPN();
private:
  // List of elements that are observing if the vpn change status occure. 
  //std::vector<*ObserverPattern> obsList;
  std::string dbNServerName{};
  int portNumber{0};
  std::string password{};
  std::string username{};
  std::string vpn{};
};
#endif