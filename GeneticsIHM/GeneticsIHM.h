#pragma once
#include <iostream>
#include <QtWidgets/QMainWindow>
#include "ui_GeneticsIHM.h"
#include "Storage.h"

class GeneticsIHM : public QMainWindow
{
	Q_OBJECT

public:
	GeneticsIHM(Storage& store, QWidget* parent = Q_NULLPTR);
	void setBrowserText(std::string myString);
	void addFamily(Family family);
public slots:
	void updateTextBrowser(int gen);
private:
	Storage& storage;
	Ui::MainWindow ui;
};
