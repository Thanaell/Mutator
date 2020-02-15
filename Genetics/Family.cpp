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
		myCreature = new RGBCreature((rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1, env, 0);
		break;
	default:
		myCreature = new RGBCreature((rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1, env, 0);
		break;
	}
	creatures.push_back(std::unique_ptr<Creature>(myCreature));
}

void Family::updateGeneration() {
	generation++;
	std::vector<Creature*> temp;
	// suppression des morts
	for (auto it = creatures.begin(); it != creatures.end();) {
		if (!it->get()->update()) {
			it=creatures.erase(it);
		}
		else {
			it++;
		}
	}
	//mutation puis reproduction des survivants
	//TODO : reproduire seulement un certain nombre de créatures choisies aléatoirement parmi les survivants
	for (auto it = creatures.begin(); it != creatures.end(); it++) {
		it->get()->mutate();
		temp.push_back(it->get()->reproduce());
	}
	//ajout des nouvelles créatures à la famille
	for (auto it : temp) {
		creatures.push_back(std::unique_ptr<Creature>(it));
	}
}

void Family::toString() {
	int nombreRGB(0);
	int averageR(0);
	int averageG(0);
	int averageB(0);
	for (auto it = creatures.begin(); it != creatures.end(); it++) {
		RGBCreature* temp = dynamic_cast<RGBCreature*>(it->get());
		if (temp) {
			averageR += temp->getR();
			averageG += temp->getG();
			averageB += temp->getB();
			nombreRGB++;
		}
	}
	if (nombreRGB) {
		averageR /= nombreRGB;
		averageG /= nombreRGB;
		averageB /= nombreRGB;
	}
	std::cout << "Generation : " << generation << " , Pop totale : "<< creatures.size() << " Population de couleur : " << nombreRGB << " , Average color : " << averageR <<" " <<averageG<<" " <<averageB << std::endl;
}