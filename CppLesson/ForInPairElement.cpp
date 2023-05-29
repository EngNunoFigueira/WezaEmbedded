#include <iostream> 
#include <utility> 
#include <time.h>  
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <sstream>
#include <queue>
#include <unistd.h>
#include <sys/types.h>
#include <map>
#include <iterator> 
#include <cstdio>
#include <cstring>
#include <vector>
#include <memory>
#include <unordered_map> 
/* memset example */
#include <stdio.h>
#include <string.h>
#include <set> 
using namespace std; 

//std::vector<std::shared_ptr<SubscriberGroupData>> activeGroups = ctx.getUserProfile()->getActiveGroups();
class  DataGroups
{
public:
	 DataGroups(int age, int birthday, std::string name, std::string surname)
	 {
	 	this->age=age;
	 	this->name=name;
	 	this->surname=surname;
	 	this->birthday=birthday;
	 }
	~ DataGroups()
	{
		std::cout<<"Finish program"<<std::endl;
	}
	int getAge()
	{
       return age;
	}
	std::string getName()
	{
      return name;
	}
	std::string getSurName()
	{
      return surname;
	}
	int getBithday()
	{
       return birthday;
	}
//SET:
    void setAge(int age)
	{
      this->age=age;
	}
	void getName(std::string name)
	{
      this->name=name;
	}
	void getSurName(std::string surname)
	{
      this->surname=surname;
	}
	void getBithday(int birthday)
	{
      this->birthday=birthday;
	}
private:
int age;
int birthday;
std::string name;
std::string surname;	

};

template<typename T>
void Afunction(T& data)
{
	std::cout<<"This is my data read "<<std::endl;
	for(int i=0; i< data.size(); i++)
    {
       std::cout<<" User name: "<<data[i]->getName()<< std::endl;
       std::cout<<" User age: " <<data[i]->getAge()<<std::endl;
    }

}
  
int main() 
{ 
	// EXAMPLE: 1º
    // CREATE AND INITIALIZE A SIMPLE VECTOR AND PRINT THEIR VALUES:
    /*pair <int, char> PAIR1 ; 
    PAIR1.first = 100; 
    PAIR1.second = 'G' ;
    cout << PAIR1.first << " " ; 
    cout << PAIR1.second << endl ; */
	// EXAMPLE: 2º
    // CREATE VECTOR OF TYPE std::pair<int, char>
    // INITIALIZE THE VECTOR WITH 5 ELEMENTS AND AFTER THAT PRINT EACH ELEMENT ON SCREEN
   /* int index=5;
    std::vector<std::pair<int, char> > dataMaining;
    for(int i=0; i< index; i++)
    {
       dataMaining.push_back(std::make_pair(1,'A'));
    }

   for(int i=0; i< index; i++)
    {
       std::cout<< "Values: "<< dataMaining[i].first << std::endl;
    }*/
	// EXAMPLE: 3º
    // CREATE  A CLASS CALLED DataGroups and CREATE A VECTOR <std::shared_ptr< DataGroups >
    // INITIALIZE THE VECTOR WITH 4 ELEMENTS AND AFTER THAT PRINT EACH ELEMENT ON SCREEN
     /*  std::vector<std::shared_ptr<DataGroups> > sapcData;
       sapcData.push_back(std::make_shared<DataGroups>(35,2019119,"Marley", "Headly"));
       sapcData.push_back(std::make_shared<DataGroups>(38,2016310,"William", "Mainson"));
       sapcData.push_back(std::make_shared<DataGroups>(24,201798,"Whitney", "Jordan"));
       sapcData.push_back(std::make_shared<DataGroups>(45,2018125,"Jessica", "Carrillo"));

      for(int i=0; i< sapcData.size(); i++)
      {
       std::cout<<" User name: "<<sapcData[i]->getName()<< std::endl;
       std::cout<<" User age: " <<sapcData[i]->getAge()<<std::endl;
      }*/
    
    // EXAMPLE: 4º
    // CREATE  A FUNCTION THAT RECEIVE A template<typename T> function(T& paramter)
    // THIS FUNCTION MUST PRINT THE VALUES OF THE ELEMENTS PASSED AS REFERENCE.
    // TO TESTING THE FUNCTION WE PASS THE VARIABLE sapcData THAT IS A VECTOR OF 
    // shared_pt<DataGroups>  
       //Afunction(sapcData);

    // EXAMPLE: 5º
    // CREATE  VECTOR OF DOUBLE PAIRS: vector<std::pair<std::pair<long, bool>, std::string> 
    // INITIALIZE THIS VECTOR WITH FOUR ELEMETES.
    // PRINT THE SECOND PAIR OF THE VECTOR   
    /*  std::vector<std::pair<std::pair<long, bool>, std::string> > modificationList;

      modificationList.push_back(std::make_pair(std::make_pair(1981, true),  "Rita Barroso"));
      modificationList.push_back(std::make_pair(std::make_pair(1989, false), "Sheila Pinto"));
      modificationList.push_back(std::make_pair(std::make_pair(2000, true),  "Marta Coelho"));
      modificationList.push_back(std::make_pair(std::make_pair(2019, false), "Inês cunha"));	
     
     for(auto item : modificationList)
     {
    	std::cout<<"The username is: "<<item.second<<std::endl;
        std::cout<<"The birthday is: "<<item.first.first<<std::endl; 	
     } */
 

     std::string getmyName;
     std::set<std::string> fullname;
     std::vector<std::string> nomes;
     std::vector<std::string> apelidos;
     std::set<std::string>::iterator it;

     nomes.push_back("Nuno");
     nomes.push_back("Miguel");
     nomes.push_back("Helio");
     nomes.push_back("Lukeny");
     nomes.push_back("Mauro");
     nomes.push_back("Nuno");

     apelidos.push_back("Figueira");
     apelidos.push_back("Manuel");
     apelidos.push_back("Figueira");
     apelidos.push_back("Manuel");
     apelidos.push_back("Domingos");

    std::ostringstream stream;
    std::copy(nomes.begin(), nomes.end(), std::ostream_iterator<std::string>(stream, ","));
    std::string result = stream.str();
    std::cout<<"The name list is: "<< result<<std::endl;

   
   
    std::cout<<" This is the string length: "<<result.length()<<std::endl;
    std::string MAE=result.replace ((result.length()-1),result.length(),"");
    std::cout<<"This is  MAE : "<< MAE<<std::endl;

    /*
    char *ch; 
    std::copy(result.begin(), result.begin()+(result.length()-1), ch);
    std::cout<<"This is the array finally data: "<< ch<<std::endl;
    */

     for(int i=0; i<nomes.size(); i++)
     {
        getmyName=nomes[i];
        it=fullname.find(getmyName);
        if (it==fullname.end())
        {
           fullname.insert(getmyName);
        }
        else
        {
        	std::cout<<"The name "<< getmyName<<" is duplicated and we removed the second ocurrence"<<std::endl;
        }
     }

     return 0; 
}
 