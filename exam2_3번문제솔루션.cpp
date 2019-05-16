#include <string>
#include <iostream>

using namespace std;

class Printer {
protected:
	string model, manufacture;
	int printedCount, availableCount;
public:
	Printer() {
		model = "";
		manufacture = "";
		availableCount = 0;
	}
	~Printer(){}
	virtual void print(int p) {}
	virtual void show() {}
};
class InkJet_P:public Printer {
	public:
		int availableInk;
		InkJet_P(string n, string m, int i, int j) {
			model = n;
			manufacture = m;
			availableCount = i;
			availableInk = j;
		}
		void show() override {
			cout << model << ", " << manufacture << ", 남은 종이" << availableCount << ", 남은 잉크" << availableInk << endl;
		}
		void print(int p) {
			if (availableCount - p >= 0 && availableInk- p >= 0) {
				availableCount -= p;
				availableInk -= p;

				cout << "프린트 하였습니다" << endl;
			}
			else if (availableInk - p < 0)cout << "잉크 부족하여 프린트할 수 없습니다." << endl;
			else if (availableCount - p < 0) cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		}

};
class Laser_P:public Printer{
private:
	int availableToner;
public:

	Laser_P(string n, string m, int i, int j) {
		model = n;
		manufacture = m;
		availableCount = i;
		availableToner = j;
	}
	void setLaser(string n, string m, int i, int j) {
		model = n;
		manufacture = m;
		availableCount = i;
		availableToner = j;
	}
	void show() override {
		cout << model << ", " << manufacture << ", 남은 종이" << availableCount << ", 남은 토너" << availableToner << endl;
	}
	void print(int p) {
		if (availableCount - p >= 0 && availableToner - p >= 0) {
			availableCount -= p;
			availableToner -= p;

			cout << "프린트 하였습니다" << endl;
		}
		else if (availableToner - p < 0)cout << "토너 부족 하여 프린트할 수 없습니다." << endl;
		else if (availableCount - p < 0) cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
};
int main() {

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	Printer *pi = new InkJet_P("Medel III", "HP", 5, 10);
	
	Laser_P pl("Medal LLL", "신도리코", 10, 20);

	bool b = 1;
	int w;
	int c;
	string a;
	while (b) {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력";
		cin >> c;
		if (c == 1) {
			cin >> w;
			(*pi).print(w);
			
		}
		if (c == 2) {
			cin >> w;
			pl.print(w);
		}

		pi->show();
		pl.show();

		cout << "계속 프린트 하시겠습니까(y/n)";
		cin >> a;
		if (a == "y" || a == "Y") b = 1;
		else if (a == "N" || a == "n") b = 0;
	}





}
