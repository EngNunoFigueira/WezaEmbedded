// atomic::exchange example
#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread
#include <vector>         // std::vector
#include <memory>
#include <thread>
#include <chrono>        // std::chrono::seconds

int BigMike=0;
std::atomic<bool> ready (false);
std::atomic<bool> winner (false);
std::shared_ptr<bool> Nuno(new bool);
std::shared_ptr<bool> Miguel=std::make_shared<bool>(true); 

class Account { 

public: 
  Account () { }
  Account (std::shared_ptr<bool> flagTrigger) 
  {
     byteFlag=flagTrigger;
  }
  Account(int userAge, std::string userEmail,  std::string userMobile)
  {
     age=userAge;
     email=userMobile;
     mobile=userEmail;
  }
  void show() 
  { 
    *byteFlag=true;
     std::cout << "The value of *byteFlag is: "<<*byteFlag <<std::endl; 
     std::this_thread::sleep_for(std::chrono::seconds(10));
     *byteFlag=false;
     std::cout << "The value of *byteFlag is: "<<*byteFlag <<std::endl;
  }

 bool charles=false; 
  private:

    int age=0;
    std::string email="";
    std::string mobile="";
    bool internalTrigger=false;
    std::shared_ptr<bool> byteFlag; //=std::make_shared<bool>(false); 
}; 

void changeName(std::shared_ptr<Account> running)
{
  while(true)
  {
      std::cout<<"executing the 1 step..."<<std::endl;
      running->charles=true;
      std::this_thread::sleep_for(std::chrono::seconds(10));
     
      std::cout<<"executing the 2 step..."<<std::endl;
      running->charles=false;
      std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

void readData(bool *barroso)
{
  while(true)
  {
     std::cout << "The barroso value is: "<< *barroso<<std::endl;
     std::this_thread::sleep_for(std::chrono::seconds(35));
  }
}


int main ()
{

  //int* mike = NULL;
 // mike = &BigMike;
 
/* EXAMPLE GOOD .................................................*/
 // std::shared_ptr<bool> p1(new bool); 
 // std::cout<< p1.get() <<std::endl; 
  //p1->show(); 

  //std::shared_ptr<bool> p2(p1); 
  //p2->show(); 
  //std::cout << p1.get()<<std::endl; 
  //std::cout << p2.get()<<std::endl; 


//std::shared_ptr<bool> Patrick(Miguel);

//std::cout<<"Miguel: " <<Miguel.get()<<std::endl; 
//std::cout<<"Patrick: "<< Patrick.get()<<std::endl;

/*...............................................................*/

std::cout<<"Before Miguel: " <<*Miguel<<std::endl;
std::shared_ptr <Account> Neusa = std::make_shared<Account>(Miguel);  
Neusa->show();
std::cout<<"After Miguel: " <<*Miguel<<std::endl;

while(1);

bool *barroso=NULL;
{
  std::shared_ptr <Account> Marisa= std::make_shared<Account>(21, "ericsson@mobile.pt", "+351 96 14 24 701");
  barroso=&Marisa->charles;

  std::thread runConsumer (changeName, std::ref(Marisa));
  std::thread merda(readData, std::ref(barroso));
  
  merda.join();
  runConsumer.join();
}

std::cout<<"MAIN ...."<<std::endl;
while(1);

return 0;
}