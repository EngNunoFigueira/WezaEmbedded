#ifndef FOO_H
#define FOO_H

#include"Foo.h"
#include <iostream>
#include <string_view>

using namespace std;

class Foo
{
 public:
  Foo();
  ~Foo();
  void PrintMessage(const std::string_view & message);
  void WriteInform();
  void ShowInform();
 private:
  std::string inform{};
};
#endif
