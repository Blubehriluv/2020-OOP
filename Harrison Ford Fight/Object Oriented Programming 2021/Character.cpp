#include <iostream>
#include <string>
#include "Character.h"

//This pulls the health of the character and relays it to the player.
int Character::GetHealth()
{
	std::cout << std::endl;
	std::cout << "My current health is " << Health << "." << std::endl;
	return  Health;
}

// This shows the current stats of the chosen character.
void Character::DisplayCharacterStats()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "~ ~ ~ Listing Character Stats ~ ~ ~" << std::endl;
	std::cout << "Given Name: " << Name << std::endl;
	std::cout << "Health: " << Health << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

// Takes input and produces text to the screen.
void Character::Talk(std::string stuffToSay)
{
	std::cout << std::endl;
	std::cout << "The Character says, '" << stuffToSay << "'" << std::endl;
}

// Takes input and a name to produce text to the screen.
void Character::Talk(std::string stuffToSay, std::string Name)
{
	std::cout << std::endl;
	std::cout << Name << " says, '" << stuffToSay << ".'" << std::endl;
}

// This will set the health of the character.
int Character::SetHealth(int healthSet)
{
	if (healthSet <= 0)
	{
		healthSet = 0;
		std::cout << std::endl;
		std::cout << "The Character has expired..." << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "My health is now " << healthSet << std::endl;
		Health = healthSet;
	}
	return Health;

}