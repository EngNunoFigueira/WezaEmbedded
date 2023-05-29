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

#include "ModuleT3.h"
#include "RandomByteGenerator.h"

ModuleT3::ModuleT3(std::shared_ptr<std::vector<stData>> _bfInn , std::shared_ptr<std::vector<stData>> _bffIn, std::mutex & mtex )
:IModule( _bfInn, _bffIn),DataManing(_bffIn){ _mutex = &mtex; }
 void ModuleT3::Task()
 {
    while(true)
    {   
      std::this_thread::sleep_for (std::chrono::milliseconds(6000));
      std::cout<<"MODULE 3"<<std::endl;
      while(inputBufferInModuloTree->size() == EMPTY );
      {
        std::lock_guard<std::mutex> pLock{*_mutex};
        PrintMatchData();
        inputBufferInModuloTree->erase(inputBufferInModuloTree->begin(), inputBufferInModuloTree->end());
      }
   }
 }
std::thread  ModuleT3::Run()
{ 
  std::thread _thread(&ModuleT3::Task, this);
  return _thread; 
}
ModuleT3::~ModuleT3(){}