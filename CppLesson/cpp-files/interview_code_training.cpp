/*
Year: 2021
Autor: Nuno Figueira
Project: Training C++ code from job interviews.
Objective: 
The objective of this small c++14 program, is pratices with code  that can be asked in job interviews.
*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory>
#include<array>


// THIS SOLUTION APPLY BRUTE FORCE O(n^2)
int foundTarget(int *left, int *right, int lenght, int target)
{
	int refTarget=0, max=0;
    for(int i=0; i< lenght; i++)
    {
    	for (int j = 0; j < lenght; ++j)
    	{
    		refTarget=left[j]+right[i];
    		std::cout<<"The refTarget value is "<< refTarget<<std::endl;
    		if( (refTarget >= target) && (refTarget > max) )
    		{
    		  max=refTarget;
    		  std::cout<<"The max by now is "<< max<<std::endl;
    		}
    	}
    }

    return max;	
}


int foundTarget(int lenght, int target)
{

    int max=0;
	int index=0;
	int refTarget=0;
    int left[] ={13,0,25};
    int right[]={1,13,1 };
    do 
    {
      std::cout<<"THE INDEX  IS "<< index<<std::endl;
      std::cout<<"THE LENGHT IS "<< lenght<<std::endl;
	  refTarget = left[index]+right[lenght];
	  std::cout<<"THE refTarget IS "<< refTarget<<std::endl;

      if( refTarget > max )
    	max=refTarget;
        std::cout<<"Previous MAX is "<< max<<std::endl;
	  if( (max > target))
	  {
	  	 std::cout<<"ENTROU NUNO MIGUEL.... "<<std::endl;
	  	 return max;
	  }
	  index++;
    }while(index < 3);

     lenght++;
     foundTarget(lenght, 30);
}



using namespace std;

int main (int argc, char *argv[])
{
  auto Words={"Bula", "Hilario", "\n"};
  std::cout<<"This program is a couple of code used in C++ interview code skills"<<std::endl;
  
  std::array<int,3> oneDimention{1,3,5};
  int multiDimention[3][3]={{1,2,3},{5,7,9},{11,13,15}};

  for(int &position: oneDimention)
  {
    std::cout<<"The value is :"<< position<<std::endl;   
  }

  std::cout<<"The matrix value for [0][0] is :"<< multiDimention[0][0]<<std::endl; 
  std::cout<<"The matrix value for [0][1] is :"<< multiDimention[0][1]<<std::endl; 
  std::cout<<"The matrix value for [0][2] is :"<< multiDimention[0][2]<<std::endl; 
  std::cout<<"The matrix value for [1][0] is :"<< multiDimention[1][0]<<std::endl; 
  std::cout<<"The matrix value for [1][1] is :"<< multiDimention[1][1]<<std::endl; 
  std::cout<<"The matrix value for [1][2] is :"<< multiDimention[1][2]<<std::endl; 
  std::cout<<"The matrix value for [2][0] is :"<< multiDimention[2][0]<<std::endl; 
  std::cout<<"The matrix value for [2][1] is :"<< multiDimention[2][1]<<std::endl; 
  std::cout<<"The matrix value for [2][2] is :"<< multiDimention[2][2]<<std::endl; 

  // Algoithm used to fill a multi-dimension array...
 /* for(int i=0; i<3;i++)
  {
  	for(int j=0;j<3;j++)
  	{
       multiDimention[i][j]=i*j-i^2;
  	}
  }*/


   // Calculate the maximumnumber of a array of 2D or 3D
  /* int max=0;

   for(int i=0; i<3;i++)
   {
   	 for (int j = 0; j < 3; j++)
   	 {
   	    if( max<=multiDimention[i][j] )
   	 	   max=multiDimention[i][j];
   	 }
   }

  std::cout<<"The max value of the 3D Array is :"<< max<<std::endl; 

  */

  // This test interview consider a function that receive two array and 
  // we need found the some of two points that is close or big than the Target.
  // Both arrays had the some length.


  int leftElements[] = {13,3,25};
  int rightElements[]= {1,13,1};

  int targer =foundTarget(leftElements, rightElements, 3, 21);
  std::cout<<"The target found is: "<< targer<<std::endl;


  std::cout<<"TESTING NOW ...."<<std::endl;
  int targetComputeByRecursiveMetho=foundTarget(0, 30);
  std::cout<<"The target computed by Recursive Method is: "<< targetComputeByRecursiveMetho<<std::endl;

  throw 32;

  return 0;
}



