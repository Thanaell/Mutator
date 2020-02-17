#include "RGBCreature.h"
#include <random>
#include <algorithm>

RGBCreature::RGBCreature(int r2, int g2, int b2, const Environment &env, float mutProba): Creature(env, mutProba){
	reproProba = 0.5;
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



int RGBCreature::getR() {
	return r;
}
int RGBCreature::getG() {
	return g;
}
int RGBCreature::getB() {
	return b;
}