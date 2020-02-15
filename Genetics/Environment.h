#pragma once
#include <iostream>

class Environment
{
public:
	Environment();
	Environment(int r2, int g2, int b2);
	int getR();
	int getG();
	int getB();
private:
	int r;
	int g;
	int b;
};

