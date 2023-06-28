#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <memory>
#include <functional>
#include <initializer_list>
#include "Foo.h"
#include "BankService.hpp"

using namespace std;

std::string Mamarela(const std::string & name, const std::string & email, const std::string & phone, const std::string & country)
{
  std::cout<<"This is the user personal contacts"<<std::endl;
  std::cout<<"Name: Mr. "<<name<<std::endl;
  std::cout<<"e-mail: "<<email<<std::endl;
  std::cout<<"Mobile phone: "<<phone<<std::endl;
  std::cout<<"Country "<<country<<std::endl;

  return "Mamarela info";
}

void reference(int & value)
{
  std::cout<<"The values read is "<<value<<endl;
}

class Magic
{
  public:
    Magic() {
      std::cout<<"This class use a std::iniliatizer to fill a vector"<<std::endl;
    }
    Magic(std::initializer_list<int> nmbers) {
      for(int values : nmbers)
      {
        numbers.push_back(values);
      }
    }
  void PrintValues()
  {
    std::cout<<"These are the values inserted"<<std::endl;
    std::cout<<"[";
    for(int opValues : numbers)
    {
       std::cout<<opValues<<" ";
    }
   std::cout<<"]"<<std::endl;
  }
  private:
    std::vector<int> numbers{};
};


int main(int argc, char ** argv)
{

 /*Code to test std::move*/
 std::string girl{"hola"};
 std::string sister{};
 sister=std::move(girl);
 std::cout<<"This is the name of my syster "<<sister<<std::endl;
 std::cout<<"The girl now is : "<<girl<<std::endl;
 //end

 /*manual Test the std::initializer_list*/
 Magic _magicBox = {1,2,3,3,4,54,660};
 _magicBox.PrintValues();
 //end

 /* utility header to use std::function*/
 auto f_lambda = [](int jobDays){ return jobDays+1; };
 std::cout<<"You work "<<f_lambda(5)<<" days"<<std::endl;
 std::function<int(int)> funcPtr1 = f_lambda;

 std::string name    = {"Nuno Figueira"};
 std::string email   = {"nuno.figueira@nundelTech.com"};
 std::string phone   = {"+41 54 65 464"};
 std::string country = {"Switzerland"};
 std::function<std::string(const std::string&, const std::string&, const std::string&, const std::string&)>functPtr2 = Mamarela;
 //functPtr2(name, email, phone, country);
 auto mamarela = std::bind(functPtr2, name, email, phone, std::placeholders::_1);
 std::cout<<"This is the return type "<<mamarela(country)<<std::endl;
 //end

 /*Study references */
 std::function<void(int &)> referenceFunc = reference;
 int marta{8340};
 referenceFunc(marta);
 //end

 /*Study example smart_ptr*/
 auto ptr = std::make_unique<Magic>(_magicBox);
 std::cout<<"I am the Unique pointer saving the value: "<<std::endl;
 ptr->PrintValues();
 //end

 BankService _myBank;
 Foo _foo(_myBank);
 std::cout<< "Starting Using Google Gest Mock" <<std::endl;
 //_foo.PrintMessage("Hello Nuno Figueira");
 //bool valid = _foo.UserLogin("ekumbi", "salas519");
  return 0;
}
