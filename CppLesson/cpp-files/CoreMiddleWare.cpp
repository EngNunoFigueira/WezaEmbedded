#include <time.h>  
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <sstream>
#include <cstdint>
#include <cstring>


using namespace std;


 void getSecondPassed(double minutes)
	{
	    double passedMinutes=0.0;
	    time_t initTime,endTime;
	    
	    time(&initTime);
	    cout<<"initTimestamp: "<<initTime<<endl;
		
	    while(passedMinutes <= minutes)
	    {
	       time(&endTime);
	       passedMinutes = difftime(endTime,initTime);
	       cout<<"passedMinutes :"<<passedMinutes<<endl;      
	    }    
	     cout<<"endTime: "<<endTime<<endl;  
	}

	 void MaxPrint()
	{
	   static int Max =0;
	   if(Max<3)
	   {
	   	 cout<<"Max value:: "<<Max<<endl;
	   	 Max++;  
	   }
	   else
	   {
	   	 cout<<"Cannot call the Max because their limit is out of scope: "<<Max<<endl;
	   }
	  
	}

	void WriteLog(int nWrites, std::string message)
	{
		while(nWrites!=0)
		{
           //LOG_WA(message);
           getSecondPassed(1.0);
           nWrites--;
		}
     
	}
	void GxOutgoingAdapter(double minutes)
     {
       double passedMinutes=0.0;
       time_t initTime,endTime;
       time(&initTime);
        std::cout<<"initTimestamp: "<< initTime<<endl;
       while(passedMinutes < minutes)
            {
               time(&endTime);
               passedMinutes = difftime(endTime,initTime);  
               //std::cout<<"passedMinutes: "<< passedMinutes<<endl;
            }
            std::cout<<"endTimestamp: "<< endTime<<endl;  
      }

/*
 * Erase First Occurrence of given  substring from main string.
 */
void eraseSubStr(std::string & mainStr, const std::string & toErase)
{
	// Search for the substring in string
	size_t pos = mainStr.find(toErase);
 
	if (pos != std::string::npos)
	{
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
	}
}

int main()
{
	int timeToSleep=1000;
	std::stringstream m;
    //m.empty();
    //m.clear();

   int test_logs_string_length=200;

   char strrnd[test_logs_string_length + 1];
   srand(time(NULL));
   for(int i=0; i <= test_logs_string_length-1; i++)
      strrnd[i] = 65 + rand() % (90 - 65);

   std::string vCBAlog=strrnd;
   std::string Merda="33672441 12:25:16.072+0100 10/29/2018 ER safComp=sapc.pcrfProc.payload,safSu=PL-3,safSg=NWA,safApp=ERIC-sapc.pcrfProc.payload Error sending CCA. SessionId: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA, Protocol: Gx";
   //char messageRest[]="tc: -1, ci: 3, thp: -1, ulMbr/apnUlMbr: 208000, dlMbr/apnDlMbr: 104000, ulGbr: -1, dlGbr: -1, si: -1, td: -1, arpPri: 3, arpPvi: -1, arpPci: -1, resType:"; 
   char messageRest[]="ci: 3, ulMbr/apnUlMbr: 208000, dlMbr/apnDlMbr: 104000, ulGbr: -1, dlGbr: -1, arpPri: 3, arpPvi: -1, arpPci: -1, resType:"; 
  // char dest[144];
   //memcpy(dest, messageRest, 144);
     //for (char c : dest)
    //    std::cout << c;
    //  std::cout << '\n';

    std::string logProfile=messageRest;	 
     unsigned int pos = logProfile.find(", resType");
	if (pos != std::string::npos)
	{
	   logProfile.erase(pos, 9);
	   std::cout << "logProfile:" << logProfile << std::endl;
	   std::cout << "pos:" << pos << std::endl;
	}

   //std::string remove=",resType";
   //std::string Mydata=messageRest;
   //cout<<"Mydata"<<Mydata<<std::endl;

   //eraseSubStr(Mydata, ",resType");

   //cout<<"Mydata after remove :"<<Mydata<<std::endl;

    //std::string(messageRest);  
	//cout << "End program..."<<endl;
	//getSecondPassed(60.0);
	//std::string Log="DNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHF";
	//std::string sapcLog="1821 16:59:33 02/22/2016 ER safComp=ERIC-SAPC_PcrfProc,safSu=ERIC-SAPC_PcrfProc-3,safSg=ERIC-SAPC_PcrfProc,safApp=ERIC-SAPC Diameter incoming message discarded. SessionId: tc_04_02_Reset_Period_2GGSN_gxr9;ggsnNodeHostname.nodeHostRealm.com;2;460222, SubsId: 34600320402, Protocol: Gx, MesssageType: CCR-I";
    //std::string Log="10241 21:45:28.121+0200 10/17/2018 ER safComp=sapc.pcrfProc.payload,safSu=PL-4,safSg=NWA,safApp=ERIC-sapc.pcrfProc.payload Error sending CCA. SessionId:DNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRAAAAAAAAAAATOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMA-tc_04_02_Reset_Period_2GGSN_gxr9;ggsnNodeHostname.nodeHostRealm.com;2;460222, Protocol: Gx";
    //WriteLog(1, sapcLog);    

    //GxOutgoingAdapter(2.0);
   // std::cout<< "Numero de caracteres: "<<Log.length()<<endl;

  //  std::cout<< "vCBA log size: "<<vCBAlog.length()<<endl;
//   std::cout<< "Merda log size: "<<Merda.length()<<endl;

   // std::clock_t Processor= clock();

   // std::cout<< "Processor time: "<<Processor<<endl;

   // std::stringstream ss;

  /* 
  for (int i=1000; i>0; --i) {
    std::cout << i << std::endl;
    //std::this_thread::sleep_for (std::chrono::seconds(60));  
    std::this_thread::sleep_for (std::chrono::milliseconds(timeToSleep)); 
  }
  std::cout << "Lift off!\n";

  */

  /* MaxPrint();
   MaxPrint();
   MaxPrint();
  int nbrOfLogsToWrite=101, exit=0,option=1;
  ss << nbrOfLogsToWrite <<"DNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRAAAAAAAAAAATOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMAJDHFDNVMHFGLOWERODHLGOWMNCHSGERPOIWYUERUJGODGRTOMA-tc_04_02_Reset_Period_2GGSN_gxr9;ggsnNodeHostname.nodeHostRealm.com;2;460222";

   std::cout<< "Call the Max again:"<<endl;
   MaxPrint(); */

  /* while(nbrOfLogsToWrite>0 && exit==0)
   {
   	switch(option)
   	{

   		case 1:
   		  nbrOfLogsToWrite--;
   	      std::cout<< "nbrOfLogsToWrite:"<< nbrOfLogsToWrite <<endl;
   		break;
   		case 2:
   		    std::cout<<"Case 2"<<endl;
   		break;
   		default:
   		    std::cout<<"Case Default"<<endl;
   		break;
   	}
   	  
      if(nbrOfLogsToWrite==1)
      {
      	exit++;
        std::cout<< "Mambo grande:"<<endl; 
      }
      	
   } */


    return 0;   
}

//lib/cpp-logs/src/main/c/Log.cc:#include <Log.hh>
//lib/cpp-logs/src/main/c/Log.hh:/*! \file Log.hh
 //LOG_ER(ERROR_SENDING_CCA, sessionId.first.c_str(), LOGGINGEVENT_PROTOCOL_GX);