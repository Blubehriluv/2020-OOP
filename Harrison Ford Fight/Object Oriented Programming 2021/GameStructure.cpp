#include <iostream>
#include "GameStructure.h"
#include "HanSolo.h"
#include "IndianaJones.h"
#include <cstdlib>

// The introduction to the program.
void Intro()
{
	std::cout << "Welcome to the Harrison Ford Fight!" << std::endl;
	std::cout << "Which Hollywood star will take home the victory!" << std::endl;
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

	HanSolo hanBoy("Han");
	hanBoy.SetHealth(250);
	hanBoy.GetHealth();
	hanBoy.JediDodge();
	hanBoy.DisplayCharacterStats();

	IndianaJones indBoy("Indy");
	indBoy.SetHealth(225);
	indBoy.GetHealth();
	indBoy.CrackWhip();
	indBoy.DisplayCharacterStats();
}