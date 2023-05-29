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
#include <syslog.h>
#include <mutex> 
#include <condition_variable>

using namespace std;

unsigned int sharedValues=0;
struct  logData
{
  unsigned int priority;
  const char* message;
  const string identation;
};

bool dataIsReady=false;
std::mutex lockQueueBuffer;
std::condition_variable isEnable;

int bufferSize=5;
queue<int> dataBuffer;
queue<int> auxDataBuffer;
bool dataBufferIsReady=false;
bool auxDataBufferIsReady=false;

void producer( queue<int>& dataLog)
{

std::cout<< "producer thread running"<<std::endl;
unsigned int counter=6;
unsigned int nTimes=0;
unsigned int auxCounter=0;
while(nTimes != 3)
{
    std::unique_lock<std::mutex> locker(lockQueueBuffer); 

	for (int i = 0; i < counter; ++i)
	{
	  //std::unique_lock<std::mutex> locker(lockQueueBuffer);  
	     dataLog.push(i);
	     //dataIsReady=true;
	  //locker.unlock();
	  //isEnable.notify_one();
      for(int i=0; i<9000; i++);
	  std::cout<<"producer thread deliver data :"<< i <<std::endl;
	}
	dataIsReady=true;
	locker.unlock();
	isEnable.notify_one();

	while(dataIsReady==true);
	//for(int i=0; i<1000000; i++);
    nTimes++;	
    auxCounter=counter;	
}
  std::cout<<"producer thread finish job with nTimes equal :"<< nTimes<<std::endl;
}


/*EventLog producer two*/

void WriteEventLog()
{

   std::cout<< "PRODUCER: running"<<std::endl;
   unsigned int nTimes=1;

while(nTimes < 13)
{
    std::unique_lock<std::mutex> locker(lockQueueBuffer); 

    if((dataBuffer.size() < bufferSize) && dataBufferIsReady==false )
    {
       dataBuffer.push(nTimes);
       std::cout<< "PRODUCER FIRST BUFFER: push:"<< nTimes << std::endl;
       if(dataBuffer.size() == bufferSize)
       {
       	 dataBufferIsReady=true;
	     locker.unlock();
	     isEnable.notify_one();
       }
    }
    else if((auxDataBuffer.size() < bufferSize) && auxDataBufferIsReady==false )
    {
      auxDataBuffer.push(nTimes);
      std::cout<< "PRODUCER SECOND BUFFER: push:"<< nTimes << std::endl;
      if( auxDataBuffer.size() == bufferSize )
       {
       	 auxDataBufferIsReady=true;
       	 dataBufferIsReady=true;
	     locker.unlock();
	     isEnable.notify_one();
       }
    }
    else
    {
    	// write now
    	std::cout<<"The two buffer are busy, write now the Log"<<std::endl;
    }

    for(int i=0; i<1000000000; i++);
    nTimes++;		
}
  std::cout<<"producer thread finish job with nTimes equal :"<< nTimes<<std::endl;
}

/*end */

/*ReadEventLog*/
void ReadEventLog()
{
	std::cout<< "CONSUMER: running"<<std::endl;

	while(true)
	{
	   std::unique_lock<std::mutex> locker(lockQueueBuffer);
	   isEnable.wait(locker, [] { return dataBufferIsReady; } );

	   if((dataBuffer.size() == bufferSize) && dataBufferIsReady==true)
	   {
	   	  std::cout<< "CONSUMER: pop data:"<< dataBuffer.front()<<std::endl;
	      while( !dataBuffer.empty() )
	      {
	        std::cout<< "CONSUMER: pop data:"<< dataBuffer.front()<<std::endl;
            dataBuffer.pop();
          }
          dataIsReady=false;
          locker.unlock();
          std::cout<< "CONSUMER: empty the dataBuffer "<<std::endl;
      }
      else if((auxDataBuffer.size() == bufferSize) && auxDataBufferIsReady==true )
      {
         while( !auxDataBuffer.empty() )
	     {
	       std::cout<< "CONSUMER: pop data:"<< auxDataBuffer.front()<<std::endl;
           auxDataBuffer.pop();
         }
         dataIsReady=false;
         locker.unlock();
         std::cout<< "CONSUMER: empty the auxDataBuffer "<<std::endl;
      }

	}	
}

