#include <iostream>
#include <string>

using namespace std;

//asking the user the question and getting guess
int getUsersGuess(int randomNum, int rangeLo, int rangeHi) {
	int guess;
	cout << "Guess a number between " << rangeLo << " and " << rangeHi << endl;
	cin >> guess;
	if (guess < randomNum)
		cout << "Too low!!\n";
	else if (guess > randomNum)
		cout << "Too high!!\n";
	else
		return guess;
	return guess;
}

//getting the number of guesses by passing it as a reference
void getNumberOfGuesses(int& numberOfGuesses,string dogName) {
	int guess = 200;
	int rangeLo, rangeHi;
	int randomNum = 0;
	int range = 0;
	
	//EXTRA CREDIT 1
	cout << "Enter a range of numbers to guess between. (Low-High)\n";
	cin >> rangeLo >> rangeHi;
	range = rangeHi - rangeLo;
	randomNum = rand()%range + rangeLo;

	//game starts
	system("cls");
	cout << "Let's play a Number Guessing Game!\n";

	while(guess != randomNum) {
		guess = getUsersGuess(randomNum, rangeLo, rangeHi);
		numberOfGuesses++;
	}
	cout << "You Win!!\n";
	if (dogName == "wrong") {
		cout << "You should really consider getting a dog as a pet...anyways, ";
	}
	else
		cout << "WOAH! I think i heard " << dogName << " say FINALLY!\n";
}

//Displays users results and insults/compliments accordingly
void displayUsersResults(int numberOfGuesses) {
	cout << "It took you " << numberOfGuesses << " guesses.\n";
	
	switch (numberOfGuesses) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4: cout << "Amazing! Or was it luck?\n";
		break;
	case 5:;
	case 6: cout << "That's a very good score...\n";
		break;
	case 7:;
	case 8: cout << "That's pretty good but you can do better...\n";
		break;
	case 9:;
	case 10: cout << "Not too shabby, but not too good either...\n";
		break; 
	default: cout << "What a terrible score!...\n";
	}
}

//asks user if he/she has pet...if dog, gets name and returns it.
string getDogName() {
	string dogBreed;
	string dogName;
	char answer;
		cout << "Before we begin the game, I have a quick question...Do you have a pet?(y/n): ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y') {
			cout << "Alright, now do you have a dog?(y/n): ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y') {
				cout << "Now what's his/her name? ";
				cin >> dogName;
				cout << "Wow, " << dogName << " is a great name for a dog!\n";
				return dogName;
			}
			else {
				cout << "Well, carry on, wish you best of luck on the game!";
				dogName = "wrong";
				return dogName;
			}
		}

		else {
			cout << "Bummer, alrighty then, wish you best of luck on the game.\n";
			dogName = "wrong";
			return dogName;
		}

}

int main() {
	int numberOfGuesses = 0;

	string dogName = getDogName();
	
	getNumberOfGuesses(numberOfGuesses, dogName);

	displayUsersResults(numberOfGuesses);
	return 0;
}