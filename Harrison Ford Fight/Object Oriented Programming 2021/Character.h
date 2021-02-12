#pragma once
#include "GameStructure.h"
#include <string>

class Character:
	public GameStructure
{
public:
	std::string Name;
	int GetHealth();
	void DisplayCharacterStats();
	void Talk(std::string stuffToSay);
	void Talk(std::string stuffToSay, std::string Name);
	int SetHealth(int healthSet);
	int virtual Attack();
	void Help();
private:
	int Health = 0;
	
};