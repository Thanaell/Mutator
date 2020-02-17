#include "Family.h"
#include "RGBCreature.h"
#include "StaticRGBCreature.h"
#include "MovingRGBCreature.h"
#include "ImmortalCreature.h"

#include <memory>
#include <string>

Family::Family(const Environment& env, std::vector<std::pair<TypeCreature, int>> pairesTypeCreatures): generation(0) {
	int nb = 0;
	for (const auto &it : pairesTypeCreatures){
		for (int i = 0; i < it.second; i++) {
			addNewCreature(env, it.first);
		}
	}
}

void Family::addNewCreature(const Environment& env, TypeCreature type) {
	Creature* myCreature;
	
	switch (type) {
	case StaticRGB:
		myCreature = new StaticRGBCreature((rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1, env, 0.1);
		break;
	case MovingRGB:
		myCreature = new MovingRGBCreature((rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1, env, 0.1);
		break;
	case Immortal:
		myCreature = new ImmortalCreature(env);
		break;
	default:
		myCreature = new ImmortalCreature(env);
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
		if (((rand() % 100) + 1) < 100 * it->get()->getReproProba()) {
			temp.push_back(it->get()->reproduce());
			nbRepro++;
		}
		it++;
	}
	//ajout des nouvelles créatures à la famille
	for (auto it : temp) {
		creatures.push_back(std::unique_ptr<Creature>(it));
	}
}

std::string Family::toString() {
	std::string myString = "";
	int nombreImmortals(0);
	int nombreStatic(0);
	int nombreMoving(0);
	int averageR(0);
	int averageG(0);
	int averageB(0);
	for (auto it = creatures.begin(); it != creatures.end(); it++) {
		StaticRGBCreature* temp = dynamic_cast<StaticRGBCreature*>(it->get());
		if (temp) {
			averageR += temp->getR();
			averageG += temp->getG();
			averageB += temp->getB();
			nombreStatic++;
		}
		else if (dynamic_cast<MovingRGBCreature*>(it->get())) {
			nombreMoving++;
		}
		else if (dynamic_cast<ImmortalCreature*>(it->get())) {
			nombreImmortals++;
		}
	}
	if (nombreStatic) {
		averageR /= nombreStatic;
		averageG /= nombreStatic;
		averageB /= nombreStatic;
	}
	myString = "Generation : " + std::to_string(generation) + " , Pop totale : " + std::to_string(creatures.size()) + "\n";
	myString+= "Static RGB : " + std::to_string(nombreStatic) + " , Average color : " + std::to_string(averageR) +" " + std::to_string(averageG)+" " + std::to_string(averageB) + "\n";
	myString += "Moving RGB : " + std::to_string(nombreMoving) + "\n";
	myString += "Immortals : " + std::to_string(nombreImmortals) + "\n\n";
	return myString;
}

