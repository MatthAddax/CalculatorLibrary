#ifndef BASE_H
	#define BASE_H
	#include "base.h"
#endif // !BASE_H


int factorielle(int x) {
	int result = 1;
	while (x > 1) {
		result *= x;
		x--;
	}
	return result;
}

double puissance(double x, int exposant) {
	if (x == 0)
		return 0;
	
	int result = 1;
	int i = 0;

	while (i < exposant) {
		result *= x;
		i++;
	}

	return result;
}

