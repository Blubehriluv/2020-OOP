#include <iostream>
#include <string>
#include "Character.h"
#include "IndianaJones.h"

// This creates an Indiana Jones character with whatever name given.
IndianaJones::IndianaJones(std::string givenName)
{
	Name = givenName;
	std::cout << Name << ": Prepare to lose!" << std::endl;
}

// This is the attack for Indiana Jones
void IndianaJones::FirePistol()
{
	std::cout << Name << ": POW, POW!" << std::endl;
	std::cout << Name << ": I oughta kill you right now." << std::endl;
}

// This is Indiana Jones' defense/dodge/parry
void IndianaJones::CrackWhip()
{
	std::cout << Name << ": CRACK!" << std::endl;
	std::cout << Name << ": That belongs in a museum!" << std::endl;
}

// This is when Indiana Jones gets hurt.
void IndianaJones::IJHurt()
{
	std::cout << Name << ": AUUUGHGHH" << std::endl;
}

// Shows the user how to use their character's abilities
void IndianaJones::Help()
{
	std::cout << "I can 'fire' my 'pistol' to hurt the enemy, and 'crack' my 'whip' to knock his bullets outta the air!" << std::endl;
}

int IndianaJones::Attack()
{
	IndianaJones::FirePistol();
	return 25;
}