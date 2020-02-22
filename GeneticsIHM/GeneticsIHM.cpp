#include "GeneticsIHM.h"
#include "Environment.h"

GeneticsIHM::GeneticsIHM(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	ui.GenerationSlider->setMinimum(0);
	ui.GenerationSlider->setMaximum(0);
	QObject::connect(ui.GenerationSlider, SIGNAL(valueChanged(int)), this, SLOT(updateTextBrowser(int)));
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(runSimulation()));
}

void GeneticsIHM::runSimulation() {
	loadEnvironment();
	loadConfig();
	simu.setEnv(env);
	simu.setConf(conf);
	simu.setUp();
	//TODO: setup slider
	ui.GenerationSlider->setMaximum(200);
	simu.run();
}

void GeneticsIHM::loadConfig() {
	
}

void GeneticsIHM::loadEnvironment() {

}

void GeneticsIHM::updateTextBrowser(int gen) {
	ui.textBrowser->setText(QString::fromStdString(simu.getStorage().toString(gen)));
}