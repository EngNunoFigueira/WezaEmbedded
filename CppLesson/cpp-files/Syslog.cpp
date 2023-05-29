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
#include <sstream>
using namespace std;


int main()
{
  // LOG OPTION...
   setlogmask (LOG_UPTO (LOG_INFO));
   openlog ("nundelTech", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
  //syslog (LOG_NOTICE, "Program started by User %d", getuid ());

  int counter=20000; 
  std::string WriteToLog;
  std::stringstream mixStringAndNumbers;
  const char* LOG = "This is a testing programming that log a cups of word to the syslog to testing the peformance in C++ ";
  

  LOG="This is a testing programming that log a cups of word to the syslog to testing the peformance in C++ ";
  //setlogmask (LOG_UPTO (LOG_INFO));
  //openlog ("nundelTech",0,LOG_USER);

  while(counter>0)
  {   
     mixStringAndNumbers << LOG << counter;
     WriteToLog=mixStringAndNumbers.str();

     for (int i=0; i< 100000; i++)
     {
         // this for implement a delay without sleep the program
     }
     syslog (LOG_INFO, LOG);
     //closelog ();
     
     // std::cout<< "String: "<< LOG.c_str()<< std::endl;
     mixStringAndNumbers.str("");
     mixStringAndNumbers.clear(); 

     counter --; 

   }

  std::cout<<"End Program"<< std::endl;
  closelog ();
  
return 0;

}

