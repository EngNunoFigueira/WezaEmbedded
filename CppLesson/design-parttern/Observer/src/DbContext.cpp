#include<iostream>
#include"DbContext.h"

using namespace std;

DbContext::DbContext(){}
DbContext::DbContext(std::string _dbNServerName, int _portNumber, std::string _password, std::string _username, std::string _vpn)
:dbNServerName(_dbNServerName)
,portNumber(_portNumber)
,password(_password)
,username(_username)
,vpn(_vpn){} /*
void DbContext::attachObserver(ObserverPattern *observerPattern)
{
	// Add observer to the list
    obsList.push_back(observerPattern);
}
void DbContext::detachObserver(ObserverPattern *observerPattern)
{
   // Remove observer from the list
}*/
void DbContext::connect()
{ std::cout<< "Database connection establish on vpn with the following list of parameters:"<<std::endl;
  std::cout<< "server name "<< dbNServerName<<std::endl;
  std::cout<< "port number "<< portNumber<<std::endl;
  std::cout<< "user name   "<< username<<std::endl;
  std::cout<< "password ************"<<std::endl;
}
bool DbContext::disconect(){ return true; }
DbContext::~DbContext(){} /*
std::string DbContext::getVPN()
{
    return vpn;
}
void DbContext::setVPN(std::string newVpn)
{
     vpn = newVpn;
}*/
void DbContext::notify()
{
   // Trigger notification
}