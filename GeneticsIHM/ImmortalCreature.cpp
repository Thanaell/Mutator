#include "ImmortalCreature.h"
#include "StaticRGBCreature.h"
#include <random>
#include <algorithm>


ImmortalCreature::ImmortalCreature(const Environment& env) : Creature(env,0){
}

ImmortalCreature* ImmortalCreature::clone() {
	return new ImmortalCreature(*this);
}