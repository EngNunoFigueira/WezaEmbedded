#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <ctime> 
#include <thread>
#include <string> 
#include <time.h>  
#include <iomanip>
#include <chrono>
#include <mutex> 
#include <algorithm>
#include <memory>
#include <vector>
#include <type_traits>

#include"RandomByteGenerator.h"

   RandomByteGenerator::RandomByteGenerator(){}
   RandomByteGenerator:: ~ RandomByteGenerator(){}
   int RandomByteGenerator::RandomGenerator()
   {
      unsigned int getRandomValue{};
      static bool isTheFirstValue{true};
      std::srand(static_cast<unsigned int>(std::time(nullptr)));
      do{
          getRandomValue = static_cast<unsigned int>(RAND_MAX/std::rand());
      }while( getRandomValue > 255 );
   
     return getRandomValue;
   }
   const unsigned char RandomByteGenerator::ByteGeneratorUsingIntegerReference()
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
	          previousValue= RandomGenerator();
	          if( auxValue !=previousValue )
	              break;
        }
      }
      isTheFirstValue=false;
      return CHAR_BYTE_MAP[previousValue];
   }
   const unsigned char RandomByteGenerator::getRandomByte()
   { 
      return ByteGeneratorUsingIntegerReference();
   }
   std::string RandomByteGenerator::getTimeUTC()
   {
      char timeUTC[200];
      time_t t;
      struct tm *tmp;
      const char* fmt = "%a, %d %b %y %T %z";
      t = time(NULL);
      tmp = gmtime(&t);
      if (tmp == NULL) 
      {
        perror("gmtime error");
        exit(EXIT_FAILURE);
      }
      if (strftime(timeUTC, sizeof(timeUTC), fmt, tmp) == 0) 
      { 
        fprintf(stderr, "strftime returned 0");
        exit(EXIT_FAILURE); 
      } 

      return (timeUTC);
   } 
   unsigned char RandomByteGenerator::TestData(int ArrayOrder, const int byteIndex)
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
