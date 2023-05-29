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
#include <map>
#include <iterator> 
#include <cstdio>
#include <cstring>
#include <vector>
#include <memory>
#include <unordered_map> 
#include <stdio.h>
#include <string.h>
#include <iostream> 
#include <tuple> 
#include <stdarg.h>
#include <algorithm>
//#include <boost/detail/algorithm.hpp>
using namespace std;


tuple<int,int> logThisEvent(std::string logId)
{
   if(logId=="logThisEvent")	
   return make_tuple(1,3);

   if(logId== "doesNotThisEvent")
   return make_tuple(0,0);
}

int main()
{
	std::cout<<"this is a program to testing the Tuple object in C++"<<std::endl;
  
    auto logEventConfig=getLogEventData();

  std::cout<<"The enable is:"<<logEventConfig.enable<<std::endl;

  return 0;

}


