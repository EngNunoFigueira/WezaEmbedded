#include <iostream>
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



using namespace std;

inline unsigned int
getMostSignificantBitSet(unsigned short bitmap)
{
   unsigned int msb = 0;

   while (bitmap >>= 1)
   {
      msb++;
   }

   return msb;
}

class Person
{
public:
Person(std::string getname, int getage)
	{
		userName=getname;
		age=getage;
		std::cout<<"My Name is:"<<userName<<std::endl;
	}
std::string userName;
int age;

};

class LogEvent
{
public:
	explicit LogEvent(std::string _logId, unsigned int _severity, bool _enable)
	: logId(_logId)
	, severity(_severity)
	, enable(_enable)
    {
    }
   
   std::string getLogId()
   {
     return logId;
   }
   unsigned int getSeverity()
   {
      return severity;
   }
   bool getEnable()
   {
      return enable;
   }

   // SETTINGS VALUES:
   void setSeveriy(unsigned int _severity)
   {
     severity=_severity;
   }
   void setEnable(bool _enable)
   {
   	 enable=_enable;
   }
   void setLogEventId(std::string _logId)
   {
     logId=_logId;
   }
 
   std::shared_ptr<LogEvent> getMydiameterLog()
   {
	  return std::make_shared<LogEvent>(logId,severity,enable);
   }
private:

    	bool enable;
    	std::string logId;
    	unsigned int severity; 
};

typedef struct  {
	char department;
	std::string phone;
}Jobs;

typedef struct  {
	int age;
	std::string Name;
	Jobs *_job;
}Worker;


template<typename T>
void getPersonalData(T &option)
//(const SaImmAttrValuesT_2** attr, char const* logEventAttrName, unsigned int index, T& logEventType)
{
	//if(zero==0) //severity
	//{
      //return option;
	//}
   //else if(zero==1) // enable
   //{
   	 //option+=36;
     //return option;
   //} 
   (*option)=23;
   cout<<"Get the values of BI: "<<std::endl;

   //return option;
}

void UpdateLogEvntMap()
{

  //Remove all delete LogEvents for businessEvents and restEvents:
 /* if(MapDeleted != nullptr)
  {

   for(auto itemDelete : MapDeleted)
   {
   	for (auto item : itemDelete.second) // Name of logs that will be deleted...
   	{
   	   //std::cout<<"List of Log to delete :"<< item <<std::endl;
   	   if(VictorlogEvents.find(item)==VictorlogEvents.end())
   	   {
   	   	  std::cout<<"This Log is not in the list to be removed"<<std::endl;
   	   }
   	   else
   	   {
   	   	 std::cout<<"This Log will be removed from the list"<<std::endl;
   	   	 VictorlogEvents.erase(item);
   	   }
   	}
   }
  }

  // New LogEvents Created:
  if(CreadetOrModifiedMap != nullptr)
  {
     for(auto item : CreadetOrModifiedMap)
     {
     	for(auto itemCreatModfied : item.second)
     	{
          if(MAPF.find(itemCreatModfied->logId())==MAPF.end())
          {
              // add the new Log:
          	MAPF.insert(make_pair(itemCreatModfied->logId(),itemCreatModfied));
          }
          else
          {
             // update the values of this current Log:
          	 MAPF.at(itemCreatModfied->logId())->getSeverity=itemCreatModfied->severity();
          	 MAPF.at(itemCreatModfied->logId())->getEnable= itemCreatModfied->enable();
          }
     	}
     }
  }
*/

} 


bool takeEbaleField(int select)
{
	if(select==0)
	return nullptr;
    if(select==1)
	return true;
    if(select==2)
	return false;
}

