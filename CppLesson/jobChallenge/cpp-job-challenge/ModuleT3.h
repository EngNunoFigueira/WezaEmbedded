#ifndef MODULET3_H
#define MODULET3_H

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
#include "IModule.h"
#include "RandomByteGenerator.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------------*
* Class ModuleT3, this is the last Module implemented to PRINTOUT/DISPLAY the information that corresponded with the sequence:0x00,0x01,0x02        *
* This ModuleT3 TASK, is check if the ModuleT2 delivery a byte char arrays and print this information.                                              * 
* In case of this sequence MATCH, the data will be delivery to the INPUT BUFFER 3.                                                                  *
*                                                                                                                                                   *
* We create another object named DataManing to implement the functions or methods that will be used by ModuleT2 and ModuleT3 to manager the data    *
* stored in the buffers.                                                                                                                            *
*                                                                                                                                                   *                    
*---------------------------------------------------------------------------------------------------------------------------------------------------*/

class ModuleT3 : public IModule, public DataManing
{
    public:
    ModuleT3(std::shared_ptr<std::vector<stData>> _bfInn , std::shared_ptr<std::vector<stData>> _bffIn, std::mutex & mtex );
    void Task();
    std::thread  Run();
    ~ModuleT3();
    private:
    std::mutex *_mutex=nullptr;
};

#endif