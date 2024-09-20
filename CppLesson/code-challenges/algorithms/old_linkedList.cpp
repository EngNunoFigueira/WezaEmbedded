#include<iostream>
#include<stdio.h>

using namespace std;


struct linkedList
{
	linkedList(int _val):
	value{_val},
	nextNode{nullptr}
	{
		// NOthing todo...
	}

	int value{0};
	linkedList *nextNode;
};

linkedList *createLinkedList(int value, linkedList *headNode)
{
    headNode = new linkedList(1);
 	return headNode;
}

int main(int argc, char **agrv)
{

    std::cout<<"This program create a linkedList"<<std::endl;
    
    size_t lcounter{0};
    linkedList *headNode;
    linkedList *nodeA{new linkedList(2)};
    headNode = nodeA;
    linkedList *nodeB{new linkedList(3)};
    nodeA->nextNode=nodeB;
    linkedList *nodeC{new linkedList(5)};
    nodeB->nextNode=nodeC;
    linkedList *nodeD{new linkedList(7)};
    nodeC->nextNode=nodeD;

  
    linkedList *printValues = headNode;
    while(printValues != nullptr)
    {
    	lcounter++;
        std::cout<<"This is the "<<lcounter<<"º value of the node "<< printValues->value <<std::endl;
        printValues = printValues->nextNode;
    }


	return 0;
}