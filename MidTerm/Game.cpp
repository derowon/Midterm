#include "Game.h"
#include<iomanip>
using namespace std;



Game::Game() {
	userName = "";
	totalWages = 0;
	totalCorrect = 0;
	totalWrong = 0;
}

void Game::splashScreen() {
	cout << "*****************************" << endl;
	cout << "*****************************" << endl;
	cout << "*****************************" << endl;
	cout << "*******              ********" << endl;
	cout << "*******The Math Game!********" << endl;
	cout << "*******By Won Dae Ro ********" << endl;
	cout << "*******              ********" << endl;
	cout << "*****************************" << endl;
	cout << "*****************************" << endl;
	cout << "*****************************" << endl;
	system("pause");
	/*
	string input;
	cout << "y/Y  to continue, any other char to exit" << endl;
	getline(cin, input);
	if (input.length() != 1) {
		return;
	}
	*/


}

void Game::menu() {
	cout << "******Choose a problem*******" << endl;
	cout << "*****************************" << endl;
	cout << "*****************************" << endl;
	cout << "*******              ********" << endl;
	cout << "*******  1.ADD       ********" << endl;
	cout << "*******  2.SUBSTRACT ********" << endl;
	cout << "*******  3.MULTIPLY  ********" << endl;
	cout << "*******  4.DIVIDE    ********" << endl;
	cout << "*******  5.STATS     ********" << endl;
	cout << "*******  n/N to quit ********" << endl;
	cout << "*******              ********" << endl;
	cout << "*****************************" << endl;
	cout << "*****************************" << endl;
	cout << "*****************************" << endl;

}

void Game::requestName() {
	string name;
	cout << "Please enter your name and press <ENTER> :" << endl;
	validate(name);
	this->userName = name;

	//Since there is no function to retrieveStarts I will retrieve after getting the name
	string nameInFile;
	this->inData.open((name + ".txt").c_str());
	if (this->inData.is_open()) {
		this->inData >> nameInFile;
		this->inData >> this->totalCorrect;
		this->inData >> this->totalWrong;
		this->inData >> this->totalWages;
	}
	this->inData.close();
}

void Game::validate(string & name) {
	bool resultOK = false;
	string userInput = "";
	do {
		resultOK = true;
		getline(cin, userInput);
		for (int i = 0; i < userInput.length(); i++) {
			if (isdigit(userInput[i])) {
				resultOK = false;
			}
			if (userInput[i] == ' ') {
				resultOK = false;
			}
		}
		if (userInput == "") {
			resultOK = false;
		}
		if (!resultOK) {
			cout << "Invalid entry, try again" << endl;
		}
	} while (!resultOK);
	name = userInput;
}

void Game::displayStats() {

	cout << "*************************************" << endl;
	cout << "*************************************" << endl;
	cout << "*************************************" << endl;
	cout << "*******                      ********" << endl;
	cout << "*******" << left << setw(22) << this->userName << "********" << endl;
	cout << "*******Total Earnings $" << setw(4) << fixed << setprecision(2) << this->totalWages << "  ********" << endl;
	cout << "*******Total Correct " << setw(4) << this->totalCorrect << "    ********" << endl;
	cout << "*******Total Incorrect " << setw(4) << this->totalWrong << "  ********" << endl;
	cout << "*******                      ********" << endl;
	cout << "*************************************" << endl;
	cout << "*************************************" << endl;
	cout << "*************************************" << endl;
}

void Game::saveStats() {
	this->outData.open((this->userName + ".txt").c_str());
	this->outData << this->userName << endl;
	this->outData << this->totalCorrect << endl;
	this->outData << this->totalWrong << endl;
	this->outData << fixed << setprecision(2) << this->totalWages << endl;
	this->outData.close();
}

void Game::updateStats(bool correct) {
	if (correct) {
		this->totalCorrect++;
		this->totalWages += 0.05;
	}
	else {
		this->totalWrong++;
		this->totalWages -= 0.03;
	}
}