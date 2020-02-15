#pragma once
#include "Creature.h"

class RGBCreature :
	public Creature
{
public:
	RGBCreature(int r2, int g2, int b2, const Environment& env, float mutProba);
	void mutate() override;
	bool isAlive() override;
	virtual RGBCreature* clone();
private:
	int r;
	int g;
	int b;
};

