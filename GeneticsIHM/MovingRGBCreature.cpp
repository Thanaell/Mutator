#include "MovingRGBCreature.h"
#include "StaticRGBCreature.h"
#include <random>
#include <algorithm>


MovingRGBCreature::MovingRGBCreature(int r2, int g2, int b2, const Environment& env, float mutProba) :RGBCreature(r2, g2, b2, env, mutProba){
}

// gaussiennes autour des couleurs de la créature 
void MovingRGBCreature::mutate() {
}

bool MovingRGBCreature::isAlive() {
	// if too old, dies
	if (age >= 3) {
		return false;
	}
	else {
		float diffR = abs(environment.getR() - r);
		float diffB = abs(environment.getB() - b);
		float diffG = abs(environment.getG() - g);
		float maxR = std::max(environment.getR(), 255 - environment.getR());
		float maxB = std::max(environment.getB(), 255 - environment.getB());
		float maxG = std::max(environment.getG(), 255 - environment.getG());
		double deltaB = diffB / maxB;
		double deltaR = diffR / maxR;
		double deltaG = diffG / maxG;

		float deathProbaB = myDeathFunction(deltaB);
		float deathProbaG = myDeathFunction(deltaG);
		float deathProbaR = myDeathFunction(deltaR);

		double tirageR = ((double)rand() / (RAND_MAX));
		double tirageG = ((double)rand() / (RAND_MAX));
		double tirageB = ((double)rand() / (RAND_MAX));

		//std::cout << tirage << "\t" << deathProba<< std::endl;
		if (tirageR < deathProbaR || tirageG < deathProbaG || tirageB < deathProbaB) {
			return false;
		}
		else {
			return true;
		}
	}
}

double MovingRGBCreature::myDeathFunction(double x) {
	return (x - 0.02) * (x - 0.02);
}

MovingRGBCreature* MovingRGBCreature::clone() {
	return new MovingRGBCreature(*this);
}