int main()
{
    // declaration of vector of LogEvents:
    vector<LogEvent> ofLogEvents;
    vector<LogEvent> Brendly;
    vector<LogEvent> Marley; 

    /*
    unordered_map is an associated container that stores elements formed by combination of key value and a mapped value.
    The key value is used to uniquely identify the element and mapped value is the content associated with the key. Both key 
    and value can be of any type predefined or user-defined.
    Internally unordered_map is implemented using Hash Table, the key provided to map are hashed into indices of hash table that is 
    why performance of data structure depends on hash function a lot but on an average the cost of search, insert and delete from hash 
    table is O(1).
    */
    std:: unordered_map<std::string, std::vector<LogEvent>> appLoger;

	std::map<std::string, int> Reference;
	std::map<int, Person> Student;
	std::map<int, Person> iterator;
	std::cout<< "This is the tester program to validate some function of ApplicationLogger"<<std::endl;
	std::cout<< "Execute the function: getMostSignificantBitSet"<<std::endl;
	unsigned short Nuno= getMostSignificantBitSet(0x007);
    std::cout<< "MostSignificantBitSet is:"<<Nuno<<std::endl;

    std::cout<< "Create and Inset a my person to the map"<<std::endl;
    Person Yo("Marta", 20);
    Student.insert(pair<int,Person>(1,Yo));
    std::cout<< "Operation sucessufl"<<std::endl;
    std::cout<<""<<std::endl;
    for(auto it = Student.cbegin(); it != Student.cend(); ++it)
    {
       std::cout << it->first<<std::endl;
       std::cout << it->second.userName<<std::endl;
    }
    std::cout<<""<<std::endl;

    std::cout<< "The name of the person Yo is:"<<Student.at(1).userName<<std::endl;
    //std::cout<< "And is:"<<iterator.first<<"age"<<std::endl;

    std::cout<< "starting debug the LOG elements:"<< std::endl;
   std::cout<<""<<std::endl;
    //Create some LOGs:
    LogEvent RAA("RAA",1,true);
    LogEvent RAR("RAR",6,true);
    LogEvent AAA("AAA",8,false);
    LogEvent AAR("AAR",6,false);
    LogEvent SYD("SYD",3,true);
    LogEvent YYA("YYA",4,true);
    LogEvent SYA("SYA",4,true);

    //insert this LOgs to a vector
    ofLogEvents.push_back(RAA);
    ofLogEvents.push_back(RAR);
    ofLogEvents.push_back(AAA);
    ofLogEvents.push_back(AAR);
    Brendly.push_back(SYD);
    

    std::cout<< "Print the name of LOgs in vector:"<< std::endl;
    std::cout<< "The vector has the following logs:"<<std::endl;
    for(auto & eachElements : ofLogEvents )
    {
       std::cout<<eachElements.getLogId() <<std::endl;
    }  
    std::cout<<""<<std::endl;
    //insert values to the unorder map: std:: unordered_map<std::string, std::vector<LogEvent>> appLoger;
    std::string CcbId="CBA-BusinessEvent";
    appLoger[CcbId]=ofLogEvents;

    for (auto x : appLoger) 
    {
    	cout << "The MAP key is: "<< x.first << std::endl;  
        for(auto &i : x.second)
        {
          cout <<"The LOGs in unordermap are:" <<i.getLogId()<<std::endl;	
        }
    }
   
     std::cout<<""<<std::endl;
     std::cout<<"Print another position of the Map "<<std::endl;
     std::cout<<""<<std::endl;
    // Add new values to a unorder map using first and second methods:
    std::string PTsinger="Ana Moura";
    std::string ESsinger="Alba Carilho";
    appLoger.insert({PTsinger,Brendly});
    for (auto x : appLoger) 
    {
    	cout << "The MAP key is: "<< x.first << std::endl; 
        for(auto &i : x.second)
        {
          cout <<"The LOGs in unordermap are:" <<i.getLogId()<<std::endl;	
        }
    }

    if(appLoger.find(ESsinger)==appLoger.end())
    {
      cout <<"NOT FOUND"<<std::endl;
      cout <<"and create a new MAP with key Alba Carilho"<<std::endl;
      Marley.push_back(YYA);
      appLoger.insert(make_pair(ESsinger,Marley));
    }
    else
    {
       cout <<"UPDATE THE MAP key Ana Moura"<<std::endl;
       appLoger.at(PTsinger).push_back(SYA);
    }
    
    for (auto x : appLoger) 
    {
    	cout << "The MAP key is: "<< x.first << std::endl; 
        for(auto &i : x.second)
        {
          cout <<"The LOGs in unordermap are:" <<i.getLogId()<<std::endl;	
        }
    }
    
    // This method enabled access the second paramter of a map:
    //appLoger.at(PTsinger).push_back(SYD);
    
    // in this step we will training the shared_ptr. So the idea is create a vector that receive a shared_ptr object:

    //create a shared_ptr LogEvent:
    std::shared_ptr<LogEvent> diameterLogs;
    //create a vector of shared_ptr type LogEvent:
    vector<std::shared_ptr<LogEvent>> vLogs;
    
    
    // print the shared pointer LOG received:
    diameterLogs=RAA.getMydiameterLog();
    std::cout<<"The shared_ptr name is: "<< diameterLogs->getLogId()<<std::endl;

    //initialize the VECTOR with the shared_ptr LogEvent
    vLogs.push_back(diameterLogs);

    // TESTING A FUNCTION TEMPLATE<typename>
    std::string marley="ola";
    int jessica=1;
    int *nuno=&jessica;
   // string name=getPersonalData(marley);
    getPersonalData(nuno);
    std::cout<< "The value get from the function is : "<< jessica << std::endl;
 

  // testing pointer ** and transform into arrays:
   // Worker **Marta;
    //Marta[0]->_job[0].department='I';


// TESTING LOGEVENT FUNCTIONS:
   std::shared_ptr<LogEvent> Lognuno;
   Lognuno=AAA.getMydiameterLog();

   //MAP used to manager the LogEvents:
   //std::unordered_map<SaImmOiCcbIdT, std::vector<std::string>> logEventsImmMapDeleted;
   //std::unordered_map<std::string,std::vector<string>>MapDeleted;

   // DECLARAMOS UM MAP DE LOGS:
   std::string logId1="AAA";
   std::string logId2="RAA";
   std::string logId3="logId3";
   std::string logId4="logId4";
   std::map<std::string, std::shared_ptr<LogEvent>> VictorlogEvents;
   VictorlogEvents.insert(std::make_pair(logId1,Lognuno));
   VictorlogEvents.insert(std::make_pair(logId2,diameterLogs));
   std::cout<<"The Victor shared_ptr name is: "<<VictorlogEvents.at(logId1)->getLogId()<<std::endl;

   // DECLARAMOS UM MAP DE COM OS NOMES DOS LOGs QUE DEVEM SER REMOVISO:
   std::unordered_map<std::string,std::vector<string>>MapDeleted;
   //LogId:
   std::string CccbID="removed";
   std::string notCcbId1="notremoved";
   std::string notCcbId2="keep";
   // List of Logs to remove:
   std::vector<std::string> ListOfLogsToDelete;
   // Inite the vector:
   ListOfLogsToDelete.push_back(CccbID);
   ListOfLogsToDelete.push_back(notCcbId1);
   ListOfLogsToDelete.push_back(notCcbId2);
   ListOfLogsToDelete.push_back(logId1);
   MapDeleted.insert(std::make_pair(CccbID,ListOfLogsToDelete));

   //MapDeleted.insert(std::make_pair(CccbID,logId2));
   //MapDeleted.insert(std::make_pair(notCcbId1,logId3));
   //MapDeleted.insert(std::make_pair(notCcbId2,logId4));

// PRINT THE MAP VALUES BEFORE THE ACTION:
   for(auto itemLogs : VictorlogEvents)
   {
   	 cout << "Theses are the Log names inside the finally Map : "<< itemLogs.first << std::endl; 
   	 cout << "Theses are the Log in the map before deleted    :"<< itemLogs.second->getLogId() << std::endl; 
   } 

   // DELET OPERATION:
   for(auto itemDelete : MapDeleted)
   {
   	for (auto item : itemDelete.second) // Name of logs that will be deleted...
   	{
   	   //std::cout<<"List of Log to delete :"<< item <<std::endl;
   	   if(VictorlogEvents.find(item)==VictorlogEvents.end())
   	   {
   	   	  std::cout<<"This Log is not in the list to be removed"<<std::endl;
   	   }
   	   else
   	   {
   	   	 std::cout<<"This Log will be removed from the list"<<std::endl;
   	   	 //VictorlogEvents.erase(item);
   	   }
   	}
   }

// PRINT THE MAP VALUES AFTER THE ACTION:
    for(auto itemLogs : VictorlogEvents)
   {
   	 cout << "Theses are the Log names inside the finally Map after delted: "<< itemLogs.first << std::endl; 
   	 cout << "Theses are the Log in the map after deleted    :"<< itemLogs.second->getLogId() << std::endl; 
   } 


   
   // CcbId str:
   std::string ImmOp="ImmccbId=1";
   // shared_ptr LogEvents:
   std::shared_ptr<LogEvent> LogMauro;
   LogMauro=RAR.getMydiameterLog();
   std::shared_ptr<LogEvent> LogAlexandre;
   LogAlexandre=RAA.getMydiameterLog();
   std::shared_ptr<LogEvent> LogAcacio;
   LogAcacio=SYA.getMydiameterLog();
   // vector:
   std::vector<shared_ptr<LogEvent>> vecMapCreatedModify;
   //vecMapCreatedModify.push_back(Lognuno);
   vecMapCreatedModify.push_back(LogMauro);
   vecMapCreatedModify.push_back(LogAlexandre);
   vecMapCreatedModify.push_back(LogAcacio);

   // CREATE THE unordered_map<CcbId, std::vector<shared_ptr<LogEnts>>
    std::unordered_map<std::string, std::vector<std::shared_ptr<LogEvent>>> MapCreatedModify;
    MapCreatedModify.insert(std::make_pair(ImmOp,vecMapCreatedModify));   
  


   // New LogEvents Created:
  if(!MapCreatedModify.empty())
  {
     for(auto item : MapCreatedModify)
     {
     	for(auto itemCreatModfied : item.second)
     	{
          if(VictorlogEvents.find(itemCreatModfied->getLogId())==VictorlogEvents.end())
          {
              // add the new Log:
          	cout<<"This is a new log added :" << itemCreatModfied->getLogId()<<std::endl;
          	VictorlogEvents.insert(make_pair(itemCreatModfied->getLogId(),itemCreatModfied));
          }
          else
          {
             // update the values of this current Log:
          	 cout<<"This will be updated:" << itemCreatModfied->getLogId()<<std::endl;
          	 //VictorlogEvents.at(itemCreatModfied->logId())->getSeverity=itemCreatModfied->severity();
          	 //VictorlogEvents.at(itemCreatModfied->logId())->getEnable= itemCreatModfied->enable();
          }
     	} 
     }
  }

  std::string Log1="Log1";
  std::string Log2="Log2";
  std::string Log3="Log3";
  std::map<std::string, std::shared_ptr<LogEvent>> ImmListOfLogs;
  //std::map<std::string, std::shared_ptr<LogEvent>> VictorlogEvents;
  std::shared_ptr<LogEvent> ImmLogEvents(new LogEvent(Log1,1,true));
  ImmListOfLogs[Log1]=ImmLogEvents;

   //update LOG
 /* ImmLogEvents->setSeveriy(2);
  ImmLogEvents->setEnable(true);
  ImmLogEvents->setLogEventId(Log2);
  ImmListOfLogs[Log2]=ImmLogEvents;*/

  ImmListOfLogs.insert(std::make_pair("Log2",(std::make_shared<LogEvent>("Log2",1,true))));
   
  //update LOG
  ImmLogEvents->setSeveriy(3);
  ImmLogEvents->setEnable(true);
  ImmLogEvents->setLogEventId(Log3);
  ImmListOfLogs[Log3]=ImmLogEvents;
  // criamos um std::make<shared_ptr>



  //vector of shared_ptr
  //std::make_shared<LogEvent>(logId,severity,enable);
  //std::vector<std::shared_ptr<LogEvent>> LogRecoverFromImm; 
  //std::make_shared<LogEvent>ImmFLog;

   std::cout<< "This is the Log Name get from IMM  to the Finally Map "<<std::endl;
   for(auto item : ImmListOfLogs )
   {
   	 //LogRecoverFromImm.push_back();
   	 std::cout<< " " << item.second->getLogId()<<std::endl;
   }

  // Testing get the businessEventId:
std::string *strAna;
std::string strGloria="businessEventId=Nuno";
strAna=&strGloria;

const char* s = "hello world!";
const size_t start = 16;

size_t end = 12; // Assume this is an exclusive bound.

std::string substring((*strAna).c_str() + start, strAna->length() - start);

strAna->length();
std::cout<<"This is length of Ana:"<< strAna->length() <<std::endl;
std::cout<<"This is my substring:"<< substring <<std::endl;


// COVERT int to bool:

int *nunoMiguel;
int mauro=0;
nunoMiguel=&mauro;

bool type=(*nunoMiguel)==1 ? 1:0;

if(type)
{
  std::cout<<"This is true:"<<std::endl;
}
else
{
  std::cout<<"This is false:"<<std::endl;
}

if(takeEbaleField(0)==nullptr)
std::cout<<"Sorry we send a nullptr:"<<std::endl;

return 0;

}

/*const std:string getLogEventName(std::string &logEventId)
{
	int number=(*logEventId)->length()- start;
	return std::string substring((*strAna).c_str() + start, strAna->length() - start);

} */

/*

typedef struct  {
	char department;
	std::string phone;
}Jobs;

typedef struct  {
	int age;
	std::string Name;
	Jobs *_job;
}Worker

*/



	  //get the values from created object:
	  //String Slogan, Bool state, unsigned int severity 
	 
	 
	 // The Main Struct we need know very well is: 
	 // Reading the Struct SaImmAttrValuesT_2
	 
	  // attr[0]->attrName             : Indicate the atribute Name
	  // attr[0]->attrValueType       : integer,float, string,double or other type
	  // attr[0]->attrValuesNumber:   : Number of parameters contains in array attrValues
	  // attr[0]->attrValues[0]      :  This is the Array that contain the atributes of created Object atributes