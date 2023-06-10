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
#include <sstream>
#include <regex>

void swiftChar(std::string original, int *step)
{
  int index{0};
  std::string output{};
  std::stringstream reverse{};
  for(unsigned char caracter : original)
  {
     if( step[index] == 1) {
         caracter = (unsigned char)(caracter+0x001);
     }
     else if( step[index] == -1) {
         caracter = (unsigned char)(caracter-0x001);
     }
    reverse << caracter;
    index++;
  }

  reverse >> output;
  std::cout<<"This is the output stream: "<<output<<std::endl;
}

int main()
{
  std::cout<<"Create a function that tweaks letters by one forward (+1) or backwards (-1) according to an array."<<std::endl;
  std::array<int,5> tip{1,1,1,1,1};
  swiftChar("rhino", tip.data());

  return 0; 
}
