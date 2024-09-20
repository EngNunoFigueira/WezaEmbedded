#include<iostream>
#include<stdio.h>
#include<array>
#include<algorithm>

using namespace std;


int searchNumber(int arrayLavues[], int numberToFound)
{

  int low{0};
  int high{4};

  while(low <= high)
  {
     int middle = low + (high - low)/2;

     std::cout<<"Low "<<low <<std::endl;
     std::cout<<"High "<<high<<std::endl;
     std::cout<<"Middle "<<middle<<std::endl;
     std::cout<<"numberToFound "<<numberToFound<<std::endl;
     std::cout<<"Middle value is "<<arrayLavues[middle]<<std::endl;


     if( numberToFound == arrayLavues[middle] )
     {
     	std::cout<<"WIN Correct value"<<std::endl; 
        return arrayLavues[middle];
     }

     if( numberToFound > arrayLavues[middle] )
     {
     	low = middle + 1;
     }
      if( numberToFound < arrayLavues[middle] )
     {
     	high = middle - 1;
     }

  }

       return -1;

}

int main(int argc, char **agrv)
{

    std::cout<<"This is a binary search algorithm implememtation "<<std::endl;
    int numbers[7]={2,4,67,21,13,51,9};
    int numbersT[5]={12,5,0,9,20};

    std::sort(std::begin(numbersT), std::end(numbersT));

/*
    size_t arrayLen = sizeof(numbers)/sizeof(numbers[0]);
    std::cout<<"The array sie is "<< arrayLen<<std::endl;

    //std::sort(std::begin(numbers), std::end(numbers));

    std::cout<<"The array aftert sort operation"<<std::endl;
    std::cout<<"[ ";
    for(int value : numbers)
    {
      std::cout<<value <<" ";
    }
    std::cout<<" ]"<<std::endl;

*/
    searchNumber(numbersT , 5) == -1 ? std::cout<<"Not found" : std::cout<<"Correct value"; 

	return 0;
}