#include "RGBCreature.h"

RGBCreature::RGBCreature(int r2, int g2, int b2, const Environment &env, float mutProba): Creature(env, mutProba) {
	if (r2 >= 0 && r2 <= 255) {
		r = r2;
	}
	else {
		r = 0;
	}
	if (g2 >= 0 && g2 <= 255) {
		g = g2;
	}
	else {
		g = 0;
	}
	if (b2 >= 0 && b2 <= 255) {
		b = b2;
	}
	else {
		b = 0;
	}
}
void RGBCreature::mutate() {
	std::cout << "an RGBCreature mutated";
}

bool RGBCreature::isAlive() {
	if (age < 3) {
		std::cout << "an RGBCreature aged";
		return true;	
	}
	else {
		std::cout << "an RGBCreature died";
		return false;
	}
}

RGBCreature* RGBCreature::clone() {
	return new RGBCreature(*this);
}