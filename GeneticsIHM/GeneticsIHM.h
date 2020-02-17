#pragma once
#include <iostream>
#include <QtWidgets/QMainWindow>
#include "ui_GeneticsIHM.h"

class GeneticsIHM : public QMainWindow
{
	Q_OBJECT

public:
	GeneticsIHM(QWidget *parent = Q_NULLPTR);
	void setBrowserText(std::string myString);
private:
	Ui::MainWindow ui;
};
