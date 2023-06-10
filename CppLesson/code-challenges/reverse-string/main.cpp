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
#include <iomanip>
#include <list>
#include <sstream> 


std::string reverseStr(std::string original)
{
  int maxChar = static_cast<int>(original.length());
  char strReverse[maxChar];
  for (int i{maxChar}; i >= 0; --i)
  {
    strReverse[maxChar-i]=original[i-1];
  }
 return std::string(strReverse);
}

int main()
{
  std::cout<<"Given a string print the reverse of this string "<<std::endl;
  std::string original {"hello"};
  std::cout<<"The orignal string is : "<<original<<std::endl;
  std::cout<<"The reverse string is : "<<reverseStr(original)<<std::endl;

  return 0; 
}
