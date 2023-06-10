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

void isEvenOrodd(int *numbers, int size, int n)
{
   int nTimes{std::move(n)};
   std::array<int,3> outputArray;
   std::cout<<"The value of nTimes is: "<< nTimes<<std::endl;
   for(int i=0; i<size; i++)
   {
    if((*numbers)%2 == 0)
     {
        outputArray[i] = (*numbers)-2;
     }
     else
     {
       outputArray[i] = (*numbers)+2;
     }
     numbers++;
   }

   //Print results:
   std::cout<<"[ ";
   for(int nmber : outputArray)
   {
      std::cout<<nmber<<" ";
   }
   std::cout<<"]"<<std::endl;

   //Coninue nTimes
   if( nTimes != 0) {
     nTimes--;
     isEvenOrodd(outputArray.data(), 3,nTimes);
   }
   else
   {
     std::cout<<"End of application"<<std::endl;
   }  
}

int main()
{
  std::cout<<"Find the Even-odd number inside a array"<<std::endl;
  std::array<int,3> sweetIntegers{3,4,9};
  std::cout<<"input array[ ";
  for(int nmber : sweetIntegers)
  {
    std::cout<<nmber<<" ";
  }
  std::cout<<"]"<<std::endl;
  isEvenOrodd(sweetIntegers.data(), 3,3);

 return 0;
}
