#include "Family.h"
#include "RGBCreature.h"
#include <ctime>
#include <cstdlib>
#include <random>


int main() {
	srand(time(NULL));
	std::random_device rd{};
	std::mt19937 gen{rd()};
	Environment myEnvironment;
	Family myFamily(myEnvironment, 10, RGB);
	myFamily.toString();
	for (int i = 0; i < 1000; i++) {
		myFamily.updateGeneration();
	}
	myFamily.toString();
}