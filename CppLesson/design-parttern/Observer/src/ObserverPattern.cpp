#include<iostream>
//#include"DbContext.h"
#include"ObserverPattern.h"

using namespace std;

ObserverPattern::ObserverPattern(){}
ObserverPattern::~ObserverPattern(){} 
ObserverPattern::ObserverPattern(DbContext * _db)
:db(_db)
{

}
DbContext* ObserverPattern::getDbConnections()
{
	return db;
}
