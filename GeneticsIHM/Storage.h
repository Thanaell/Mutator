#pragma once
#include "Family.h"
#include <string>

class Storage {
private:
	int generations;
	std::vector<Family> families;
public:
	Storage();
	void addFamily(Family family);
	std::string toString(int gen);
};
