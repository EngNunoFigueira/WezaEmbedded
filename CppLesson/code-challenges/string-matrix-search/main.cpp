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


void searchLetter(const char *arrayA, const char *arrayB, const char *arrayC, const char *arrayD, const char *arrayE)
{
    const char letter{'D'};
    std::array<int,5> found{0};
    for(int i=0; i < 6; i++)
    {
        if( arrayA[i] == letter)
        {
           found[0]+=1;
        }
        if( arrayB[i] == letter)
        {
           found[1]+=1;
        }
         if( arrayC[i] == letter)
        {
           found[2]+=1;
        }
         if( arrayD[i] == letter)
        {
           found[3]+=1;
        }
        if( arrayE[i] == letter)
        {
           found[4]+=1;
        }
    }

    
    std::cout<<"Letter "<< letter<<" found "<<found[0]<<" in array A"<<std::endl;
    std::cout<<"Letter "<< letter<<" found "<<found[1]<<" in array B"<<std::endl;
    std::cout<<"Letter "<< letter<<" found "<<found[2]<<" in array C"<<std::endl;
    std::cout<<"Letter "<< letter<<" found "<<found[3]<<" in array D"<<std::endl;
    std::cout<<"Letter "<< letter<<" found "<<found[4]<<" in array E"<<std::endl;
}

int main()
{
  std::cout<<"Swap the character of a string"<<std::endl;
  std::cout<<"The end strind after swapped is: "<< doubleCharcSwap("aabbccc",'a', 'b')<<std::endl; 
  std::cout<<"The end strind after swapped is: "<< doubleCharcSwap("random w#rds writt&n h&r&", '#', '&')<<std::endl;
  std::cout<<"The end strind after swapped is: "<< doubleCharcSwap("128 895 556 788 999", '8', '9')<<std::endl;

  const char A[6] = {'D', 'E', 'Y', 'H', 'A', 'D'};
  const char B[6] = {'C', 'B', 'Z', 'Y', 'J', 'K'};
  const char C[6] = {'D', 'B', 'C', 'A', 'M', 'N'};
  const char D[6] = {'F', 'G', 'G', 'R', 'S', 'R'};
  const char E[6] = {'V',  'X', 'H', 'A', 'S', 'S'};
  searchLetter(A, B, C, D, E);
 return 0; 
}
