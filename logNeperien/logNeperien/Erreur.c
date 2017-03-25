#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool verifDecimales(double x1, double x2, int Decimale);
void afficheDecimales(int nbDecimale, double reel);
int factorielle(int x1);

bool verifDecimales(double x1, double x2, int Decimale) {
	return round(x1*pow(10, Decimale)) / pow(10, Decimale) == round(x2*pow(10, Decimale)) / pow(10, Decimale);
}

void afficheDecimales(int nbDecimales, double reel){
	printf("%.*lf \n", nbDecimales, reel);
}

int factorielle(int x) {
	if(x > 1)
		return x*factorielle(x - 1);
	return 1;
}