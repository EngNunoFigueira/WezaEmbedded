#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Person
{

public:
  Person(int aged, std::string named)
  {
     age=aged;
     name=named;
  }
  void whoAreYou()
  {
    std::cout<<"my name is  "<< name << "and I am "<< age<<std::endl;
  }
private:
  int age=20;
  std::string name="Jonh";
}; 


enum commands
{
   TS           =8388637,  // TSR/TSA 8388637
   CC           =272,      // CCR/CCA 272
   ReAuth       =258,      // RAR/RAA 258
   AA           =265,      // AAA/AAR 265
   ST           =275,      // STR/STA 275
   AS           =274      //  ASR/ASA 274
};

enum  requestCommands
{
   request=1,
   answer =2,
   unknow =0
};
enum  interface
{
   Gx    =1,
   Rx    =2,
   Sd    =3,
   Sy    =4,
   ifaceUnknow=0
};

/***************************************************************************************************************************/
/* FUNCTION: initiator                                                                                                      *
****************************************************************************************************************************/
std::string getOrigin(const commands &cmd, const requestCommands &requestType, const interface &interface)
{
    switch(interface)
	{
		case Rx:
		switch(requestType)
		{
           case request:          // Rx protocol request  cmds
            if(AA==cmd)           // AAR/AAA
            {
               std::cout<<"Sent by an AF to the PCRF in order to provide it with the Session Information"<<endl;
               return "AF";
            }
            else if(ReAuth==cmd)  // RAR
            {
               std::cout<<"Sent by the PCRF to the AF in order to indicate an Rx-specification action"<<endl;
               return "PCRF";
            }
            else if(ST==cmd)    //  STR
            {
               std::cout<<"Sent by the AF to inform the PCRF that an established session shall be terminated"<<endl;
               return "AF";
            }
             else if(AS==cmd)   // ASR
            {
               std::cout<<"Sent by the PCRF to inform the AF that bearer for the established session is no longer available"<<endl;
               return "PCRF";
            }
           break;
           case answer:        // Rx protocol answer cmds
           	if(AA==cmd)        // AAA
            {
               std::cout<<"Sent by the PCRF to the AF in response to the AAR commands"<<endl;
               return "PCRF";
            }
            else if(ReAuth==cmd)  // RAA
            {
               std::cout<<"Sent by the AF to the PCRF in response to the RAR commands"<<endl;
               return "AF";
            }
            else if(ST==cmd)   // STA
            {
               std::cout<<"Sent by the PCRF to the AF in response to the STR commands"<<endl;
               return "PCRF";
            }
            else if(AS==cmd)  //  ASA
            {
               std::cout<<"Sent by the AF to the PCRF in response to the ASR commands"<<endl;
               return "AF";
            }
           break;
		}
		break;
		case Gx:
		switch(requestType)
		{
           case request:
           if(CC==cmd)
           {
              std::cout<<"Sent from PCEF to a PCRF, e.g. in order to request PCC rules"<<endl;
              return "PCEF";
           }
           else if(ReAuth==cmd)
           {
              std::cout<<"Sent by PCRF to the PCEF in order to provide PCC rules using the push procedure"<<endl;
              return "PCRF";
           }
           break;
           case answer:
           if(CC==cmd)
           {
              std::cout<<"Sent by a PCRF in response to the CCR command"<<endl;
              return "PCRF";
           }
           else if(ReAuth==cmd)
           {
             std::cout<<"Sent by a PCEF in response to the RAR command"<<endl;
             return "PCEF";
           }
           break;
		}
		break;
		case Sd:
		switch(requestType)
		{
           case request:     // requests cmds
           if(TS==cmd)       // TSR
           {
             std::cout<<"Sent by the PCRF to the TDF in order to estabblish the TDF session and to provision the ADC rulesF"<<endl;
             return "PCRF";
           }
           else if(CC==cmd)   // CCR
           {
             std::cout<<"Sent from a TDF to a PCRF, e.g. in order to request a ADC rules and to inform PCRF about the request application detection"<<endl;
             return "TDF";
           }
           else if(ReAuth==cmd) // RAR
           {
             std::cout<<"sent by a PCRF to the TDF in order to provision ADC rules using the push procedure"<<endl;
             return "PCRF";
           }
           break;
           case answer:      // answer cmds
           if(TS==cmd)       // TSA
           {
             std::cout<<"TSA Sent by a TDF in response to the TSR commands."<<endl;
             return "TDF";
           }
           else if(CC==cmd) // CCA
           {
             std::cout<<"CCA sent by a OCRF in response to the CCR commands"<<endl;
             return "PCRF";
           }
           else if(ReAuth==cmd) // RAA
           {
             std::cout<<"RAA sent by the TDF in response to RAR"<<endl;
             return "TDF";
           }
           break;
		}
		break;
		default:
		break;
	}

   return "interface not found";
}
/****************************************************************************************************************************/
/* FUNCTION: target                                                                                                         *
*****************************************************************************************************************************/
std::string getOrigin(const commands &cmd, const requestCommands &requestType, const interface &interface, int nbr)
{
    switch(interface)
	{
		case Rx:
		switch(requestType)
		{
           case request:          // Rx protocol request  cmds
            if(AA==cmd)           // AAR/AAA
            {
               std::cout<<"Sent by an AF to the PCRF in order to provide it with the Session Information"<<endl;
               return "PCRF";
            }
            else if(ReAuth==cmd)  // RAR
            {
               std::cout<<"Sent by the PCRF to the AF in order to indicate an Rx-specification action"<<endl;
               return "AF";
            }
            else if(ST==cmd)    //  STR
            {
               std::cout<<"Sent by the AF to inform the PCRF that an established session shall be terminated"<<endl;
               return "PCRF";
            }
             else if(AS==cmd)   // ASR
            {
               std::cout<<"Sent by the PCRF to inform the AF that bearer for the established session is no longer available"<<endl;
               return "AF";
            }
           break;
           case answer:        // Rx protocol answer cmds
           	if(AA==cmd)        // AAA
            {
               std::cout<<"Sent by the PCRF to the AF in response to the AAR commands"<<endl;
               return "AF";
            }
            else if(ReAuth==cmd)  // RAA
            {
               std::cout<<"Sent by the AF to the PCRF in response to the RAR commands"<<endl;
               return "PCRF";
            }
            else if(ST==cmd)   // STA
            {
               std::cout<<"Sent by the PCRF to the AF in response to the STR commands"<<endl;
               return "AF";
            }
            else if(AS==cmd)  //  ASA
            {
               std::cout<<"Sent by the AF to the PCRF in response to the ASR commands"<<endl;
               return "PCRF";
            }
           break;
		}
		break;
		case Gx:
		switch(requestType)
		{
           case request:
           if(CC==cmd)
           {
              std::cout<<"Sent from PCEF to a PCRF, e.g. in order to request PCC rules"<<endl;
              return "PCRF";
           }
           else if(ReAuth==cmd)
           {
              std::cout<<"Sent by PCRF to the PCEF in order to provide PCC rules using the push procedure"<<endl;
              return "PCEF";
           }
           break;
           case answer:
           if(CC==cmd)
           {
              std::cout<<"Sent by a PCRF in response to the CCR command"<<endl;
              return "PCEF";
           }
           else if(ReAuth==cmd)
           {
             std::cout<<"Sent by a PCEF in response to the RAR command"<<endl;
             return "PCRF";
           }
           break;
		}
		break;
		case Sd:
		switch(requestType)
		{
           case request:     // requests cmds
           if(TS==cmd)       // TSR
           {
             std::cout<<"Sent by the PCRF to the TDF in order to estabblish the TDF session and to provision the ADC rulesF"<<endl;
             return "TDF";
           }
           else if(CC==cmd)   // CCR
           {
             std::cout<<"Sent from a TDF to a PCRF, e.g. in order to request a ADC rules and to inform PCRF about the request application detection"<<endl;
             return "PCRF";
           }
           else if(ReAuth==cmd) // RAR
           {
             std::cout<<"sent by a PCRF to the TDF in order to provision ADC rules using the push procedure"<<endl;
             return "TDF";
           }
           break;
           case answer:      // answer cmds
           if(TS==cmd)       // TSA
           {
             std::cout<<"TSA Sent by a TDF in response to the TSR commands."<<endl;
             return "PCFR";
           }
           else if(CC==cmd) // CCA
           {
             std::cout<<"CCA sent by a OCRF in response to the CCR commands"<<endl;
             return "TDF";
           }
           else if(ReAuth==cmd) // RAA
           {
             std::cout<<"RAA sent by the TDF in response to RAR"<<endl;
             return "PCRF";
           }
           break;
		}
		break;
		default:
		break;
	}

   return "interface not found";
}

