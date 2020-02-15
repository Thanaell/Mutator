#include "Environment.h"

Environment::Environment() :r(255), g(255), b(255) {

}

Environment::Environment(int r2, int g2, int b2){
	if (r2 >= 0 && r2 <= 255) {
		r = r2;
	}
	else {
		r = 255;
	}
	if (g2 >= 0 && g2 <= 255) {
		g = g2;
	}
	else {
		g = 255;
	}
	if (b2 >= 0 && b2 <= 255) {
		b = b2;
	}
	else {
		b = 255;
	}
}