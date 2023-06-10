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

void perfectSquarePatch( int number )
{
  int repetCounter {std::move(number)};
  for(int i{0}; i<number; i++)
  {
    std::cout<<"[ ";
    for(int i{0}; i<number; i++)
     {
       std::cout<<number<<" ";
     }
    if(i==number-1)
      std::cout<<" ]"<<std::endl;
    else
      std::cout<<" ],"<<std::endl;
  }
  std::cout<<std::endl;
}

int main()
{
  std::cout<<"Create a function that takes an integer and outputs an n x n square solely consisting of the integer n."<<std::endl;
  perfectSquarePatch(3);
  perfectSquarePatch(5);
  perfectSquarePatch(1);
  
 return 0; 
}
