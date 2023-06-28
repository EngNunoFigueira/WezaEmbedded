#ifndef BANKSERVICE_H
#define BANKSERVICE_H

#include <iostream>
#include "BankService.hpp"
using namespace std;

class BankService
{
  public:
    BankService(); 
    virtual ~BankService();
    virtual void   PrintMessage();
    virtual double ShowScore();
    virtual bool   UserLogOut();
    virtual void   GetValue(double _value);
    virtual double SendMoney(double mount);
    virtual bool   UserLogin(std::string user, std::string pwd);
  private:
    double value{0.00};
    std::string user {"ekumbi"};
    bool userLogged {false};
    std::string pwd {"salas519"};
};
#endif
