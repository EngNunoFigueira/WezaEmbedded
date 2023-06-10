#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <thread>
#include <future>
#include <utility>
#include <memory>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <initializer_list>
#include <cstddef>
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <list>

int spinAround(std::list<std::string> step)
{
  
  int rStepCounter{0}; int rRound{0};
  int lStepCounter{0}; int lRound{0};

  for(auto guest : step)
  {
    if(guest == "right")
    {
       rStepCounter++;
       lStepCounter=0;
    }
    else if(guest == "left")
    {
       lStepCounter++;
       rStepCounter=0;
    }
    if(rStepCounter == 4)
    {
      rRound++;
    }
    if(lStepCounter == 4)
      lRound++;
  }

  if(rRound >=1)
  {
    return rRound;
  }
  else if(lRound >=1)
  {
    return lRound;
  }

  return 0;
}

int main()
{
  std::cout<<"Given a list of directions to spin, [left] or [right], return an integer of"<<std::endl;
  std::cout<<"how many full 360° rotations were made. Note that each word in the array counts"<<std::endl;
  std::cout<<"as a 90° \nrotation in that direction."<<std::endl;

  std::list<std::string> step{"right", "left", "right", "right", "left","left", "left", "left"};
  std::cout<<"Total rounds: "<<spinAround(step)<<std::endl;

 return 0; 
}
