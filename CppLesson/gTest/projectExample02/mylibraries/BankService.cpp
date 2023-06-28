#include <iostream>
#include "BankService.hpp"
using namespace std;


BankService::~BankService() {}
BankService::BankService()  {}
void BankService::PrintMessage()
{
  std::cout<<"Welcome to the Central Bank of Wambu"<<std::endl;
}

double BankService::ShowScore()
{ 
  std::cout<<"This is your current account score: "<< value<<std::endl;
  return value == 0.00 ? 100.00 : value;
}

bool BankService::UserLogOut()
{
  if( user == "ekumbi" && pwd == "salas519" && userLogged == true)
    {
      std::cout<<"Bye bye bye"<<std::endl;
      return true;   
    }
  else
     {
       std::cout<<"The user is not logged"<<std::endl;
       return false;
     }
}

double BankService::SendMoney(double mount)
{ 
  std::cout<<"Operation Type Send Money"<<std::endl;
  if( mount < value)
   {
      std::cout<<"Operation cannot be procced because you don't have enough money to complet the operation."<<std::endl;
      return 0.00;
   }
  else
    {
      std::cout<<"Operation sucess complet."<<std::endl;
      return 1.00;
    }
}
bool BankService::UserLogin(std::string user, std::string pwd)
{
  std::cout<<"Welcome to the Central Bank of Wambu"<<std::endl;
  std::cout<<"Checking your Login Credentials....."<<std::endl;
  if(user == "ekumbi" && pwd == "salas519")
   {
     std::cout<<"Welcome to the Central Bank of Wambu"<<std::endl;
     userLogged=true;
     return true;
   }
  else
     std::cout<<"This credentials are not falid"<<std::endl;
     userLogged=false;
     return false;
}

void BankService::GetValue(double _value)
{
   value = _value;
}