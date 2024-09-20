#include<map>
#include<array>
#include<vector>
#include<memory>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include"Observer.h"
#include"DbContext.h"

using namespace std;


int main(int argc, char ** argv)
{
    int sessionTokenId=3949549;
    std::cout<<"Designe Parttern Observer"<<std::endl; 
    Observer dbChanges(sessionTokenId);
    dbChanges.create();
    DbContext newDb("Mongo server", 5060, "*********", "oscar.avz.crespo@gmail.com", "nundelTech VPN");
    newDb.connect();
	return 0;
}