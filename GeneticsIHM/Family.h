#pragma once
#include <vector>
#include <memory>
#include "Creature.h"
#include "TypeCreature.h"
#include <algorithm>

class Family
{
public:
	
	Family(const Environment &env, std::vector<std::pair<TypeCreature, int>> pairesTypeCreatures);
	void addNewCreature(const Environment& env, TypeCreature type);
	void updateGeneration();
	std::string toString();
	~Family();
	Family(Family const& other);
	Family(Family && other) = default;
	Family& operator=(Family const& other);
	Family& operator=(Family && other) = default;

private:
	const int nbMaxCreatures = 500;
	int generation;
	std::vector<std::unique_ptr<Creature>> creatures;

};

