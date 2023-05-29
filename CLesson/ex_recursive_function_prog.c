/*
Year: 2021
Autor: Nuno Figueira
Project: Recursive Function 
Objective: 
The objective this function is undersrtand the recursive function.
With a recursive function we can implement a repetite iterations.
*/


#include<stdio.h>
#include<stdlib.h>


int Counter(int value, int max)
{
    value++;
    if(value < max)
    {
        value = value + Counter(value,max);
    }
    else
    {
       printf("\nThe result of our recursive function is: %d\n", value);
    }
   return value;
}

int main(int argc, char *argv[])
{

int maxCounter = 230;
Counter(0, maxCounter);
return 0;


}
