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



std::array<int,2> sumEvenAndOddArrayValues(int *arr)
{
  int evenSum{0};
  int oddSum{0};
  std::array<int, 2> arrResults{0};
  for(int arrElement{0}; arrElement< 6; arrElement++)
  {
    if(((*arr)%2)==0) {
      evenSum = evenSum + (*arr);
    }
    else {
       oddSum = oddSum + (*arr);
    }
    arr++;
  }
  arrResults[0]=evenSum;
  arrResults[1]=oddSum;

  return arrResults;

}


int main()
{
  std::cout<<"Write a function that takes an array of numbers and returns an array with two elements:"<<std::endl;
  std::cout<<"The first element should be the sum of all even numbers in the array."<<std::endl;
  std::cout<<"The second element should be the sum of all odd numbers in the array."<<std::endl;

  std::array<int, 6> values{1, 2, 3, 4, 5, 6};
  std::array<int, 2> getArrResults{0};
  getArrResults = sumEvenAndOddArrayValues(values.data());

  std::cout<<"The sum of even is: "<< getArrResults[0]<<std::endl;
  std::cout<<"The sum of odd  is: "<< getArrResults[1]<<std::endl;

 return 0; 
}
