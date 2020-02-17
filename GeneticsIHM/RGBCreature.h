#pragma once
#include "Creature.h"

class RGBCreature :
	public Creature
{
public:
	RGBCreature(int r2, int g2, int b2, const Environment& env, float mutProba);
	virtual void mutate() override = 0;
	virtual bool isAlive() override = 0;
	virtual RGBCreature* clone() = 0;
	int getR();
	int getG();
	int getB();
	virtual double myDeathFunction(double x) = 0;
protected:
	int r;
	int g;
	int b;
};

