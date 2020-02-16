#pragma once
#include "Environment.h"

class Creature
{
protected:
	int age;
	Environment environment;
	float mutationProba;
public:
	Creature(const Environment& environment, float mutProba);
	virtual void mutate();
	virtual bool isAlive();
	bool update();
	virtual Creature* reproduce();
	virtual Creature* clone() = 0;
};

