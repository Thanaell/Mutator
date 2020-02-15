#include "Family.h"
#include "RGBCreature.h"
#include <ctime>
#include <cstdlib>


int main() {
	srand(time(NULL));
	Environment myEnvironment;
	Family myFamily(myEnvironment, 10, RGB);
	myFamily.toString();
	for (int i = 0; i < 20; i++) {
		myFamily.updateGeneration();
		myFamily.toString();
	}
}