#include <iostream>
#include "Foo.h"
using namespace std;


Foo::Foo(){}
Foo::~Foo(){}
void Foo::PrintMessage (const std::string_view & message)
{
  std::cout<<"User message : "<< message<<std::endl;
}

void Foo::WriteInform()
{
  std::cout<<"Please inform yor report"<<std::endl;
  std::cin >> inform;
}

void Foo::ShowInform()
{
  std::cout<< "This is the report we received: "<<std::endl;
  std::cout<< inform<<std::endl;
}
