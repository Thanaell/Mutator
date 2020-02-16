#include "GeneticsIHM.h"
#include <QtWidgets/QApplication>
#include <qmessagebox.h>
#include "Family.h"
#include "RGBCreature.h"
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
	Family myFamily(myEnvironment, 50, RGB);
	myString+=myFamily.toString();
	for (int i = 1; i <= 200; i++) {
		myFamily.updateGeneration();
		if (i % 10 == 0) {
			myString+=myFamily.toString();
		}
	}
	QApplication a(argc, argv);
	GeneticsIHM w;
	w.setLabelText(myString);
	w.show();
	return a.exec();
}
