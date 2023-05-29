/*
Year: 2021
Autor: Nuno Figueira
Project: Explain how is the lambda expresion and where we need them on ssoftware solution.
Objective: 
The objective of this small c++14 program, is pratices with code  that can be written using Lambada Expression.
Such as the stadndards functions like for example the function std::for_each_(var.begin(), var.end(), function_need ).
*/

#include<stdio.h>
#include<stdlib.h>


struct Node 
{
	int key;
	struct  Node *leftNode;
    struct  Node *rightNode;
};
struct  Node *rootNode;
void CheckIfAllocationFailed(struct  Node* ptrNode)
{
     if(ptrNode == NULL)
     {
     	printf("Error! memory not allocated.");
        exit(0);
     }
}
MemoryDeallocation(struct  Node* ptrNode)
{
  free(ptrNode);
}

struct Node* CreateNewNode(int data)
{
     printf("New node for binary tree created\nwith key equal to :%d", data);
     struct Node* nodeBST = (struct Node*)malloc(sizeof(struct Node));
     if( nodeBST == NULL )
     {
        printf("Error! memory not allocated.");
        exit(0);
     }
     nodeBST->key=data;
     nodeBST->leftNode=NULL;
     nodeBST->rightNode=NULL;
     return nodeBST;
}

struct Node* InsertDataToNode(struct  Node* CurrentNodeBST , int data)
{
       if( CurrentNodeBST == NULL )
          CurrentNodeBST = CreateNewNode(data);
  	   else if(CurrentNodeBST->key > data)
  	   {
  	   	  printf("\nThe data %d will be insert to the left side of binary Tree\n", data);
          CurrentNodeBST->leftNode = InsertDataToNode(CurrentNodeBST,data);
  	   }
  	   else if(CurrentNodeBST->key < data)
  	   {
  	   	  printf("\nThe data %d will be insert to the right side of binary Tree\n", data);
          CurrentNodeBST->rightNode =  InsertDataToNode(CurrentNodeBST,data);
  	   }

     return CurrentNodeBST;
}

int main( int argc, char *argv[])
{
	int value=0;
    printf("\nThis programming will manager a binary tree to Data Storage in memory\n");
    printf("\nPlease, introduce a value greater than zero to put on the Binary Tree\n");
  
   /* scanf("%d", &value);
    InsertDataToNode(value);
    printf("\nData correctly inserted...");
    //second element
    printf("\nPlease, introduce the second element:\n");
    scanf("%d", &value);
    InsertDataToNode(value);
    printf("\nData correctly inserted...");
    // third element
    printf("\nPlease, introduce the third element:\n");
    scanf("%d", &value);
    InsertDataToNode(value);
    printf("\nData correctly inserted...");

    printf("\nTheses are the list of data introduce by the user:\n");
    printf("\n The data inserted on root  %d\n",  rootNode->data);
    printf("\n The data inserted on left  %d\n",  rootNode->leftNode->data);
    printf("\n The data inserted on right %d\n",  rootNode->rightNode->data);
    printf("\n Now we will recover the data insert into the memory\n");
    printf("\n The data inserted was %d\n", rootNode->data);
    MemoryDeallocation(rootNode);
    */

    //rootNode = InsertDataToNode(rootNode,70);
    //rootNode = InsertDataToNode(rootNode,90);
    //rootNode = InsertDataToNode(rootNode,30);
    //rootNode = InsertDataToNode(rootNode,10);
    //rootNode = InsertDataToNode(rootNode,50);
    //rootNode =InsertDataToNode(rootNode,40);
    //rootNode =InsertDataToNode(rootNode,40);
    //printf("\n The data inserted on root  %d\n",  rootNode->key);
   // printf("\n The data inserted on root  %d\n",  rootNode->data);
    //printf("\n The data inserted on root  %d\n",  rootNode->data);

    Counter(0, 20);

    //MemoryDeallocation(rootNode);


    
    
	return 0;
}