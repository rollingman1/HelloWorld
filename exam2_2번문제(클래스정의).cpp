#include "myTime.h"

myTime::myTime() {
	hour = 0;
	minute = 0;
	second = 0;
}

myTime::myTime(int h , int m , int s ) {
	hour = h;
	minute = m;
	second = s;
}
myTime::~myTime()
{}
string myTime::getTime() {
	string s = to_string(hour) + "시 " + to_string(minute) + "분 " + to_string(second) + "초 ";
	return s;
}
void myTime::printTime() {
	cout << hour * 3600 + minute * 60 + second << "초" << endl;
}
