#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <thread>
#include <future>
#include <utility>
#include <memory>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <initializer_list>
#include <cstddef>
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <fstream>
#include <cstring>

std::string doubleCharcSwap(std::string strSwap, char c1, char c2)
{
  for(int index =0 ; index < strSwap.length(); index ++)
  {
    if( strSwap[index] == c1)
    {
       strSwap[index] = c2;
    }
    else if( strSwap[index] == c2)
    {
       strSwap[index] = c1;
    }
  }

  return strSwap;
}

/* This function the solution is not emplemented using modern C++ features.
std::string doubleCharcSwap(std::string strSwap, char c1, char c2)
{
  int len = strSwap.length();
  char *charsArray = new char(len);
  memcpy(charsArray, strSwap.c_str(), len+1);
  for(int index =0 ; index < strSwap.length(); index ++)
  {
    if( charsArray[index] == c1)
    {
       charsArray[index] = c2;
    }
    else if( charsArray[index] == c2)
    {
       charsArray[index] = c1;
    }
  }

  std::string swapped(charsArray);
  delete charsArray;
  return strSwap;
}
*/


int main()
{
  std::cout<<"Swap the character of a string"<<std::endl;
  std::cout<<"The end strind after swapped is: "<< doubleCharcSwap("aabbccc",'a', 'b')<<std::endl; 
  std::cout<<"The end strind after swapped is: "<< doubleCharcSwap("random w#rds writt&n h&r&", '#', '&')<<std::endl;
  std::cout<<"The end strind after swapped is: "<< doubleCharcSwap("128 895 556 788 999", '8', '9')<<std::endl;

 return 0; 
}
