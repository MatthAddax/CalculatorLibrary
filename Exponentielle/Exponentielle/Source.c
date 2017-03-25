#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Exponentielle(double exposant);


void main(){
	double expo;
	printf("Introduisez l'exposant de e : ");
	scanf_s("%lf", &expo);
	Exponentielle(expo);
	System("pause");
}

double Exponentielle(double exposant) {
	int degre = 0, nbDecimales, multipleDe05;
	double totalPolynome = 0, reste, argMod, p, polynome05, polynomeReste, resultatPolynome;

	if (exposant > 0.5 || exposant < -0.5) {
		multipleDe05 = abs(ceil(exposant / 0.5));

		if (exposant < -0.5) {
			reste = (exposant + (multipleDe05*0.5));
		}else{
			reste = (exposant - (multipleDe05*0.5));
		}

		argMod = (abs(ceil(exposant / 0.5)) + 1) * 0.5;
		p = ceil((nbDecimales + (argMod - 0.5) * 0.5 + (argMod / 5) + 0.31));
		degre = CalculDegré(exposant, p);
		polynome05 = CalculPolynome((exposant > 0 ? 0.5 : -0.5), degre);
		polynomeReste = CalculPolynome(reste, degre);
		totalPolynome = reste * (Puissance(polynome05, multipleDe05));
	}else{
		degre = CalculDegré(exposant, nbDecimales);
		resultatPolynome = CalculPolynome(exposant, degre);
		totalPolynome = resultatPolynome;
	}
	return totalPolynome;
}

double CalculDegré(int nbDecimale){
	double n = 0, Resultat, constante;
	Resultat = CalculPourDegre(n);
	constante = 0.5 * Puissance(10, -nbDecimale);
	while (Resultat >= constante) {
		Resultat = CalculPourDegre(n);
		n++;
	}
	return n;
}

double CalculPourDegre(double n){
	return (2.8*Puissance(0.5, n + 1) / factorielle(n));
}

double CalculPolynome(double nombre, int degre) {
	double total = 0;
	for (int n = 0; n <= degre;n++){
		total += (Puissance(nombre, n) / factorielle(nombre));
	}
	return total;
}