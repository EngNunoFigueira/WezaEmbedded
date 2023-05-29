#include <iostream>
#include <array>
#include <cstdio>
#include <cstdlib> 
#include <ctime> 
#include <thread>
#include <string> 
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
#include <map> 
#include <algorithm>
#include <condition_variable>

std::mutex lockInputBufferModuleTwo;
std::mutex lockInputBufferModuleTree;
std::condition_variable isDataAvaible;

const unsigned int EMPTY{0};
const unsigned int BYTE_ARRAY_SIZE=7;
const unsigned int INPUT_BUFFER_MAX_SIZE=3;
const unsigned char CHAR_BYTE_MAP [] {
 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,
 0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x00,0x01,
 0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x00,0x01,0x02,
 0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x00,0x01,0x02,0x03,
 0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x00,0x01,0x02,0x03,0x04,
 0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x00,0x01,0x02,0x03,0x64,0x65,
 0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70,0x71,0x72,0x73,0x74,0x75,0x76,
 0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,
 0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,
 0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,
 0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,
 0xBB,0xBC,0xBD,0xBE,0xBF,0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,
 0xCC,0xCD,0xCE,0xCF,0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,
 0xDD,0xDE,0xDF,0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,
 0xEE,0xEF,0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,
 0xFF
}; 

unsigned char TestData(int ArrayOrder, const int byteIndex)
{
   unsigned char data{};
   const unsigned char CHAR_BYTE_TESTA []{ 0x0A,0x01,0x02,0x03,0x04,0x05,0x06 };
   const unsigned char CHAR_BYTE_TESTB []{ 0x05,0x01,0x02,0x03,0x04,0x05,0x06 };
   const unsigned char CHAR_BYTE_TESTC []{ 0x00,0x01,0x02,0x03,0x04,0x05,0x06 };

   switch(ArrayOrder)
   {
   	case 0:
      data=CHAR_BYTE_TESTA[ byteIndex ];
   	break;
   	case 1:
   	data=CHAR_BYTE_TESTB[ byteIndex ];
   	break;
   	case 2:
   	data=CHAR_BYTE_TESTC[ byteIndex ];
   	break;
   	default:
   	break;
   }

   return data;
}

struct Data
{
  Data(){}
  Data(unsigned char bf[])
  {
	for (int i = 0; i < BYTE_ARRAY_SIZE; ++i)
	{
		chBuffer[i]=bf[i];
	}
  }
  bool isMatch{false};
  std::string receivedDateTime{};
  unsigned char chBuffer[BYTE_ARRAY_SIZE]{};
};

std::vector<Data> inputBufferInModuloTwo{};
std::vector<Data> inputBufferInModuloTree{};

int RandomGenerator()
{
    unsigned int getRandomValue{};
	static bool isTheFirstValue{true};
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    do{
        getRandomValue = static_cast<unsigned int>(RAND_MAX/std::rand());
    }while( getRandomValue > 255 );
   
   return getRandomValue;
}
const unsigned char ByteGeneratorUsingIntegerReference()
{
	int auxValue{};
    static int previousValue{};
	static bool isTheFirstValue{true};
    if (isTheFirstValue)
    {
      previousValue = RandomGenerator();
    }
    else if( (previousValue == RandomGenerator()) )
    {
      auxValue=previousValue;
      for (int i = 0; i < 5; ++i)
	  {
	    //std::this_thread::sleep_for (std::chrono::milliseconds(1));
		previousValue= RandomGenerator();
		if( auxValue !=previousValue )
			break;
	  }
    }
  
    isTheFirstValue=false;
    return CHAR_BYTE_MAP[previousValue];
}

const unsigned char getRandomByte()
{
	 return ByteGeneratorUsingIntegerReference();
}

