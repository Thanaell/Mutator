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
	QApplication a(argc, argv);
	GeneticsIHM w;
	w.show();
	return a.exec();
}
