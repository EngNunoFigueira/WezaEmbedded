/*
Year:  2021
Autor: Nuno Figueira
Project: 
    This exercise was proposed during a C++ Test Skill Interview with Karat Software Engineer...
Description: 
    Given a vector with a list of strings, and an input string we need check if one of the words in the vector are part of the string.
Example: 
   for example, consider that the Vector is :words {"cato", "ax", "bbabythath", "maronacatdixes", "tewyolmfgax"}
Example: 
   And the string is eacrhThisString="percatomaselvi"...How we can see, one of the words of the VECTOR is "cato" and is include on the middle of the string.
Requirement: 
   Build a function that receive this two parameters and found if the input String contain any word of the vector...
My Solution: 
   First of all, the problem can be very trick... And during the interview, I try avoid develop a solution, in C++ 14
   that was implemented with BIG NOTATION n(O²)... 
   In that time my idea was that if I'm developing a code for a job interview, I need give a good solution... 
   And I spend the time looking for a good solution and avoid using a two cicles <for> inside a small function...
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<memory>
#include<array>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h> 


using namespace std;

std::string findTheWord(std::vector<std::string> &_words, std::string &searchThis)
{
    int caractersFounds=0, i=0;
    std::string wordFound;
    char caractersToSearch[40];
    char caractersOfCurrentWord[40];

   for( std::string &currentWord : _words )
   {

    std::string auxCurrentWord=currentWord;
    int getLengthOfStringToSearch = searchThis.length();
    strcpy(caractersToSearch, searchThis.c_str());
    strcpy(caractersOfCurrentWord, currentWord.c_str());
    std::cout<<"The words read from the vector is: "<<currentWord.c_str() <<"\n"<<std::endl;

   for(int i=0; i< getLengthOfStringToSearch; i++)
    {
      std::cout<<"SEARCHING FOR CARACTERS....\n"<<std::endl;
      if(caractersOfCurrentWord[caractersFounds] == caractersToSearch[i])
      {
         caractersFounds++;
         wordFound = wordFound + caractersToSearch[i];
         std::cout<<"Founded the caractrer "<<caractersToSearch[i] << "on position "<< i<<"\n"<<std::endl;
         if(caractersFounds>=2)
         {
             std::cout<<"CURRENT WORD IS  "<<auxCurrentWord<<" COMPARE IS "<< wordFound <<"\n"<<std::endl;
            if(wordFound == auxCurrentWord)
                return wordFound;
         }
      }
      else
      {
        wordFound="";
        caractersFounds=0;
      }

    }
   }

   return "not found";
}


int main(int argc, char **argv)
{

 std::string seacrhThisString="masdixeselvi";
 std::vector<std::string> words {"cato", "ax", "bbabythath", "dixes", "tewgax"};
 std::cout<<"\nGive a string we need found if this string exist on one of the words stored in a VECTOR...\n"<<std::endl;

  std::cout<<"\nThe String :...\n"<< findTheWord(words, seacrhThisString)<<std::endl;

 return 0;
}
