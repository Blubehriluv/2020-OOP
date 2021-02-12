#include <iostream>
#include <string>
#include "Character.h"
#include "HanSolo.h"

// This creates the HanSolo character with whatever name was given
HanSolo::HanSolo(std::string givenName)
{
	Name = givenName;
	std::cout << Name << ": Get ready to go home empty handed!" << std::endl;
}

// Han Solo's attack text
void HanSolo::FireBlaster()
{
	std::cout << Name << ": PEW, PEW!" << std::endl;
	std::cout << Name << ": Sorry about the mess." << std::endl;
}

// This is Han Solo's block/dodge/parry
void HanSolo::JediDodge()
{
	std::cout << Name << ": Greedo didn't shoot ;)" << std::endl;
	std::cout << Name << ": But I can still dodge like lightning!" << std::endl;
}

// This is when Han Solo gets hurt
void HanSolo::HSHurt()
{
	std::cout << Name << ": OUUUUGHGHGH" << std::endl;
}

// Shows the user how to use their character's abilities
void HanSolo::Help()
{
	std::cout << "I can 'fire' my 'blaster' to deal damage and use my 'jedi dodge' to avoid getting hurt!" << std::endl;
}

int HanSolo::Attack()
{
	HanSolo::FireBlaster();
	return 25;
}