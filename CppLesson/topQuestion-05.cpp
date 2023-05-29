/*
Year: 2022
Autor: Nuno Figueira
Project: Tesntig exame code question.
Objective: 
The objective of this small c++14 program, is pratices with code exam question about C++1y
*/


#include <iostream>
#include <stdio.h>
#include <array>
#include <cstring>
#include <ctime>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

std::string getTimeUTC()
{
   char timeUTC[200];
   time_t t;
   struct tm *tmp;
   const char* fmt = "%a, %d %b %y %T %z";

   t = time(NULL);
   tmp = gmtime(&t);
   if (tmp == NULL) {
    perror("gmtime error");
    exit(EXIT_FAILURE);
  }

  if (strftime(timeUTC, sizeof(timeUTC), fmt, tmp) == 0) { 
    fprintf(stderr, "strftime returned 0");
    exit(EXIT_FAILURE); 
  } 
  return (timeUTC);
}       


int main() {

char option{'D'};
unsigned int counter{0};
unsigned int count{7};

std::cout<<"This program will Testig the behavior of break and continue in For, While and Do-While Loops"<<std::endl;

// 1º SCENARIO

// Uncomment this section to understand the break behavior on switch -case 
/*
for( int i=0 ;i<5 ;i++ )
{
  switch(option )
  {
	case 'A':
	case 'B':
	case 'C':
	   counter ++;
	   break;
	case 'D':
	std::cout<<"Case D:"<<std::endl;
	case 'E':
	case 'F':
	default:
 	std::cout<<"default case..."<<std::endl;
  }
}
*/

//1º B
/*
while(true)
{
   std::cout<<"Staring For Ciclo..."<<std::endl;
   for( int i=0 ;i<5 ;i++ )
   {
	 if( i==3 ) {
 	  std::cout<<"Number found the For is Break Out"<<std::endl;
 	  break;
	 }
	std::cout<<"For Running i: "<< i<<std::endl;
  }
}
*/



// 2º SCENARIO

/* Uncomment this code to check the continue behavior on C++
for (int i = 0; i < count; ++i)
{
	if(i==3)
	{
		std::cout<<"The iterator values is: "<<i<<std::endl;
		continue;
	}
	std::cout<<"For Loop i="<<i <<std::endl;
}
std::cout<<"The counter values is: "<<counter<<std::endl;
*/

// 3º SCENARIO

/*
while (counter <=6)
{
	if (counter ==2)
	{
		std::cout << "Counter is equal "<< counter<<std::endl;
		counter++;
		continue;
	}
	else
	{
       std::cout << "continue integration of counter: "<< counter<<std::endl;
	   counter++;
	}
}
*/


// 4º SCENARIO

/*
int aux{1}, stars{0};
while(stars<=4)
{
   //std::cout<<"stars values is "<< stars<<std::endl;
   if( aux > 0)
    {
   	  std::cout<<"*";
   	  //std::cout<<"Continue and aux value is "<< aux<<std::endl;
   	  aux--;
   	  continue;
    }
    std::cout<<"\n";
   stars++;
   aux=stars+1;
   //std::cout<<" aux=stars+aux is equal to "<<aux<<std::endl;
}
*/
/*
 int digit{0};
 std::string getDigit{}; 
 std::cout<<"Insert a number"<<std::endl;
 //std::cin>>digit;
 //std::cout<<"The digit insert was "<<digit <<std::endl;
 std::cin>>getDigit;
 std::cout<<"The digit inserted was "<<getDigit <<std::endl;
 digit=getDigit.length();
 const char *listDigits=getDigit.c_str();

 for(int i=0; i<digit; i++)
 {
 	std::cout<<"digits inserted one by one "<<static_cast<int>((*listDigits)+i) <<std::endl;
 }
*/


 //char ndigits= static_cast<int>(digit);
 //std::cout<<"The equivalent number in char is: "<< ndigits<<std::endl;

// object
//static_cast<std::string>
std::string nuno= getTimeUTC();
std::cout<<"The current time is :"<< nuno<<std::endl;

return 0;
}


