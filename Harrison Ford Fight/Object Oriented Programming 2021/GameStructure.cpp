#include <iostream>
#include "GameStructure.h"
#include "HanSolo.h"
#include "IndianaJones.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>

HanSolo hansolo("");
IndianaJones indianajones("");

bool playerGoesFirst = false;
bool isIndy = false;
bool isHan = false;

bool playerTurnTaken = false;
bool enemyTurnTaken = false;

int maxDamageNum = 100;
int coinFlipNum = 2;

int aiFightChoiceMax = 2;
int attackCritChance;
int attackChance;
int critChance;
int dodgeChance;

int turnOutcome;
int enemyTurnOutcome;
int playerTurnOutcome;

int hanHealth = 400;
int indyHealth = 400;
int attackDamage = 25;

std::string characterGivenName;
std::string indyDefaultName = "Indiana Jones";
std::string hanDefaultName = "Han Solo";

std::string fightOption;
int aiFightChoice;

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
	std::cout << "Please name your character!" << std::endl;
	
	// Receives player input and assigns character names.
	std::cin >> characterGivenName;
	if (isHan)
	{
		hansolo = characterGivenName;
		indianajones = indyDefaultName;
	}
	else if (isIndy)
	{
		hansolo = hanDefaultName;
		indianajones = characterGivenName;
	}
	hansolo.SetHealth(hanHealth);
	indianajones.SetHealth(indyHealth);
	std::cout << std::endl;
	std::cout << "The fight begins!" << std::endl;
}



void Fight(bool whosTurn);

void DiceRoll(int rollFor)
{
	//std::cout << rand() % maxDamageNum << std::endl;
	switch (rollFor)
	{
		// Chance for the current player to get a crit on their attack
		case 1:
			attackCritChance = rand() % 10 + 1;
			std::cout << "The 10 sided die produces a " << attackCritChance << std::endl;
			if (attackCritChance <= 3)
			{
				std::cout << "No crit." << std::endl;
				DiceRoll(2);
			}
			else if (attackCritChance >= 4)
			{
				std::cout << "Possible to crit!" << std::endl;
				DiceRoll(3);
			}
			break;
		// WITHOUT CRIT Chance for player to attack and miss
		case 2:
			attackChance = rand() % 10 + 1;
			std::cout << "The 10 sided die produces a " << attackChance << std::endl;
			if (attackChance <= 2)
			{
				std::cout << "Unlucky, the attack missed." << std::endl;
				turnOutcome = attackDamage;
			}
			else if (attackChance >= 3)
			{
				std::cout << "Hit for 25 damage." << std::endl;
				turnOutcome = attackDamage;
			}
			break;
		// WITH CRIT Chance for player to attack and miss or hit for without crit
		case 3:
			critChance = rand() % 10 + 1;
			std::cout << "The 10 sided die produces a " << critChance << std::endl;
			if (critChance == 1)
			{
				std::cout << "Crit fell." << std::endl;
				std::cout << "Hit for 25 damage." << std::endl;
				turnOutcome = attackDamage;
			}
			else if (critChance >= 2 && critChance <= 5)
			{
				std::cout << "Unlucky, the attack missed." << std::endl;
				turnOutcome = 0;
			}
			else if (critChance >= 6)
			{
				int critValue = 0;
				switch(critChance)
				{
				case 6:
					critValue = 20;
					break;
				case 7:
					critValue = 40;
					break;
				case 8:
					critValue = 60;
					break;
				case 9:
					critValue = 80;
					break;
				case 10:
					critValue = 100;
					break;
				}
				std::cout << "Nice, crit for " << critValue << "% more damage!" << std::endl;
				turnOutcome = ((attackDamage * critValue) / 100) + attackDamage;
			}
			break;
		// Chance for current player to fail dodge, negate 75% of damage, or all damage
		case 4:
			dodgeChance = rand() % 10 + 1;
			std::cout << "The 10 sided die produces a " << dodgeChance << std::endl;
			if (dodgeChance <= 2)
			{
				std::cout << "Dodge failed, full damage taken." << std::endl;
				turnOutcome = 0;
			}
			if (dodgeChance >= 3 && dodgeChance <= 7)
			{
				std::cout << "Success, 75% damage negated." << std::endl;
				turnOutcome = 75;
			}
			else if (dodgeChance >= 8)
			{
				std::cout << "WOW! 100% of damage negated!" << std::endl;
				turnOutcome = 100;
			}
			break;
	}	
}

