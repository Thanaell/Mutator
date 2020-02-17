#include "GeneticsIHM.h"

GeneticsIHM::GeneticsIHM(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void GeneticsIHM::setBrowserText(std::string myString) {
	ui.textBrowser->setText(QString::fromStdString(myString));
}