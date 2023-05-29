/*
Year: 2021
Autor: Nuno Figueira
Project: Calculation of a factorial of a number
Objective: 
The objective this small program is pratices with code  that can be written using recursive function.
At this implementation we use the solution using a for cicle, but against it be could use the recursive...
*/


#include<stdio.h>
#include<stdlib.h>


int myFactorial(int nValue)
{
   int factorial=1;
   int static nfResult=1, aux=0;
   nfResult=nfResult*nValue;
   nValue=nValue-1;
   aux++;

   if(nValue == 0)
   {
      printf("\nThe Factorial of %d  is equal to %d\n", aux, nfResult);
      exit(0);
   }
   if(nValue > 0)
   {
      myFactorial(nValue);
   }
}

int main(int argc, char *argv[])
{
    int nfactorial=0;
    int i=0, result=1;

    if(argc != 0)
    printf("\nThe parameter is %s: \n", argv[1]);

    printf("Please insert the number to calculate their factorial\n");
    scanf("%d",&nfactorial);
    if(nfactorial > 0)
    {
      for (i=1;i<=nfactorial;i++)
      {
        result=result*i;
      }

      printf("\nThe Factorial of %d is eqaul to %d ", nfactorial, result);
    }
   else
   {
      printf("\nThe number must be integer graent than zero\n");
   }

    printf("\nNow we are calculating the factorial number using a recursive function\n");
    myFactorial(nfactorial);

    return 0;
}

