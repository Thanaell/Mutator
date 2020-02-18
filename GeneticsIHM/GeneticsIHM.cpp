#include "GeneticsIHM.h"

GeneticsIHM::GeneticsIHM(Storage& store, QWidget* parent) : QMainWindow(parent), storage(store)
{
	ui.setupUi(this);
	ui.GenerationSlider->setMinimum(0);
	ui.GenerationSlider->setMaximum(200);
	QObject::connect(ui.GenerationSlider, SIGNAL(valueChanged(int)), this, SLOT(updateTextBrowser(int)));
}

void GeneticsIHM::addFamily(Family family) {
	storage.addFamily(family);
}

void GeneticsIHM::setBrowserText(std::string myString) {
	ui.textBrowser->setText(QString::fromStdString(myString));
}

void GeneticsIHM::updateTextBrowser(int gen) {
	ui.textBrowser->setText(QString::fromStdString(storage.toString(gen)));
}