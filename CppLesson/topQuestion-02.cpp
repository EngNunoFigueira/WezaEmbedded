/*
Year: 2022
Autor: Nuno Figueira
Project: Interview Top five problems solving.
Objective: 
The purpose of this small C++14 program, is understand how MEMORY MANAGMENT is coordinated during the program exec. 
The challenge is allocate a memory and delete that memory and before try print the memory values.
ANALYSIS:
The probgram will compile without errors and a warnings and after detele the allocated memory the print will be zero.
*/


#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{   
	 std::cout<<"This is a Top Five Cpp Interview Question"<<std::endl;
	 int *nmber = new int (100);
	 std::cout<<"The value received is "<< *nmber<<std::endl;
	 std::cout<<"Now we delete the memory allocated delete(nmber) "<<std::endl;
	 delete nmber;
	 std::cout<<"Try print again the nmber "<< *nmber<<std::endl;

	return 0;
}