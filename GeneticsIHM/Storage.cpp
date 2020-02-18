#include "Storage.h"


Storage::Storage() : generations(0) {
}

void Storage::addFamily(Family family) {
	families.push_back(family);
	generations++;
}

std::string Storage::toString(int gen) {
	std::string myString;
	myString = "Generation " + std::to_string(gen) + "\n" + families[gen].toString() + "\n";
	return myString;
}
