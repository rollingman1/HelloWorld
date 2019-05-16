#include "myTime.h"

int main() {
	myTime t1;
	myTime t2(1, 2, 3);

	cout << "t의 시간정보 : " << t1.getTime() << endl;
	cout << "t2의 초 정보 : ";
	t2.printTime();

	return 0;
}