void EnemyTurn()
{
	std::cout << std::endl;
	std::cout << "~ ~ ~ Enemy Turn ~ ~ ~" << std::endl;

	aiFightChoice = rand() % aiFightChoiceMax + 1;

	// For the AI to be HAN SOLO
	if (isIndy)
	{
		// They attack
		if (aiFightChoice == 1)
		{
			hansolo.Attack();
			DiceRoll(1);
			enemyTurnOutcome = turnOutcome;
		}
		// They dodge
		else if (aiFightChoice == 2)
		{
			hansolo.JediDodge();
			DiceRoll(4);
			enemyTurnOutcome = turnOutcome;
		}
	}
	// For the AI to be INDIANA
	if (isHan)
	{
		// They attack
		if (aiFightChoice == 1)
		{
			indianajones.Attack();
			DiceRoll(1);
			enemyTurnOutcome = turnOutcome;
		}
		// They dodge
		else if (aiFightChoice == 2)
		{
			indianajones.CrackWhip();
			DiceRoll(4);
			enemyTurnOutcome = turnOutcome;
		}
	}
	enemyTurnTaken = true;
	Fight(playerGoesFirst);
}

// Initiates a random roll producing a number between 1 and 100.
void PlayerTurn()
{
	std::cout << std::endl;
	std::cout << "~ ~ ~ Player Turn ~ ~ ~" << std::endl;
	
	std::cout << "'Attack' or 'Dodge'?" << std::endl;
	std::cin >> fightOption;

	std::transform(fightOption.begin(), fightOption.end(), fightOption.begin(), ::toupper);

	if (isIndy)
	{
		// They attack
		if (fightOption == "ATTACK")
		{
			indianajones.Attack();
			DiceRoll(1);
			playerTurnOutcome = turnOutcome;
		}
		// They dodge
		else if (fightOption == "DODGE")
		{
			indianajones.CrackWhip();
			DiceRoll(4);
			playerTurnOutcome = turnOutcome;
		}
	}
	// For the AI to be INDIANA
	if (isHan)
	{
		// They attack
		if (fightOption == "ATTACK")
		{
			hansolo.Attack();
			DiceRoll(1);
			playerTurnOutcome = turnOutcome;
		}
		// They dodge
		else if (fightOption == "DODGE")
		{
			hansolo.JediDodge();
			DiceRoll(4);
			playerTurnOutcome = turnOutcome;
		}
	}
	playerTurnTaken = true;
	Fight(playerGoesFirst);
}

void EndRound(int player, int enemy)
{
	std::cout << std::endl;
	std::cout << "~ ~ ~ Round Concluded ~ ~ ~" << std::endl;

	if (isIndy)
	{
		if (fightOption == "ATTACK")
		{
			std::cout << "The player wanted to attack." << std::endl;
			if (player == 0)
			{
				std::cout << "Shame, they missed." << std::endl;
			}
			else if (player != 0)
			{
				std::cout << characterGivenName << " attacked for " << player << " damage." << std::endl;
				if (aiFightChoice == 2)
				{
					std::cout << "The enemy attempted to dodge." << std::endl;
					if (enemy == 0)
					{
						std::cout << "They took full damage" << std::endl;
						hansolo.HSHurt();
						hanHealth -= player;
						hansolo.SetHealth(hanHealth);
					}
					else if (enemy == 75)
					{
						std::cout << "The enemy negated 25% of the damage dealt!" << std::endl;
						hansolo.HSHurt();
						hanHealth -= ((player * 75)) / 100;
						hansolo.SetHealth(hanHealth);
					}
					else if (enemy == 100)
					{
						std::cout << "The enemy took no damage!" << std::endl;
					}
				}
				
				else if (aiFightChoice == 1)
				{
					std::cout << hanDefaultName << " took full damage." << std::endl;
					hansolo.HSHurt();
					hansolo.SetHealth(hanHealth - player);
					std::cout << "The enemy wanted to attack for " << enemy << " damage." << std::endl;

					std::cout << characterGivenName << " took full damage." << std::endl;
					indianajones.IJHurt();
					indianajones.SetHealth(indyHealth - enemy);
				}
			}
		}
		if (fightOption == "DODGE")
		{
			if (aiFightChoice == 2)
			{
				std::cout << "Stalemate.  Nobody decided to fight." << std::endl;
			}
			else if (aiFightChoice == 1)
			{
				std::cout << "The player attempted to dodge." << std::endl;
				if (player == 0)
				{
					std::cout << "They took full damage" << std::endl;
					indianajones.IJHurt();
					indyHealth -= enemy;
					indianajones.SetHealth(indyHealth);
				}
				else if (player == 75)
				{
					std::cout << "The player negated 25% of the damage dealt!" << std::endl;
					indianajones.IJHurt();
					indyHealth -= ((enemy * 75)) / 100;
					indianajones.SetHealth(indyHealth);
				}
				else if (player == 100)
				{
					std::cout << "The player took no damage!" << std::endl;
				}
			}			
		}
	}
	else if (isHan)
	{
		if (fightOption == "ATTACK")
		{
			std::cout << "The player wanted to attack." << std::endl;
			if (playerTurnOutcome == 0)
			{
				std::cout << "Shame, they missed." << std::endl;
			}
			else
			{
				std::cout << characterGivenName << " attacked for " << playerTurnOutcome << " damage." << std::endl;
				if (aiFightChoice == 2)
				{
					std::cout << "The enemy attempted to dodge." << std::endl;
					if (enemyTurnOutcome == 0)
					{
						std::cout << "They took full damage" << std::endl;
						indianajones.IJHurt();
						indyHealth -= enemyTurnOutcome;
						indianajones.SetHealth(indyHealth);
					}
					else if (enemyTurnOutcome == 75)
					{
						std::cout << "The enemy negated 25% of the damage dealt!" << std::endl;
						indianajones.IJHurt();
						indyHealth -= ((playerTurnOutcome * 75)) / 100;
						indianajones.SetHealth(indyHealth);
					}
					else if (enemyTurnOutcome == 100)
					{
						std::cout << "The enemy took no damage!" << std::endl;
					}
				}

				else if (aiFightChoice == 1)
				{
					std::cout << indyDefaultName << " took full damage." << std::endl;
					indyHealth -= player;
					indianajones.IJHurt();
					indianajones.SetHealth(indyHealth);
					std::cout << "The enemy wanted to attack for " << enemy << " damage." << std::endl;

					std::cout << characterGivenName << " took full damage." << std::endl;
					hansolo.HSHurt();
					hansolo.SetHealth(hanHealth - enemy);
				}
			}
		}
		if (fightOption == "DODGE")
		{
			if (aiFightChoice == 2)
			{
				std::cout << "Stalemate.  Nobody decided to fight." << std::endl;
			}
			else if (aiFightChoice == 1)
			{
				std::cout << "The player attempted to dodge." << std::endl;
				if (playerTurnOutcome == 0)
				{
					std::cout << "They took full damage" << std::endl;
					hansolo.HSHurt();
					hanHealth -= enemyTurnOutcome;
					hansolo.SetHealth(hanHealth);
				}
				else if (playerTurnOutcome == 75)
				{
					std::cout << "The player negated 25% of the damage dealt!" << std::endl;
					hansolo.HSHurt();
					hanHealth -= ((enemyTurnOutcome * 75)) / 100;
					hansolo.SetHealth(hanHealth);
				}
				else if (playerTurnOutcome == 100)
				{
					std::cout << "The player took no damage!" << std::endl;
				}
			}
		}
	}
	indianajones.GetHealth();
	hansolo.GetHealth();
	
	playerTurnTaken = false;
	enemyTurnTaken = false;
}

