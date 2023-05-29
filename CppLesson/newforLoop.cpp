#include <iostream>
#include <vector>
//#include <string_view>


using namespace std;

int main()
{
  std::cout<<"This programming is for testing the new For loop in C++11"<<"\n"<<std::endl;
  std::vector<std::string> peopleNames {"Marley", "Alzira", "Alexandre"};
  for(auto &names: peopleNames)
  { 
     std::cout<<"The names is :"<< names <<std::endl;
  }

  return 0;
}
