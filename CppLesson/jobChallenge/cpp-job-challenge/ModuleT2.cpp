#include <cstdio>
#include <cstdlib> 
#include <ctime> 
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

#include "ModuleT2.h"
#include "RandomByteGenerator.h"

  ModuleT2::ModuleT2(std::shared_ptr<std::vector<stData>> _bfInn , std::shared_ptr<std::vector<stData>> _bffIn, std::mutex & mtex )
  :IModule( _bfInn, _bffIn),DataManing(_bffIn){ _mutex = &mtex; }
  void ModuleT2::Task()
  {
    while(true) 
    {
      std::this_thread::sleep_for (std::chrono::milliseconds(100));
      std::cout<<"MODULO 2"<<std::endl;
      while( inputBufferInModuloTwo->size() != INPUT_BUFFER_MAX_SIZE );
      std::lock_guard<std::mutex> lck{*_mutex};
      {
        std::for_each(inputBufferInModuloTwo->begin(), inputBufferInModuloTwo->end(), std::bind(&ModuleT2::DataManing::SearchForMatch, this, std::placeholders::_1));
        inputBufferInModuloTwo->erase(inputBufferInModuloTwo->begin(), inputBufferInModuloTwo->end());
      }
     }
  }
  std::thread ModuleT2::Run()
  { 
    std::thread _thread(&ModuleT2::Task, this);
    return _thread;
  }
  ModuleT2::~ModuleT2(){}
		