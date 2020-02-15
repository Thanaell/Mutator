#include "Creature.h"

Creature::Creature(const Environment& env, float mutProba) : environment(env), age(0), mutationProba(mutProba) {

}

void Creature::mutate() {
	std::cout << "a unknown creature mutated PANIC";
}

bool Creature::isAlive() {
	return true;
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