#include "GeneticsIHM.h"


GeneticsIHM::GeneticsIHM(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void GeneticsIHM::setLabelText(std::string myString) {
	ui.label->setText(QString::fromStdString(myString));
}