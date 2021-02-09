#include <iostream>
#include <string>
#include "Character.h"

int GetHealth()
{
	return 0;
}

void DisplayCharacterStats()
{
	std::cout << "This Character currently has " << GetHealth() << " customers!" << std::endl;
}

void Talk(std::string stuffToSay)
{
	std::cout << "The Character says, '" << stuffToSay << "'" << std::endl;
}

void Talk(std::string stuffToSay, std::string Name)
{
	std::cout << Name << ", " << stuffToSay << "." << std::endl;
}

int SetHealth(int healthSet)
{
	if (healthSet <= 0)
	{
		healthSet = 0;
		std::cout << "Character has expired..." << std::endl;
	}
}