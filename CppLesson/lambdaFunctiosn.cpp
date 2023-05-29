/*
Year: 2021
Autor: Nuno Figueira
Project: Explain how is the lambda expresion and where we need them on ssoftware solution.
Objective: 
The objective of this small c++14 program, is pratices with code  that can be written using Lambada Expression.
Such as the stadndards functions like for example the function std::for_each_(var.begin(), var.end(), function_need ).
*/


#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
#include<string>
using namespace std;


int main()
{
  std::cout<<"Training with lambada functions" <<std::endl;
  std::vector<std::string> peopleNames {"Marley", "Alzira", "Alexandre"};
  auto age=[](int Bornyear,int currentYear){ return currentYear-Bornyear;};
  std::cout<<"I am :"<<age(1912, 2021)<<std::endl;

   // The std::count_if algorithm is standard function that will return a true or false if the that we search is found inside the vector passed as parameter.
  //  The lambada function we provide, check if the var is greater than 2 and less than six ...
  std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  const auto val = std::count_if(v.begin(), v.end(), [](int var) { return var > 2 && var <= 6;});

  // The std::count_if algorithm is standard function that will return a true or false if the that we search is found inside the vector passed as parameter.
  // The lambad function we provide just check if the name is in vector and when the name is found the iteration finish.
  auto checkName = std::count_if(peopleNames.begin(),peopleNames.end(), [](std::string numElements){ return numElements == "Bram"; });
  std::string NUNO=checkName?"Elements OK":"Not OK";
  std::cout<<NUNO<<std::endl;

  return 0;
}
