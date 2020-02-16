#include "Family.h"
#include "RGBCreature.h"
#include <memory>
#include <string>

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
		myCreature = new RGBCreature((rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1, env, 0.1);
		break;
	default:
		myCreature = new RGBCreature((rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1, env, 0.1);
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
	//mutation des survivants
	for (auto it = creatures.begin(); it != creatures.end(); it++) {
		it->get()->mutate();
	}
	//puis reproduction d'une partie des survivants
	std::random_shuffle(creatures.begin(), creatures.end());
	int nbRepro(creatures.size());
	auto it = creatures.begin();
	while (nbRepro < nbMaxCreatures && it != creatures.end()) {
		temp.push_back(it->get()->reproduce());
		it++;
		nbRepro++;
	}
	//ajout des nouvelles créatures à la famille
	for (auto it : temp) {
		creatures.push_back(std::unique_ptr<Creature>(it));
	}
}

std::string Family::toString() {
	std::string myString = "";
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
	myString= "Generation : " + std::to_string(generation)+ " , Pop totale : " + std::to_string(creatures.size()) + " Population de couleur : " + std::to_string(nombreRGB) + " , Average color : " + std::to_string(averageR) +" " + std::to_string(averageG)+" " + std::to_string(averageB) + "\n";
	return myString;
}