/*end */

void consumer( queue<int>& dataLog)
{
	std::cout<< "consumer thread running"<<std::endl;

	while(true)
	{
	   std::unique_lock<std::mutex> locker(lockQueueBuffer);
	   isEnable.wait(locker, [] { return dataIsReady; } );
	   while(!dataLog.empty())
	   {
	       //std::cout<< "consumer thread running"<<std::endl;
	       std::cout<< "List of data read from buffer:"<< dataLog.front()<<std::endl;
           dataLog.pop();
           //while(true);
           //for(int i=0; i<9000; i++);
       }
       dataIsReady=false;
       locker.unlock();
       std::cout<< "consumer thread empty buffer"<<std::endl;
	}	
}

int main()
{
	std::cout<< "This is a testing program to evaluate the Thread sincronization"<<std::endl;
	/*
	// old solution without input parameters:
    queue<int> myqueue; 
	thread runProducer (producer, std::ref(myqueue));
	thread runConsumer (consumer, std::ref(myqueue));

	runProducer.join();
	runConsumer.join();
     */

	// New solution without input parameters:

    thread runProducer (WriteEventLog);
	thread runConsumer (ReadEventLog);

	runProducer.join();
	runConsumer.join();


	return 0;
}

/*
ApplicationLogger::writeLogRecord(int priority, const char* logRecordMessage, const std::string& logIdentation)
{
   TRACE_FUNCTION_DEBUG("Enter. Priority=%u, Message='%s', Identation='%s'",
                        priority,
                        logRecordMessage,
                        logIdentation.c_str());
   {
      std::unique_lock<std::mutex> lock(logmutex);

      if (logsToWrite.size() < logPoolSize && (!bufferIsFree))
      {
      	 // write log to the buffer
         logData logToWrite;
         logToWrite.priority = priority;
         logToWrite.logRecordMessage = std::string(logRecordMessage);
         logToWrite.logIdentation = logIdentation;
         logsToWrite.push(logToWrite);
         if(logsToWrite.size()==(logPoolSize))
         	bufferIsFull=true;
         lock.unlock();
         incomingLogEvent.notify_one();
      }
      else if(logsToWrite.size() < logPoolSize && (!auxBufferIsFree))
      {
         // If the buffer is busy write log to the aux buffer
         logData logToWrite;
         logToWrite.priority = priority;
         logToWrite.logRecordMessage = std::string(logRecordMessage);
         logToWrite.logIdentation = logIdentation;
         auxlogsToWrite.push(logToWrite);
         if(logsToWrite.size()==(logPoolSize))
         	auxBufferIsFull=true;
         lock.unlock();
         incomingLogEvent.notify_one();
      } 
      else if( (logsToWrite.size() > logPoolSize) || (auxlogsToWrite.size() > logPoolSize) )
      {
         writeLogRecordNow(priority, logRecordMessage, logIdentation);
      }
   }
}

*/

/*
void logWorker()
{
   logging = true;
   while (logging)
   {
   	   // wait the producer send a full buffer 
       std::unique_lock<std::mutex> locker(logmutex);
	   isEnable.wait(locker, [] { return bufferIsFull; } );
	   while(!logsToWrite.empty())
	   {
         logData logToWrite;
         std::unique_lock<std::mutex> lock(logmutex);
         logToWrite = logsToWrite.front();
         logsToWrite.pop();
         sapc::cba::writeLogRecord(logToWrite.priority,
                logToWrite.logRecordMessage.c_str(),
                logToWrite.logIdentation.c_str());
       }
       bufferIsFull=false;
       locker.unlock();

       std::unique_lock<std::mutex> locker(logmutex);
	   isEnable.wait(locker, [] { return auxbufferIsFull; } );
       while(!auxlogsToWrite.empty())
	   {
         logData logToWrite;
         std::unique_lock<std::mutex> lock(logmutex);
         logToWrite = logsToWrite.front();
         auxlogsToWrite.pop();
         sapc::cba::writeLogRecord(logToWrite.priority,
                logToWrite.logRecordMessage.c_str(),
                logToWrite.logIdentation.c_str());
       }
       auxbufferIsFull=false;
       locker.unlock();
	}
         
}
*/


//compile line: g++ ThreadExample.cpp -o mainThread -pthread -std=c++1y