#pragma once
#ifndef  myTime_h
#define myTime_h
#include <iostream>
#include <string>
using namespace std;

class myTime {
private:
	int hour, minute, second;
public:
	myTime();
	myTime(int, int, int);
	~myTime();
	string getTime();
	void printTime();
};

#endif // ! myTime_h
