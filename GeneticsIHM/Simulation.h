#pragma once
#include "Family.h"
#include "Config.h"
#include "Storage.h"

class Simulation
{
private:
	Storage storage;
	Family myFamily;
	Environment env;
	Config conf;
	
public:
	void run();
	void setUp();
	Simulation();
	Family getFamily();
	void addFamily(Family family);
	Storage & getStorage();
	void setEnv(Environment& env);
	void setConf(Config conf);
};


