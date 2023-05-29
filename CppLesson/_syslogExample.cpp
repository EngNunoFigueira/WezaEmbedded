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


using namespace std;


/*
LOG_EMERG:0
LOG_ALERT:1 
LOG_CRIT:2
LOG_ERR:3
LOG_WARNING:4
LOG_NOTICE:5
LOG_INFO:6
LOG_DEBUG:7
*/

#include <syslog.h>

int main()
{
  setlogmask (LOG_UPTO (LOG_INFO));
  openlog ("exampleprog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);  

//syslog (LOG_NOTICE, "Program started by User %d", getuid ());
syslog (LOG_INFO, "Nuno Miguel Figueira Manuel first test usign syslog in C++");

closelog ();

}

