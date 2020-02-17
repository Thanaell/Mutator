#include "Creature.h"

Creature::Creature(const Environment& env, float mutProba) : environment(env), age(0), mutationProba(mutProba), reproProba(0) {

}

void Creature::mutate() {
}

bool Creature::isAlive() {
	return true;
}

float Creature::getReproProba() {
	return reproProba;
}

bool Creature::update() {
	if (isAlive()) {
		mutate();
		age++;
		return true;
	}
	else {
		return false;
	}
}

// retourne une copie de la créature avec éventuellement une mutation (pas de reproduction par couple pour le moment)
Creature* Creature::reproduce() {
	Creature* myCreature;
	myCreature = this->clone();
	myCreature->age = 0;
	myCreature->mutate();
	return myCreature;
}