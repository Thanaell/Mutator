#include "RGBCreature.h"
#include <random>
#include <algorithm>

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

// gaussiennes autour des couleurs de la créature 
void RGBCreature::mutate() {
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	//std::cout << r << " " << g << " " << b << " ";
	std::normal_distribution<> dr{double(r),5.0 };
	std::normal_distribution<> dg{double(g),5.0 };
	std::normal_distribution<> db{double(b),5.0 };
	r = std::max(0.0, std::min(dr(gen), 255.0));
	g = std::max(0.0, std::min(dg(gen), 255.0));
	b = std::max(0.0, std::min(db(gen), 255.0));
	//std::cout << r << " " << g << " " << b << " "<<std::endl;
	
}

bool RGBCreature::isAlive() {
	// if too old, dies
	if (age >= 2) {
		return false;	
	}
	else {
		//TODO: deathProba non linéaire
		int diffR = abs(environment.getR() - r);
		int diffB = abs(environment.getB() - b);
		int diffG = abs(environment.getG() - g);
		float deathProba = 100 * (diffB + diffR + diffG);
		deathProba /= 3.0;
		deathProba /= 255.0;
		float tirage = (rand() % 100) +1;
		if (tirage < deathProba) {
			return false;
		}
		else {
			return true;
		}
	}
}

RGBCreature* RGBCreature::clone() {
	return new RGBCreature(*this);
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