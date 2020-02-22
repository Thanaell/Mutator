#pragma once
#include <iostream>
#include <QtWidgets/QMainWindow>
#include "ui_GeneticsIHM.h"
#include "Storage.h"
#include "Simulation.h"

class GeneticsIHM : public QMainWindow
{
	Q_OBJECT

public:
	GeneticsIHM(QWidget* parent = Q_NULLPTR);
public slots:
	void updateTextBrowser(int gen);
	void runSimulation();
	void loadConfig();
	void loadEnvironment();
private:
	Environment env;
	Config conf;
	Ui::MainWindow ui;
	Simulation simu;
};
