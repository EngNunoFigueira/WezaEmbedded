#include<iostream>
#include<stdio.h>
#include<array>
#include<algorithm>
#include<string>

using namespace std;



std::string searchSubString(const std::string &text)
{
	std::cout<<"function starting search the subtring position..."<<std::endl;

	int low{0};
	int aux_low{0};
	int high{text.length()/2-1};
	bool notDuplicatedFound{true};

	while(low <= high)
	{
	  aux_low{low};
      for(int i{low}; i < high; i++)
      {
         if(text[low] == text[i+1]) 
         {
         	//low++;
         	//firstSubSTR lenght = low - i -> 
         	notDuplicatedFound=false;
         }
      }

      if((low == high) && (notDuplicatedFound) && (high >= (text.length/2)-1))
      {
            // Found substring... from low to high check if text.lenght = (high+low) = scileLenght finish and return the subStr
      	return "Found";

      }
      /*
      if((low == high) && (notDuplicatedFound) && (NewSubSTR > firstSubSTR))
      {
            // Found substring... from low to high check if text.lenght = (high+low) = scileLenght finish and return the subStr
      	   //  string for duplicate is: low - i
      	   //  updated...

      }
      if((low == high) && (!notDuplicatedFound) && bigNumber)
      {
         // Lets working on the other side of the string ...
      	// bigNumber is true when all elements are checked
      	low=high;
      	high=text.lenght-1;
      }*/

      low++;
	}

	return "not found";
}

int main(int argc, ** agrv)
{
    std::cout<<"Process running..."<<std::endl;
	return 0;
}

/*

[a b c d e f j h]
1 - ab, ac, ad, ae, -- af, aj, ah
2 -     bc, bd, be, -- bf, bj, bh
3           cd, ce, -- cf, cj, ch


negativo:

[a b a d  f b z d]
*/
ab, aa, ad, af -- ab, az, ad
    ba, bd, bf -- bb, bz, bd
        ad, af --
            df --
