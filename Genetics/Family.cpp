#include "Family.h"
#include "RGBCreature.h"
#include <memory>

Family::Family(const Environment& env, int nbCreatures, TypeCreature baseType): generation(0) {
	for (int i = 0; i < nbCreatures; i++) {
		addNewCreature(env, baseType);
	}
}

//TODO : faire une vraie factory
void Family::addNewCreature(const Environment& env, TypeCreature type) {
	Creature* myCreature;
	switch (type) {
	case RGB:
		myCreature = new RGBCreature(0,0,0,env,0);
		break;
	default:
		myCreature = new RGBCreature(0,0,0,env,0);
		break;
	}
	creatures.push_back(std::unique_ptr<Creature>(myCreature));
}

void Family::updateGeneration() {
	generation++;
	std::vector<Creature*> temp;
	// suppression des morts
	for (auto it = creatures.begin(); it != creatures.end(); it++) {
		if (!it->get()->update()) {
			creatures.erase(it);
		}
		// mutation puis reproduction
		else {
			it->get()->mutate();
			temp.push_back(it->get()->reproduce());
		}
	}
	//ajout des nouvelles créatures à la famille
	for (auto it : temp) {
		creatures.push_back(std::unique_ptr<Creature>(it));
	}
}
