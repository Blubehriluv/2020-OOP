#pragma once
#include <string>
#include "GameStructure.h"

class Character:
	public GameStructure
{
public:
	int Health;
	std::string Name;
	int GetHealth();
	void DisplayCharacterStats();
	void Talk(std::string stuffToSay);
	void Talk(std::string stuffToSay, std::string Name);
	int SetHealth(int healthSet);
	
};