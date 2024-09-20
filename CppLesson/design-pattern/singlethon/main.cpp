/**
 * Date: 08/2024/
 * Autor: Nuno Figueira
 * Email: ekumbi48172@hotmail.com
 * Project: IT job Interview Code Challenge
 * Video CV:  https://www.youtube.com/watch?v=liOPojIVjH4
 * LinkedInd: https://www.linkedin.com/in/nuno-figueira-2aa2785b/
 *
 * Editor Sublime
 * Programming language Cpp version 11
 * Operation System Linux Ubuntu 20.04 LTS
 * Command line execution: ./main
 * ./main
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

/**
 * The method receive order array of integers and found the moda.
 * @param int
 * @param int
 * @return int
 */

class Repository
{

private:
    Repository(){}
  public:  
  ~ Repository(){}

  Repository(const Repository&) = delete;

  static Repository & getInstance()
  {
    static Repository _repository;
    return _repository;
  }

  void printMessage()
  {
     std::cout<<"This is an implementation of a Singlethon..."<<std::endl;
  }
  
};

//Repository Repository::_repository;


int main(int argc, char** argv)
{
  std::cout<<"This is an implementation of a Singlethon..."<<std::endl;

  Repository *tekas = &Repository::getInstance();
  tekas->printMessage();

  return 0;
}


