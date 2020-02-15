#include "Family.h"
#include "RGBCreature.h"

int main() {
	Environment myEnvironment;
	Family myFamily(myEnvironment, 10, RGB);
	std::cout << "family created";
	myFamily.updateGeneration();
	std::cout << "family updated";
}