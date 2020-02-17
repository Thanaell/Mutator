#pragma once
#include "Creature.h"
class ImmortalCreature :
	public Creature
{
public:
	ImmortalCreature(const Environment& env);
	virtual ImmortalCreature* clone();
};

