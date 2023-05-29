#ifndef IMODULE_H
#define IMODULE_H

#include <iostream>
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
#include <type_traits>

#include"IModule.h"

const unsigned int EMPTY{0};
const unsigned int BYTE_ARRAY_SIZE=7;
const unsigned int INPUT_BUFFER_MAX_SIZE=3;

/*-------------------------------------------------------------------------------------------------------------------*
* It is important define a Data Structure to represent the complite information requested to be printed in Module 3: * 
* char arrays[100] and UTC, for each data that Match a sequence of pre-defined bytes (0x00, 0x01, 0x02)              *           
*--------------------------------------------------------------------------------------------------------------------*/
struct stData
{
 // stData(){}
  stData(const unsigned char bf[])
  {
    for (int i = 0; i < BYTE_ARRAY_SIZE; ++i)
    {
      chBuffer[i]=bf[i];
    }
  }
  bool isMatch{false};
  std::string receivedDateTime{};
  unsigned char chBuffer[BYTE_ARRAY_SIZE]{};
};


/*-----------------------------------------------------------------------------------------------------------------------------------*
* Class DataManing, is a object we created to encapsulate the code that implement the algorithm used to Search for a Match sequence * 
* of char bytes (0x00,0x01,0x02) inside a char byte[] Random generated . In case of found, this information are printout on MOdule 3.*           
*------------------------------------------------------------------------------------------------------------------------------------*/

class DataManing
{
  public:
  DataManing(){}
  DataManing( std::shared_ptr<std::vector<stData>> inputBfTreeIn )
  { 
     _inputBfTreeIn = inputBfTreeIn; 
  }
 ~DataManing(){}
  void SearchForMatch(stData byteArrays)
  {  
     for (int i = 0; i < BYTE_ARRAY_SIZE; ++i)
     {
      if((BYTE_ARRAY_SIZE-i)>= 3)
       {
         if(byteArrays.chBuffer[i]==0x00)
            if(byteArrays.chBuffer[i+1]==0x01)
               if(byteArrays.chBuffer[i+2]==0x02)
               {
                 std::cout<<"SEARCH MATCH"<<std::endl;
                 byteArrays.isMatch=true;
                 MatchFoundSendDataToModuleTree(byteArrays);
                 break;
               }
       }
    }
  }
 void MatchFoundSendDataToModuleTree( const stData & dataByte)
 {
    if (_inputBfTreeIn->size() != INPUT_BUFFER_MAX_SIZE ) 
    {
     _inputBfTreeIn->push_back(dataByte);
    }
   else
     return;
  }
  void PrintMatchData()
  {
    std::cout<<"MODULE TREE STARTING PRINT DATA"<<std::endl;
     for_each(_inputBfTreeIn->begin(), _inputBfTreeIn->end(), [](const stData &arrBytes ) {
     std::cout<<"The UTC is: "<< arrBytes.receivedDateTime<<std::endl;
     std::cout<<"The Buffer [ "; 
     for (int i = 0; i < BYTE_ARRAY_SIZE; ++i)
     {
         std::cout<< static_cast<unsigned int> (arrBytes.chBuffer[i])<<" "; 
     }
        std::cout<<" ]"<<std::endl; 
     });
  }
  private:
  std::shared_ptr<std::vector<stData>> _inputBfTreeIn;
};



/*------------------------------------------------------------------------------------------------------------------------------------------*
* Classe IModule, is the interface requested as requeriment for this job challenge.                                                         * 
*                                                                                                                                           *
* We define just one pure virtual method, that will be rewrited by each module/class to implement the their own Thread Function/Task.       *
* The IModule has tree variables: 2-> shared_ptr<<std::vector<stData>> Buffer and 1-> std::mutex *mtx=nullptr. It is allow use the value    *
* of this member variables inside all  tree Modules.                                                                                        *                    
*                                                                                                                                           *                                                           
* NOTES:                                                                                                                                    *
*                                                                                                                                           *
* Using an interface, was a big challenge for working with a MultiThread solution, because:                                                 *
* 1.1 - We need ensure that the shared resource, the buffers in this case, are protected against mutual access. Or just one object at time. *
* 1.2 - In resume, we can say that the challenge, here, was pass a MUTEX "non-copyable element" for Tree differents objects.                *
* 1.3 - As the InpuBuffer_T2 and InpuBuffer_T3 are resources used by the tree objects/MOdules, we used two shared_ptr                       *   
*-------------------------------------------------------------------------------------------------------------------------------------------*/


class IModule
{
    public:
    virtual void Task( )=0;
    protected: 
    std::shared_ptr<std::vector<stData>> inputBufferInModuloTwo{};
    std::shared_ptr<std::vector<stData>> inputBufferInModuloTree{};
    IModule( std::shared_ptr<std::vector<stData>> _bfIn, std::shared_ptr<std::vector<stData>> _bffIn )
    { 
      inputBufferInModuloTwo  = _bfIn;
      inputBufferInModuloTree = _bffIn; 
    }
};

#endif