void Fight(bool whosTurn)
{
	// The round can end.
	if (playerTurnTaken == true && enemyTurnTaken == true)
	{
		EndRound(playerTurnOutcome, enemyTurnOutcome);
	}
	// It's TRUE that Player goes FIRST.
	if (whosTurn == true)
	{
		if (playerTurnTaken == false && enemyTurnTaken == false)
		{
			std::cout << "The Player is taking their turn first." << std::endl;
			PlayerTurn();
		}
		else if (playerTurnTaken == true && enemyTurnTaken == false)
		{
			std::cout << "The Enemy is taking their turn second." << std::endl;
			EnemyTurn();
		}
	}
	// It's FALSE that Player goes FIRST.
	if (whosTurn == false)
	{
		if (enemyTurnTaken == false && playerTurnTaken == false)
		{
			std::cout << "The Enemy is taking their turn first." << std::endl;
			EnemyTurn();
		}
		if (enemyTurnTaken == true && playerTurnTaken == false)
		{
			std::cout << "The Player is taking their turn second." << std::endl;
			PlayerTurn();
		}
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
			playerGoesFirst = true;
		}
		else if(coinFlipHold == 2)
		{
			std::cout << "THE COIN REVEALS TAILS." << std::endl;
			std::cout << "You go second." << std::endl;
			playerGoesFirst = false;
		}
		Fight(playerGoesFirst);
	}
	// This is if the PLAYER chooses tails.
	else if(coinChoice == "TAILS")
	{
		if (coinFlipHold == 1)
		{
			std::cout << "THE COIN REVEALS HEADS." << std::endl;
			std::cout << "You go second." << std::endl;
			playerGoesFirst = false;
		}
		else if (coinFlipHold == 2)
		{
			std::cout << "THE COIN REVEALS TAILS." << std::endl;
			std::cout << "You go first." << std::endl;
			playerGoesFirst = true;
		}
		Fight(playerGoesFirst);
	}
	// This is if the player input doesn't work.
	else
	{
		std::cout << "Please choose a side and spell it correctly" << std::endl;
		CoinFlip();
	}
}

void Conclude()
{
	std::cout << "done" << std::endl;
}

// Main function to start program.
int main()
{
	srand(time(0));

	Intro();

	ChooseCharacter();
	
	CharacterInitialize();

	CoinFlip();

	Fight(playerGoesFirst);

	Conclude();
}