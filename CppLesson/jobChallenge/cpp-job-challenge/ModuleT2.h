#ifndef MODULET2_H
#define MODULET2_H

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
#include "IModule.h"
#include "RandomByteGenerator.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------------*
* Class ModuleT2, this is the second Module implemented to support the algorithm of SEARCH AND MATCH FOUND...                                       *
* This ModuleT2 TASK, is check if one of the byte char arrays sent from ModuleT1 to the INPUT Buffer 2, has the following sequence: 0x00,0x01,0x02. * 
* In case of this sequence MATCH, the data will be delivery to the INPUT BUFFER 3.                                                                  *
*                                                                                                                                                   *
* In terms of code we can say that the ModuleT2 is a bit critical because is the bridge between ModuleT1 and ModuleT3. So, we must get attention... *
* To work with two shared resorces that will be accessed by MUTEX.                                                                                  *
* AS CAN YOU TESTING THIS CODE IN SIMPLE WAY:                                                                                                       *                                
* Using the same process we described for the MOduleT1.                                                                                             *
*                                                                                                                                                   *
* We create another object named DataManing to implement the functions or methods that will be used by ModuleT2 and ModuleT3 to manager the data    *
* stored in the buffers.                                                                                                                            *
*                                                                                                                                                   *                    
*---------------------------------------------------------------------------------------------------------------------------------------------------*/

class ModuleT2: public IModule, public DataManing
{
    public:
    ModuleT2( std::shared_ptr<std::vector<stData>> _bfInn , std::shared_ptr<std::vector<stData>> _bffIn, std::mutex & mtex );
    void Task();
    ~ModuleT2();
    std::thread Run();
    private:
    std::mutex *_mutex=nullptr;		
};
#endif
