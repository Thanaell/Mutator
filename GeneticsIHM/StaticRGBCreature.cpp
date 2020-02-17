#include "StaticRGBCreature.h"
#include <random>
#include <algorithm>


StaticRGBCreature::StaticRGBCreature(int r2, int g2, int b2, const Environment& env, float mutProba) :RGBCreature(r2, g2, b2, env, mutProba) {
}

// gaussiennes autour des couleurs de la créature 
void StaticRGBCreature::mutate() {
	int randInt = (rand() % 100) + 1;
	if (randInt < mutationProba * 100) {
		std::random_device rd{};
		std::mt19937 gen{ rd() };
		//std::cout << r << " " << g << " " << b << " ";
		std::normal_distribution<> dr{ double(r),5.0 };
		std::normal_distribution<> dg{ double(g),5.0 };
		std::normal_distribution<> db{ double(b),5.0 };
		r = std::max(0.0, std::min(dr(gen), 255.0));
		g = std::max(0.0, std::min(dg(gen), 255.0));
		b = std::max(0.0, std::min(db(gen), 255.0));
		//std::cout << r << " " << g << " " << b << " "<<std::endl;
	}

}

bool StaticRGBCreature::isAlive() {
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

double StaticRGBCreature::myDeathFunction(double x) {
	return (x - 0.02) * (x - 0.02);
}

StaticRGBCreature* StaticRGBCreature::clone() {
	return new StaticRGBCreature(*this);
}