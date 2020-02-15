#pragma once
#include <vector>
#include <memory>
#include "Creature.h"
#include "TypeCreature.h"

class Family
{
public:
	Family(const Environment &env, int nbCreatures, TypeCreature type);
	void addNewCreature(const Environment& env, TypeCreature type);
	void updateGeneration();
private:
	int generation;
	std::vector<std::unique_ptr<Creature>> creatures;

};

