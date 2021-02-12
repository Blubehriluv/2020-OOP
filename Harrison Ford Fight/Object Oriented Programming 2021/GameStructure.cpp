#include <iostream>
#include "GameStructure.h"
#include "HanSolo.h"
#include "IndianaJones.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>

bool isPlayerTurn = false;
bool isIndy = false;
bool isHan = false;

int maxDamageNum = 100;
int coinFlipNum = 2;
int aiFightChoice = 2;

// The introduction to the program.
void Intro()
{
	std::cout << "Welcome to the Harrison Ford Fight!" << std::endl;
	std::cout << "Prepare for the battle of Han Solo vs. Indiana Jones!" << std::endl;
	std::cout << "Which Hollywood star will take home the victory!" << std::endl;
	std::cout << std::endl;
}

// Prompts the user to choose a character and make them fight.
void ChooseCharacter()
{
	std::string characterChoice;
	std::cout << "Please choose your character!" << std::endl;
	std::cout << "'Han' or 'Indy'" << std::endl;
	std::cin >> characterChoice;
	// This changes the input to uppercase so that the program can accept multiple answers.
	std::transform(characterChoice.begin(), characterChoice.end(), characterChoice.begin(), ::toupper);

	if (characterChoice == "HAN")
	{
		isHan = true;
		std::cout << "You have chosen Han Solo!" << std::endl;
	}
	else if (characterChoice == "INDY")
	{
		isIndy = true;
		std::cout << "You have chosen Indiana Jones!" << std::endl;
	}
	else
	{
		std::cout << "Please use the given names and correct spelling!" << std::endl;
		ChooseCharacter();
	}
}

// This will initialize the player's character and the AI character
void CharacterInitialize()
{
	std::string characterGivenName;
	std::string indyDefaultName = "Indiana Jones";
	std::string hanDefaultName = "Han Solo";
	std::cout << "Please name your character!" << std::endl;

	// Receives player input and assigns character names.
	std::cin >> characterGivenName;
	if (isHan)
	{
		HanSolo hansolo(characterGivenName);
		IndianaJones indianajones(indyDefaultName);
	}
	else if (isIndy)
	{
		HanSolo hansolo(hanDefaultName);
		IndianaJones indianajones(characterGivenName);
	}
	std::cout << std::endl;
	std::cout << "The fight begins!" << std::endl;
}

void DamageNumber()
{
	std::cout << rand() % maxDamageNum << std::endl;
}

void EnemyTurn()
{
	std::cout << std::endl;
	std::cout << "Enemy Turn" << std::endl;
	
	
}

// Initiates a random roll producing a number between 1 and 100.
int PlayerTurn()
{
	std::string fightOption;
	std::cout << "'Attack' or 'Dodge'?" << std::endl;
	std::cin >> fightOption;

	std::transform(fightOption.begin(), fightOption.end(), fightOption.begin(), ::toupper);

	int randomNum = rand() % 100 + 1;
	std::cout << "The 100 sided dice falls to " << randomNum << std::endl;;
	return randomNum;
	
	if (fightOption == "ATTACK")
	{
		
	}
	else if (fightOption == "DODGE")
	{
		
	}
	else
	{
		
	}
}

void Fight(bool whosTurn)
{
	// True is player's turn
	if (whosTurn == true)
	{
		PlayerTurn();
	}
	// False is AI turn
	else
	{
		EnemyTurn();
	}	
}

// The program decides who goes first with a coin flip.
// 1 is heads, 2 is tails.
void CoinFlip()
{
	std::string coinChoice;
	int coinFlipHold = rand() % coinFlipNum + 1;
	std::cout << "Let's see who goes first!" << std::endl;
	std::cout << "'Heads' or 'Tails'" << std::endl;
	std::cin >> coinChoice;
	std::transform(coinChoice.begin(), coinChoice.end(), coinChoice.begin(), ::toupper);
	
	// This is if the PLAYER chooses heads.
	if (coinChoice == "HEADS")
	{
		if (coinFlipHold == 1)
		{
			std::cout << "THE COIN REVEALS HEADS." << std::endl;
			std::cout << "You go first." << std::endl;
			isPlayerTurn = true;
		}
		else if(coinFlipHold == 2)
		{
			std::cout << "THE COIN REVEALS TAILS." << std::endl;
			std::cout << "You go second." << std::endl;
			isPlayerTurn = false;
		}
		Fight(isPlayerTurn);
	}
	// This is if the PLAYER chooses tails.
	else if(coinChoice == "TAILS")
	{
		if (coinFlipHold == 1)
		{
			std::cout << "THE COIN REVEALS HEADS." << std::endl;
			std::cout << "You go second." << std::endl;
			isPlayerTurn = false;
		}
		else if (coinFlipHold == 2)
		{
			std::cout << "THE COIN REVEALS TAILS." << std::endl;
			std::cout << "You go first." << std::endl;
			isPlayerTurn = true;
		}
		Fight(isPlayerTurn);
	}
	// This is if the player input doesn't work.
	else
	{
		std::cout << "Please choose a side and spell it correctly" << std::endl;
		CoinFlip();
	}
}

// Main function to start program.
int main()
{
	srand(time(0));

	Intro();

	ChooseCharacter();
	
	CharacterInitialize();

	CoinFlip();

	Fight();

	
	
	// Create player turn
	// Create enemy turn
}