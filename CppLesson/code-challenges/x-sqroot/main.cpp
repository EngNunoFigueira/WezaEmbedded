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

int squareRoot(int a, int b, int c)
{
  return abs(b - std::sqrt((b*b)-4*a*c))/(2*a);  
}

int main()
{
  std::cout<<"Find the sqaure root of equation -> ax2+2ab+c"<<std::endl;
  std::cout<<"The sqaure root of equation (a=2, b=-7,  c=3)  is: "<<squareRoot(2, -7, 3)<<std::endl;
  std::cout<<"The sqaure root of equation (a=1, b=-12, c=28) is: "<<squareRoot(1, -12, -28)<<std::endl;
  std::cout<<"The sqaure root of equation (a=1, b=2,   c=-3) is: "<<squareRoot(1, 2, -3)<<std::endl;

 return 0;
}
