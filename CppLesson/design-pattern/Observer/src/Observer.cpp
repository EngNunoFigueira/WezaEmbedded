#include<iostream>
#include"Observer.h"

using namespace std;

Observer::Observer(){}
Observer::Observer(int &a)
:aa(a){}
void Observer::create(){ std::cout<<"Observer created sucess"<<std::endl; }
bool Observer::notify(){ return true; }
bool Observer::remove(){ return true; }
Observer::~Observer(){}
