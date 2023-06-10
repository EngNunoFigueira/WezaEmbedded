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
                      
int carToyWorkshop(int wheels, int carBodies, int figuresPerson)
{
 
  int _wheels{std::move(wheels)};
  int _carBodies{std::move(carBodies)};
  int _figuresPerson{std::move(figuresPerson)};
  int units{0};
  while(_carBodies>=1 && _figuresPerson>=2 && _wheels >=4)
  {
       units++;
      _wheels-=4;
      _carBodies-=1;
      _figuresPerson-=2;         
  }
  return units;
 } 

int main()
{
  std::cout<<"Find the number of cars we can assemble with the floowing components"<<std::endl;
  std::cout<<"A: 8-wheels \nB: 6-bodies \nC: 9-people figurues"<<std::endl;
  std::cout<<"The manufacture can assemble "<<carToyWorkshop(43, 15, 87)<<" cars"<<std::endl;
  
 return 0;
}