typedef std::map<string, int> ScoreByName;
typedef std::map<int, Person> BankAccount;
/****************************************************************************************************************************/
/* FUNCTION: main                                                                                                           *
*****************************************************************************************************************************/
int main()
{
  size_t length=7;
  char HOSTNAME[100];

  if( gethostname(HOSTNAME, length)== 0 )
  {
    std::string hostname=HOSTNAME;
    std::cout<<"COMPUTER HOSTNAME :"<<hostname<<endl;
  } 
  
  ScoreByName nuno;
  nuno.insert(std::make_pair<std::string, int>("ASSA",21));
  nuno["Ana"]=21;

   std::cout<<"The value is: "<<nuno["Ana"]<<std::endl;


  int i=2;
  BankAccount moneySecure;
  Person PedroCabral(34,"Pedro de Jesus");
  Person Borlido(36,"Jesus Borlido");

  BankAccount::iterator pi;

  pi->second=PedroCabral;

  //moneySecure.insert(std::make_pair< int,Person>(234,*PedroCabral));
  //moneySecure[2220.30]=PedroCabral;

/*std::map<int, MyClass> myMap;

MyClass foo;
myMap[5] = foo;
myMap[5].bar = 10;
*/

	std::cout<<"The program will testing the followings commands of TFD node: "<<endl;
	std::cout<<"TS: "          <<TS<<endl;
	std::cout<<"ST: "          <<ST<<endl;
	std::cout<<"CC : "         <<CC<<endl;
	std::cout<<"AA: "          <<AA<<endl;
	std::cout<<"ReAuth : " <<ReAuth<<endl;
	std::cout<<"AS : "         <<AS<<endl;
	
  getOrigin(CC, request, Gx);
	return 0;
}
