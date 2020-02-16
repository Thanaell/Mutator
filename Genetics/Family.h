#pragma once
#include <vector>
#include <memory>
#include "Creature.h"
#include "TypeCreature.h"
#include <algorithm>

class Family
{
public:
	Family(const Environment &env, int nbCreatures, TypeCreature type);
	void addNewCreature(const Environment& env, TypeCreature type);
	void updateGeneration();
	void toString();

private:
	const int nbMaxCreatures = 500;
	int generation;
	std::vector<std::unique_ptr<Creature>> creatures;

};

