/*
Year: 2022
Autor: Nuno Figueira
Project: Tesntig exame code question.
Objective: 
The objective of this small c++14 program, is pratices with code exam question about C++1y
*/


#include <iostream>
#include<stdio.h>
#include<array>
#include <cstring>

//using namespace std;

enum Color { red=1, green=2, blue=3 };

int main(int argc, char **argv)
{   
	 Color myColor = red;
	 std::cout<<"This is a Top Five Cpp Interview Question"<<std::endl;
     int *ptr= nullptr, number=100;
	 int list[5]={3,4,6,7,1};
     std::array<int,5>myList{4,6,8,9,10};

     ptr = &number;
     std::cout<<"Considering the operation -> ptr= &number. What is the value pointed by the pointer is: "<< *ptr<<std::endl;
     ptr=list;
     std::cout<<"Considering the operation -> ptr= list. What is the value pointed by the ptr+1 is: "<< (*ptr)+1<<std::endl;
     
       char toma[5];
       memcpy(toma, argv[1],1);
       std::cout<<"The color is red  "<<*toma<<std::endl;


       int getInt       = static_cast<int>(7.9);
       int getSecondInt = static_cast<int>(2.3);
       float getFloat   = static_cast<float>(9,9);
       double getDouble = static_cast<double>(41/8);

       std::cout<<"Int converted "<<getInt<<std::endl;
       std::cout<<"Second Int converted "<<getSecondInt <<std::endl;
       std::cout<<"Float converted "<<getFloat<<std::endl;
       std::cout<<"Double converted "<<getDouble<<std::endl;

	return 0;
}