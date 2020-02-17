#pragma once
#include "RGBCreature.h"
class MovingRGBCreature :
	public RGBCreature
{
public:
	MovingRGBCreature(int r2, int g2, int b2, const Environment& env, float mutProba);
	void mutate() override;
	bool isAlive() override;
	MovingRGBCreature* clone() override;
	double myDeathFunction(double x);
	void move();
private:
	float x;
	float y;
};

