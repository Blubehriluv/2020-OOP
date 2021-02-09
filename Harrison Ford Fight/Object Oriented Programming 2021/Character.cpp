#include <iostream>
#include <string>
#include "Character.h"

void Character()
{
	
}

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