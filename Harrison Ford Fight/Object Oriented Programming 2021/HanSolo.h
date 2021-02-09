#pragma once
#include "Character.h"

class HanSolo :
	public Character
{
public:
	HanSolo(std::string Name);
	void FireBlaster();
	void JediDodge();
	void HSHurt();
};