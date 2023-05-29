/*
Year: 2022
Autor: Nuno Figueira
Project: Overload of functions in Cpp.
Objective: 
The objective of this small c++14 program, is pratices with code  overload functions and now the difference between NULL, 0 and nullprt in C++1y
*/


#include <iostream>
#include<stdio.h>

using namespace std;

 void FuncData(int number) {
	 std::cout<<"The value received is "<< number<<std::endl;
 }

  void FuncData(char *name) {
 	if(name==nullptr)
      std::cout<<"Received a nullptr"<<std::endl;
    else
      std::cout<<"The name is "<< *name<<std::endl;
 }


int main()
{   
	 std::cout<<"This is a Top Five Cpp Interview Question"<<std::endl;
	 FuncData(32);
	 //FuncData(NULL);
	 FuncData(nullptr);

	return 0;
}