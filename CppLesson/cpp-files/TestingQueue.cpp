#include <iostream>
#include <time.h>  
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <sstream>
#include <queue>
#include <unistd.h>
#include <sys/types.h>
#include <syslog.h>
using namespace std;

struct  logData
{
  unsigned int priority;
  const char* message;
  const string identation;
};

int main()
{   
  std::cout << "In this example we testing the QUEUE libray in C++ using the <queue.h>" <<endl;
  queue<int> myqueue; 
  myqueue.push(1); 
  
  if (myqueue.empty())
  { 
  	int getNumber=myqueue.pop();
    cout << "True"<<endl; 
  } 
  else
  { 
  	 cout << "False"<<endl; 
  } 

	return 0;
}


