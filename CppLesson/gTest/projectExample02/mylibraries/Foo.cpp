#include <iostream>
#include "Foo.h"
#include <memory>
using namespace std;

Foo::Foo(){}
Foo::Foo(BankService & bank):
myBank(&bank)
{
  //myBank->PrintMessage();
}
Foo::~Foo(){}
void Foo::PrintMessage (const std::string_view & message)
{
  myBank->PrintMessage();
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

int Foo::GetMax()
{
  std::cout<< "This is the max"<<std::endl;
  return max;
}

void Foo::SetCounterValue(int value)
{
  max = value;
}

bool Foo::BankLogin()
{
  std::cout<< "This is the Foo class"<<std::endl;
  return  myBank->UserLogin("ekumbi", "salas519");
}
bool Foo::BankLogOut()
{
  return myBank->UserLogOut();
}

bool Foo::ShowScore()
{
  return myBank->ShowScore();
}



//./isorespinner.sh -i lubuntu-22.04.1-desktop-amd64.iso -b GRUB-32 -l rtl8723bs_4.12.0_amd64.deb -f linuxium-install-UCM-files.sh -f wrapper-linuxium-install-UCM-files.sh -f linuxium-install-broadcom-drivers.sh -f wrapper-linuxium-install-broadcom-drivers.sh -c wrapper-linuxium-install-UCM-files.sh -c wrapper-linuxium-install-broadcom-drivers.sh