#include <string>
#include <iostream>
#include "GameStructure.h"

//int randomNum;

// The introduction to the program.
void Intro()
{
	std::cout << "Welcome to the Harrison Ford Fight!" << std::endl;
	std::cout << "Which Hollywood star will take home the victory!" << std::endl;

	std::cout << "Random number 1: ";
}

// Initiates a random roll producing a number between 1 and 100.
int RandomRoll()
{
	int randomNum = rand() % 100 + 1;
	std::cout << "The 100 sided dice falls to " << randomNum << std::endl;;
	return randomNum;
}

// Main function to start program.
int main()
{
	
	Intro();
	RandomRoll();
	RandomRoll();
	
}