void MatchFoundSendDataToModuleTree( Data & dataByte )
{
  if (inputBufferInModuloTree.size() != INPUT_BUFFER_MAX_SIZE ) 
  	{
  	   std::cout<<"COMPARADOR DE DADOS"<<std::endl;
  	   inputBufferInModuloTree.push_back(dataByte);
  	}
  else
  	return;
}

void PrintMatchData()
{
	std::cout<<"MODULE TREE STARTING PRINT DATA"<<std::endl;
	for_each(inputBufferInModuloTree.begin(), inputBufferInModuloTree.end(), [](const Data &arrBytes ) {
	  std::cout<<"The UTC is: "<< arrBytes.receivedDateTime<<std::endl;
	  std::cout<<"The Buffer [ "; 
	  for (int i = 0; i < BYTE_ARRAY_SIZE; ++i)
	  {
	  	 std::cout<< static_cast<unsigned int> (arrBytes.chBuffer[i])<<" "; 
	  }
	  std::cout<<" ]"<<std::endl; 
	});
}

void SearchForMatch(Data byteArrays)
{	 
	for (int i = 0; i < BYTE_ARRAY_SIZE; ++i)
   	{
   	  	if((BYTE_ARRAY_SIZE-i)>= 3)
   	  	{
         if(byteArrays.chBuffer[i]==0x00)
   	  	  if(byteArrays.chBuffer[i+1]==0x01)
   	  	  	if(byteArrays.chBuffer[i+2]==0x02)
   	  	  	{
   	  	  		byteArrays.isMatch=true;
   	  	  		MatchFoundSendDataToModuleTree(byteArrays );
   	  	  		break;
   	  	  	}
   	  	}
   	}
}

std::string getTimeUTC()
{
   char timeUTC[200];
   time_t t;
   struct tm *tmp;
   const char* fmt = "%a, %d %b %y %T %z";

   t = time(NULL);
   tmp = gmtime(&t);
   if (tmp == NULL) {
    perror("gmtime error");
    exit(EXIT_FAILURE);
  }

  if (strftime(timeUTC, sizeof(timeUTC), fmt, tmp) == 0) { 
    fprintf(stderr, "strftime returned 0");
    exit(EXIT_FAILURE); 
  } 
  return (timeUTC);
} 

void ModuleTwo()
{
  while(true) 
  {
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
   	std::cout<<"MODULO 2"<<std::endl;
    while( inputBufferInModuloTwo.size() != INPUT_BUFFER_MAX_SIZE );
    std::unique_lock<std::mutex> lck{lockInputBufferModuleTwo};
    {
       std::for_each(inputBufferInModuloTwo.begin(), inputBufferInModuloTwo.end(), SearchForMatch);
       inputBufferInModuloTwo.erase(inputBufferInModuloTwo.begin(), inputBufferInModuloTwo.end());
    }
  }
}

void ModuleTree()
{
	while(true)
	{   
		std::this_thread::sleep_for (std::chrono::milliseconds(6000));
		std::cout<<"MODULE 3"<<std::endl;
        while(inputBufferInModuloTree.size() == EMPTY );//!= INPUT_BUFFER_MAX_SIZE );
        {
          std::lock_guard<std::mutex> pLock{lockInputBufferModuleTree};
          PrintMatchData();
          inputBufferInModuloTree.erase(inputBufferInModuloTree.begin(), inputBufferInModuloTree.end());
        }
	}
}

void ModuleOne()
{ 
  unsigned int nbytes{0}, arrayOrder{0};
  unsigned char byteArrays [BYTE_ARRAY_SIZE]{};
  while(true)
  {
   std::unique_lock<std::mutex> lck{lockInputBufferModuleTwo};
   while( inputBufferInModuloTwo.size() != INPUT_BUFFER_MAX_SIZE )
   {
        byteArrays[nbytes] = TestData(arrayOrder,nbytes); //getRandomByte();   
        nbytes++;
        if ((nbytes == BYTE_ARRAY_SIZE) && (inputBufferInModuloTwo.size() != INPUT_BUFFER_MAX_SIZE) )  
   	    {
   	      Data receivedData(byteArrays);
   	  	  receivedData.receivedDateTime=getTimeUTC();
   	  	  inputBufferInModuloTwo.push_back(receivedData);
          nbytes=0;
          arrayOrder++;
   	    }
   	    if ( inputBufferInModuloTwo.size() == INPUT_BUFFER_MAX_SIZE )
   	    {
   	       std::cout<<"MODULE 1 DELIVERY BUFFER "<<std::endl;
           std::this_thread::sleep_for (std::chrono::milliseconds(1000));
        }
   }
  }
}

