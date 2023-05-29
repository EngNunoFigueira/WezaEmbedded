/*------------------------------------------------------------------------------------------------------------------------------------------
Year: 2022/March
Autor: Nuno Figueira
Email: ekumbi48172@hotmail.com
LinkedInd: https://www.linkedin.com/in/nuno-figueira-2aa2785b/
Project: IT job Code Challenge.

This code was developed in C++11, OS UBUNTU 14.04 LTS. Editor Sublime Text Editor. 
Command Line Compilation: g++ main.cpp -o main  ModuleT1.* IModule.* ModuleT2.* ModuleT3.* RandomByteGenerator.* -std=c++1y -pthread
Debuguer Tools: UNIX DGB
Execution line: ./main
---------------------------------------------------------------------------------------------------------------------------------------------*/


#include "ModuleT1.h"
#include "ModuleT2.h"
#include "ModuleT3.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	std::mutex mymutex;
	std::mutex pLmutex;
    auto bufferTwo = std::make_shared<std::vector<stData>>();
    auto bufferTree = std::make_shared<std::vector<stData>>();

    ModuleT1 _ModuleT1( bufferTwo, bufferTree, mymutex);
 	ModuleT2 _ModuleT2( bufferTwo, bufferTree, mymutex);
 	ModuleT3 _ModuleT3( bufferTwo, bufferTree, pLmutex);

    std::thread JoinmT1 = _ModuleT1.Run();
 	std::thread JoinmT2 =_ModuleT2.Run();
 	std::thread JoinmT3 =_ModuleT3.Run();

    JoinmT1.join();
 	JoinmT2.join();
 	JoinmT3.join();

    while(true);
	return 0;
}