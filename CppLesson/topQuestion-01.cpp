/*
Year: 2022
Autor: Nuno Figueira
Project: Interview Top five problems solving.
Objective: 
The purpose of this small C++14 program, is understand how MEMORY MANAGMENT is coordinated during the program exec. 
The challenge is create a function that return a pointer or the address of a local variable declared inside the Function().
ANALYSIS:
The probgram will compile with a warning because the address of the function will be out of scope after the function terminate.
Its mean that we must avoid this situation. Declaring variable that we want return the address inside the function as static....
*/


#include <iostream>
#include<stdio.h>

using namespace std;

int *getPrt()
{
	static int i= 0;
	i =1;
	return &i;
}

int main()
{   
	std::cout<<"This is a Top Five Cpp Interview Question"<<std::endl;
	 int *nmber= getPrt();
	 std::cout<<"The value received is "<< *nmber<<std::endl;
	return 0;
}