int main(int argc, char *argv[])
{
	std::cout<<"This is a code challenge required in job Application"<<std::endl;
    std::thread runProducer(ModuleOne);
    std::thread runConsumer(ModuleTwo);
    std::thread runPrintData(ModuleTree);
    runProducer.join();
    runConsumer.join();
    runPrintData.join();

	while(true);
	return 0;
}



/*
void ModuleOne()
{ 
  //std::cout<<"MODULE 1: "<< inputBufferInModuloTwo.size() <<std::endl;
  char byteArrays [BYTE_ARRAY_SIZE]{};
  unsigned int getRandomValue{}, nbytes{0};
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  while(true)
  {
   std::unique_lock<std::mutex> lck{lockInputBufferModuleTwo};
   while( inputBufferInModuloTwo.size() != INPUT_BUFFER_MAX_SIZE )
   {
   	 getRandomValue = static_cast<unsigned int>(RAND_MAX/std::rand());
   	 if (getRandomValue <= BYTE )
   	 {
        byteArrays[nbytes] = static_cast< unsigned char> (getRandomValue);
        nbytes++;
        if ((nbytes == BYTE_ARRAY_SIZE) && (inputBufferInModuloTwo.size() != INPUT_BUFFER_MAX_SIZE) )  
   	    {
   	      Data receivedData(byteArrays);
   	  	  receivedData.receivedDateTime=getTimeUTC();
   	  	  inputBufferInModuloTwo.push_back(receivedData);
          nbytes=0;
   	    }
   	 }
   	 if ( inputBufferInModuloTwo.size() == INPUT_BUFFER_MAX_SIZE ) {
   	    std::cout<<"MODULE 1 DELIVERY BUFFER "<<std::endl;
        std::this_thread::sleep_for (std::chrono::milliseconds(1000)); }
   }
  }
}

*/

/*

  //std::cout<<"MODULE 1: "<< inputBufferInModuloTwo.size() <<std::endl;
  unsigned int nbytes{0};
  unsigned char byteArrays [BYTE_ARRAY_SIZE]{};
  
  while(true)
  {
   std::unique_lock<std::mutex> lck{lockInputBufferModuleTwo};
   while( inputBufferInModuloTwo.size() != INPUT_BUFFER_MAX_SIZE )
   {
   	    std::cout<<"MODULE 1"<<std::endl;
   	    //std::cout<<"BUFFER size: "<< inputBufferInModuloTwo.size()<<std::endl;
   	    //std::cout<<"nbytes is: "<<nbytes <<std::endl;
        byteArrays[nbytes]= getRandomByte();
        nbytes++;
        if ((nbytes == BYTE_ARRAY_SIZE) && (inputBufferInModuloTwo.size() != INPUT_BUFFER_MAX_SIZE) )  
   	    {
   	      Data receivedData(byteArrays);
   	  	  receivedData.receivedDateTime=getTimeUTC();
   	  	  inputBufferInModuloTwo.push_back(receivedData);
          nbytes=0;
   	    }
   	}
   	if ( inputBufferInModuloTwo.size() == INPUT_BUFFER_MAX_SIZE ) {
   	    //std::cout<<"BUFFER IS FULL, WAIT FOR FREE "<<std::endl;
        std::this_thread::sleep_for (std::chrono::milliseconds(1000)); 
    }
  }

  */