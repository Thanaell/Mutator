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
	Family myFamily(myEnvironment, 50, RGB);
	myFamily.toString();
	for (int i = 1; i <= 500; i++) {
		myFamily.updateGeneration();
		if (i % 10 == 0) {
			myFamily.toString();
		}
	}
}