#include "Addition.h"
#include<iomanip>
using namespace std;


Addition::Addition() {
	this->theAnswer = 0;
	this->userResponse = 0;

	randomize();
}

void Addition::randomize() {
	unsigned seed = time(0);
	srand(seed);
	int number1;
	this->num1 = (rand() % 10) + 1;
	this->num2 = (rand() % 10) + 1;
	this->theAnswer = this->num1 + this->num2;

}
bool Addition::checkAnswer() {
	if (this->userResponse == this->theAnswer) {
		return true;
	}
	else {
		return false;
	}
}
void Addition::validate(string str) {
	bool resultOK;
	string input;
	do {
		getline(cin, input);
		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				resultOK = false;
			}
		}
		if (input == "") {
			resultOK = false;
		}
		if (!resultOK) {
			cout << "Please enter a positive integer!" << endl;
		}
	} while (!resultOK);
	this->userResponse = atoi(input.c_str());

}

ostream &operator <<(ostream &strm, const Addition &obj) {
	strm << obj.num1 << " + " << obj.num2 << " = ?"
}
/*
ostream &operator <<(ostream &strm, const Date &obj) {
	strm << obj.names[obj.month - 1] << " " << obj.day << ". " << obj.year;
	return strm;
}
*/