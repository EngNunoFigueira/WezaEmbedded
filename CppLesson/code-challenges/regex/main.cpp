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

void isHexa(std::string value)
{
  if(value.length()>=6)
  {
    std::cout<<"The input value is not valid: "<<value.length()<<std::endl;
    return;
  }
  else if (std::regex_match (value, std::regex("#[A-F]+[0-9]*[A-F0-9]*") ))
  {
    std::cout<< "string literal matched\n"<<std::endl;
  }
  else
    std::cout<<"string literal doesn't match"<<std::endl;
}

int main()
{
  std::cout<<"Regular expression in C++"<<std::endl;
  isHexa("#CD5C5C");
  isHexa("#CD5C");
   isHexa("#CD5CE");
  return 0; 
}
