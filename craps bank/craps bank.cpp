
#include "pch.h"
#include <iostream>
#include<cstdlib>
#include<iomanip>
#include<random>
#include<ctime>

using namespace std; 

bool craps();
int RollADice();


int main() {

	int balance = 1000;
	int wager = 0;

	cout<<"Program will simulate rolling 2 die"<<endl;
	cout << "If the sum of your roll is 7 or 11 you win" << endl;
	cout << "If the sum is 2, 3, or 12 you lose" << endl;
	cout << "Any other sum will become your 'point'" << endl;
	cout << "If you roll your point before you roll a 7, you win. If not, you lose" << endl;
	cout << "You will start with 1000 in the bank. Goodluck!" << endl << endl;


	while (balance > 0) {

		while (true) {

			cout << "Enter your wager" << endl;
			cin >> wager;

			if (wager > balance)
				cout << "You dont have that much money. Enter a wager less than " << balance << endl;

			else
				break;
		}

		if (craps()) {

			balance += wager;

			if (rand() % 2)

				cout << "nice try ?  " << endl << endl;

			else
				cout << "dont forget. blowing on the dice WILL continue to win you games " << endl << endl;

		}
		else {
			balance -= wager;

			if (rand() % 2) 
			cout << "pressures on." << endl << endl;

			else
				cout << "are you here to be responsible or are you here to give us your money i mean have fun??" << endl << endl; 


		}

		cout << "your balance is: " << balance << endl;
	}

	cout << "Some people just cant handle vegas" << endl;

	return 0;

}


bool craps() {

	srand(static_cast<unsigned int>(time(0))); // will randomize the result of function 

	enum class Status { W, L, C };		// status is the name of the class and the constants are win, lose, or continue
	Status gameStatus;					// define variable gameStatus as the either constants in the class

	int sum = RollADice();				// define integer sum as the value you get when you call function RollADice

	int point = 0;						// initialize your point (to be use in the default case of switch) 

	switch (sum) {						// takes value of sum and compares to the defined cases (7,11 win, 2,13,12, lose, etc)

	case 7:
	case 11:

		gameStatus = Status::W;
		break;

	case 2:
	case 3:
	case 12:

		gameStatus = Status::L;
		break;

	default:
		gameStatus = Status::C;
		point = sum;					 // if you dont win or lose on the first round, sum of your roll becomes your point
		cout << "your point is: " << point << endl;
	}

	while (gameStatus == Status::C) {

		sum = RollADice();				 // roll dice again

		if (sum == point)
			gameStatus = Status::W;

		else if (sum == 7)
			gameStatus = Status::L;

		else
			gameStatus = Status::C;
	}

	if (gameStatus == Status::W)
		return true;


	else
		return false;

}

int RollADice() {   

	int dice1 = 1 + rand() % 6; // picks random number between 1 and 6
	int dice2 = 1 + rand() % 6;
	int sum = dice1 + dice2;


	cout << "You rolled a " << dice1 << "+ " << dice2 << "= " << sum << endl;

	return sum;
}

