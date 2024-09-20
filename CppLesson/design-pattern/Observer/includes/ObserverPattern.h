#ifndef OBSERVERPATTERN_H
#define OBSERVERPATTERN_H

#include<iostream>
#include"DbContext.h"
#include"ObserverPattern.h"

class ObserverPattern 
{
public:
   ObserverPattern();
   virtual ~ObserverPattern();
   ObserverPattern(DbContext  * _db);
   virtual void Update() = 0;
protected:
   DbContext *getDbConnections();  
private:
  DbContext *db;
};
#endif 