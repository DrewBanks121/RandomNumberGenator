#include "UserInput.h"
#include <iostream>
#include <random>
#include <string>



UserInput::UserInput()
{
	UserNumber = 0.0;
	GeneratedNumb = 0.0;
	NumberOfGuesses = 0.0;
}

UserInput::~UserInput()
{
}

void UserInput::gameStart()
{
	std::cout << "Welcome to the amazing number guessing game" << std::endl;
	std::cout << "Please choose a number now between 0-100" << std::endl;
}

void UserInput::GenerateNumb()
{
	
	srand((unsigned)time(NULL));
	GeneratedNumb = rand() % 101;

}

void UserInput::GameRestart()
{
	std::cout << "Please choose a number now between 0-100" << std::endl;
	GenerateNumb();
	checkUserInput();
}

void UserInput::checkUserInput() {

	while (true) {
		std::cout << "Your number is: ";

		std::string input;
		std::cin >> input;

		bool isNumber = true;
		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				isNumber = false;
				break;
			}
		}

		if (!isNumber) {
			std::cout << "Please provide a number!" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}

		int number = stoi(input);

		if (number <= 0 || number >= 100) {
			std::cout << "That Number is not between 0-100 try again" << std::endl;
		}
		else if (number < GeneratedNumb) {
			std::cout << "Your Number is too low try again" << std::endl;
			NumberOfGuesses = NumberOfGuesses + 1;
		}
		else if (number > GeneratedNumb) {
			std::cout << "Your Number is too high try again" << std::endl;
			NumberOfGuesses = NumberOfGuesses + 1;
		}
		else {
			NumberOfGuesses = NumberOfGuesses + 1;
			std::cout << "GOOD JOB!!! YOU WIN!!!" << std::endl;
			std::cout << "It took you " << NumberOfGuesses << " Guesses" << std::endl;
			
			std::cout << "Would you like to play again? (Y/N)" << std::endl;
			std::string Yes_No;
			std::cin >> Yes_No;

			if (Yes_No == "Y" || Yes_No == "y") {
				system("CLS");
				GameRestart();
			}
			else
			{
				break;
			}

		}

		std::cin.clear();
		std::cin.ignore();
	}

}



double UserInput::outPutUserNumber()
{
	return 0.0;
}


