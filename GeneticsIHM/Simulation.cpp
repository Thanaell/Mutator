#include "Simulation.h"
#include "Storage.h"


Simulation::Simulation(): env(Environment()) {

}

void Simulation::setUp(){
	for (int i = 0; i < 2; i++) {
		myFamily.addNewCreature(env, Immortal);
	}
	for (int i = 0; i < 50; i++) {
		myFamily.addNewCreature(env, StaticRGB);
	}
	for (int i = 0; i < 2; i++) {
		myFamily.addNewCreature(env, MovingRGB);
	}
	storage.addFamily(myFamily);
}

void Simulation::run() {
	for (int i = 0; i < 200; i++) {
		myFamily.updateGeneration();
		storage.addFamily(myFamily);
	}
}

void Simulation::setEnv(Environment& enve) {
	env = enve;
}
void Simulation::setConf(Config config) {
	conf = config;
}

Storage& Simulation::getStorage() {
	return storage;
}