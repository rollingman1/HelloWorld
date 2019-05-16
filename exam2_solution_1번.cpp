#include <iostream>
#include <string>
using namespace std;

double dSum(double a, double b) { return a + b; }

double dSubt(double a, double b) { return a - b; }

double dMult(double a, double b) { return a * b; }

double dDiv(double a, double b) { return a / b; }

class Calculator {
private:
	string sOperator;
	double x, y;
	double(*func)(double, double);
public:
	void getInput() {
		cout << "(exit when input is 0 + 0)"<<endl<<"Input>>";
		cin >> sOperator;
		int i = 0;
		i = sOperator.find(" ");
		if (sOperator[i+1] == '+') {
			x = atof(sOperator.substr(0,i).c_str());
			y = atof(sOperator.substr(i + 3, sOperator.length() - (i + 3)).c_str());
			sOperator = "+";
		}
		else if (sOperator[i + 1] == '-') {
			x = atof(sOperator.substr(0, i).c_str());
			y = atof(sOperator.substr(i + 3, sOperator.length() - (i + 3)).c_str());
			sOperator = "-";
		}
		else if (sOperator[i + 1] == '*') {
			x = atof(sOperator.substr(0, i).c_str());
			y = atof(sOperator.substr(i + 3, sOperator.length() - (i + 3)).c_str());
			sOperator = "*";
		}
		else if (sOperator[i + 1] == '/') {
			x = atof(sOperator.substr(0, i).c_str());
			y = atof(sOperator.substr(i + 3, sOperator.length() - (i + 3)).c_str());
			sOperator = "/";
		}
	} 
	void selectFunc() {
		if (sOperator == "+") {
			func = dSum;
		}
		if (sOperator == "-") {
			func = dSubt;
		}
		if (sOperator == "*") {
			func = dMult;
		}
		if (sOperator == "/") {
			func = dDiv;
		}
	}
	void checkExit() {
		if (sOperator == "+"&&x == 0 && y == 0) {
			cout << "Exit the program..." << endl;
		}
	}
	void printOutput() {
		cout << "Output" << func(x, y) << endl << endl;
	}
	void run() {
		while (1) {
			getInput();
			checkExit();
			selectFunc();
			printOutput();
		}
	}
};
int main() {
	Calculator calc;
	calc.run();
	return 0;
}
