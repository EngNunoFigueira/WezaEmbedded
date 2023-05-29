/*
CURLcode curl_easy_setopt(CURL *handle, CURLoption option, parameter);

curl_easy_setopt is used to tell libcurl how to behave. 
By setting the appropriate options, the application can change libcurl's behavior.
All options are set with an option followed by a parameter. 

That parameter can be a long, a function pointer, an object pointer or a curl_off_t, depending on what the specific option expects.

Read this manual carefully as bad input values may cause libcurl to behave badly! You can only set one option in each function call. A typical 
application uses many curl_easy_setopt calls in the setup phase.

Options set with this function call are valid for all forthcoming transfers performed using this handle. The options are not in any way reset between
transfers, so if you want subsequent transfers with different options, you must change them between the transfers. You can optionally reset all options
back to internal default with curl_easy_reset.

Strings passed to libcurl as 'char *' arguments, are copied by the library; thus the string storage associated to the pointer argument may be overwritten
after curl_easy_setopt returns. The only exception to this rule is really CURLOPT_POSTFIELDS, but the alternative that copies the string 
CURLOPT_COPYPOSTFIELDS has some usage characteristics you need to read up on. This function does not accept input strings longer than 
CURL_MAX_INPUT_LENGTH (8 MB).

The order in which the options are set does not matter.
Before version 7.17.0, strings were not copied. Instead the user was forced
keep them available until libcurl no longer needed them. The handle is the return code from a curl_easy_init or curl_easy_duphandle call.
*/

#include <stddef.h>
#include <iostream>
#include <string>
#include <curl/curl.h>
using namespace std;

struct apiJsonData
{
  std::string userId={};
  int counter{};
  std::string code{0};
  std::string status{};
  std::string serviceType{};
  std::string openTime{};
  std::string closeTime{};
};

enum jsonTags
   {
   	 ticketId=24,
   	 ticketCode=4,
   	 ticketStatus=6,
   	 ticketServiceType=7,
   	 ticketOpenTime=12,
   	 ticketCloseTime=12
   };

bool apiGetNotFound(const std::string & get)
{
    if(get.length()>0) { return true; } 
    else { return false; }  	
}

void serializeJsonData (const string & apiResponse)
{
  // "message":[{"_id":"5e5d96090369d74da90ce101","counter":2,"code":"AR02","status":"waiting","serviceType":"ATT Geral","openTime":"102303202020","closeTime":"102403202020"},
                     // 5e5d96090369d74da90ce101

   const int firstCaractersBegin{11};
   const int defaultCaractersToRemove{5};

   struct apiJsonData getData;
   getData.userId       = apiResponse.substr(20,24);
   getData.counter      = std::stoi(apiResponse.substr(56,1)); // need an arranjement to detect the correct nber of caracters to read
   getData.code         = apiResponse.substr(66,4);
   getData.status       = apiResponse.substr(82,7);
   getData.serviceType  = apiResponse.substr(106,9);
   getData.openTime     = apiResponse.substr(129,12);
   getData.closeTime    = apiResponse.substr(156,12);

   std::string testData    = apiResponse.substr(180,23);
 
   std::cout <<"The ticket Id           is: "<<getData.userId       <<std::endl;
   std::cout <<"The ticket Counter      is: "<<getData.counter      <<std::endl;
   std::cout <<"The ticket Code         is: "<<getData.code         <<std::endl;
   std::cout <<"The ticket Status       is: "<<getData.status       <<std::endl;
   std::cout <<"The ticket ServiceType  is: "<<getData.serviceType  <<std::endl;
   std::cout <<"The ticket openTime     is: "<<getData.openTime     <<std::endl;
   std::cout <<"The ticket closeTime    is: "<<getData.closeTime    <<std::endl;
   std::cout <<"The ticket closeTime    is: "<<testData             <<std::endl;

}

 struct car { char *make; char *model; int year; }; // declares the struct type
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	std::cout <<"The CALLBACK function was called..."<< std::endl;
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    //std::cout <<"The size valus is: "<<size * size <<std::endl;
    //std::cout <<"The nmemb valus is: "<<size * nmemb <<std::endl;
    return size * nmemb;
}

int main(void)
{
  CURL *curl;
  const std::string stringUrl="192.168.250.137:3000/register/";
  // wchar_t w this is the correct form to write a char to C. 
  // but this code is compled to modern C++ 17 and the functions 
  // CURL a just a C-style. So in that case we need use a char like 
  // in C-Style and not use the modern C++17.
  const char *url = stringUrl.c_str(); 
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if(apiGetNotFound(readBuffer))
      std::cout << readBuffer << std::endl;
      serializeJsonData(readBuffer);
  }
  else 
  {
  	std::cout <<"The CURL failed"<< std::endl;
  }

  return 0;
}