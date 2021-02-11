#pragma once
#include "Character.h"

class IndianaJones :
	public Character
{
public:
	IndianaJones(std::string Name);
	void FirePistol();
	void CrackWhip();
	void IJHurt();
};