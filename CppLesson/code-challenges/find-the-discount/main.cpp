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

void findTheDiscount(int price, int discount)
{
  if(discount == 50){
    float endPrice = (float)price/2;
    std::cout<<std::fixed<<std::setprecision(2)<< endPrice<<std::endl;
  }
  else{
    float endPrice = (float)price-(((float)price*(float)discount)/100);
    std::cout<<std::fixed<<std::setprecision(2)<< endPrice<<std::endl;
  }
}

int main()
{
  std::cout<<"Applay the discount on the original prices"<<std::endl;
  findTheDiscount(121, 17); 
  findTheDiscount(1500, 50);
  findTheDiscount(89, 20);
  findTheDiscount(100, 75); 

 return 0; 
}
