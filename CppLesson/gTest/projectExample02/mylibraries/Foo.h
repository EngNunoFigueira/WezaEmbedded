#ifndef FOO_H
#define FOO_H

#include"Foo.h"
#include <iostream>
#include <memory>
#include <string_view>
#include "BankService.hpp"

using namespace std;

class Foo
{
 public:
   Foo();
   Foo(BankService & bank);
  virtual ~Foo();
  void PrintMessage(const std::string_view & message);
  bool BankLogOut();
  bool BankLogin();
  bool ShowScore();
  void SetCounterValue(int value);
  void WriteInform();
  void ShowInform();
  int GetMax();
 private:
  int max{100};
  std::string inform{};
  BankService *myBank; 
};;
#endif
