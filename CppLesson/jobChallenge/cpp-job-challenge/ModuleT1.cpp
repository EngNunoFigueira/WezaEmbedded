#include <cstdio>
#include <cstdlib> 
#include <thread>
#include <string> 
#include <time.h>  
#include <iomanip>
#include <chrono>
#include <ctime>
#include <mutex> 
#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>
#include <type_traits>

#include "ModuleT1.h"
#include "RandomByteGenerator.h"

   ModuleT1::ModuleT1(std::shared_ptr<std::vector<stData>> _bfIn , std::shared_ptr<std::vector<stData>> _bffIn, std::mutex & mtex )
    :IModule( _bfIn,  _bffIn) { _mutex = &mtex; }
   void ModuleT1::Task()
   {
     
    while(true)
    {
     std::lock_guard<std::mutex> lck{*_mutex};
     while( inputBufferInModuloTwo->size() != INPUT_BUFFER_MAX_SIZE )
     {
        byteArrays[nbytes] = _generator.TestData(arrayOrder,nbytes);  //_generator.getRandomByte();   
        nbytes++;
        if ((nbytes == BYTE_ARRAY_SIZE) && (inputBufferInModuloTwo->size() != INPUT_BUFFER_MAX_SIZE) )  
   	    {
   	      stData receivedData(byteArrays);
   	  	  receivedData.receivedDateTime=_generator.getTimeUTC();
   	  	  inputBufferInModuloTwo->push_back(receivedData);
          nbytes=0;
          arrayOrder++;
   	    }
   	    if ( inputBufferInModuloTwo->size() == INPUT_BUFFER_MAX_SIZE )
   	    {
   	      std::cout<<"MODULE 1 DELIVERY BUFFER "<<std::endl;
          std::this_thread::sleep_for (std::chrono::milliseconds(1000));
        }
     }
    }
   }
   std::thread ModuleT1::Run()
   { 
      std::thread _thread(&ModuleT1::Task, this);
      return _thread;
   }
