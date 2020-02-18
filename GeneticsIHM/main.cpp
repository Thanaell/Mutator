#include "GeneticsIHM.h"
#include <QtWidgets/QApplication>
#include <qmessagebox.h>
#include "Family.h"
#include "RGBCreature.h"
#include "Storage.h"
#include <ctime>
#include <cstdlib>
#include <random>

int main(int argc, char *argv[])
{
	std::string myString = "";
	srand(time(NULL));
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	Environment myEnvironment;
	std::vector<std::pair<TypeCreature, int>> pairesTypesNb;
	std::pair<TypeCreature, int> immortals(Immortal,2 );
	std::pair<TypeCreature, int> moving(MovingRGB,3);
	std::pair<TypeCreature, int> statics(StaticRGB,50);
	pairesTypesNb.push_back(immortals);
	pairesTypesNb.push_back(moving);
	pairesTypesNb.push_back(statics);
	Family myFamily(myEnvironment, pairesTypesNb);
	Storage myStorage;
	myStorage.addFamily(myFamily);

	for (int i = 1; i <= 50; i++) {
		myFamily.updateGeneration();
		myStorage.addFamily(myFamily);
	}
	QApplication a(argc, argv);
	GeneticsIHM w;
	w.setBrowserText(myStorage.toString(50));
	w.show();
	return a.exec();
}
