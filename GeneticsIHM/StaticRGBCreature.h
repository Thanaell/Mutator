#pragma once
#include "RGBCreature.h"
class StaticRGBCreature :
	public RGBCreature
{
public:
	StaticRGBCreature(int r2, int g2, int b2, const Environment& env, float mutProba);
	void mutate() override;
	bool isAlive() override;
	StaticRGBCreature* clone() override;
	double myDeathFunction(double x);

};

