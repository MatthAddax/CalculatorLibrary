#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Exponentielle(double exposant);
int CalculDegré(int nbDecimale);
double CalculPourDegre(double n);
double CalculPolynome(double nombre, int degre);
double Puissance(double x, double exposant);
int factorielle(int x);

void main(){
	double expo;
	/*printf("0) : %15lf\n", CalculPourDegre(0));
	printf("1) : %15lf\n", CalculPourDegre(1));
	printf("2) : %15lf\n", CalculPourDegre(2.0)); 
	printf("3) : %15lf\n", CalculPourDegre(3.0));
	printf("4) : %15lf\n", CalculPourDegre(4.0));
	printf("5) : %15lf\n", CalculPourDegre(5.0));
	printf("10) : %15lf\n", CalculPourDegre(10));*/

	/*printf("0) DEGRE : %d\n", CalculDegré(0));
	printf("1) DEGRE : %d\n", CalculDegré(1));
	printf("2) DEGRE : %d\n", CalculDegré(2));
	printf("3) DEGRE : %d\n", CalculDegré(3));
	printf("4) DEGRE : %d\n", CalculDegré(4));
	printf("5) DEGRE : %d\n", CalculDegré(5));
	printf("10) DEGRE : %d\n", CalculDegré(10));*/

	printf("5.6,0 : %.2lf\n", CalculPolynome(5.6,0));
	printf("5.6,1 : %.2lf\n", CalculPolynome(5.6,1));
	printf("5.6,2 : %.2lf\n", CalculPolynome(5.6,2));
	printf("5.6,3 : %.2lf\n", CalculPolynome(5.6,3));
	printf("5.6,4 : %.2lf\n", CalculPolynome(5.6,4));
	printf("5.6,5 : %.2lf\n", CalculPolynome(5.6,5));
	printf("5.6,10 : %.2lf\n", CalculPolynome(5.6,10));
	printf("-0.3,0 : %.2lf\n", CalculPolynome(-0.3,0));
	printf("0.3,1 : %.2lf\n", CalculPolynome(0.3,1));
	printf("-4.8,2 : %.2lf\n", CalculPolynome(-4.8,2));
	printf("-4.8,3 : %.2lf\n", CalculPolynome(-4.8,3));
	printf("-4.8,4 : %.2lf\n", CalculPolynome(-4.8,4));
	printf("-4.8,5 : %.2lf\n", CalculPolynome(-4.8,5));
	printf("-4.8,10 : %.2lf\n", CalculPolynome(-4.8,10));

	printf("Introduisez l'exposant de e : ");
	scanf_s("%lf", &expo);
	Exponentielle(expo);
	system("pause");
}

double Exponentielle(double exposant) {
	int degre = 0, nbDecimales = 2;
	double totalPolynome = 0, reste, multipleDe05, argMod, p, polynome05, polynomeReste, resultatPolynome;

	if (exposant > 0.5 || exposant < -0.5) {
		multipleDe05 = abs(ceil(exposant / 0.5));

		if (exposant < -0.5) {
			reste = (exposant + (multipleDe05*0.5));
		}else{
			reste = (exposant - (multipleDe05*0.5));
		}

		argMod = (abs(ceil(exposant / 0.5)) + 1) * 0.5;
		p = ceil((nbDecimales + (argMod - 0.5) * 0.5 + (argMod / 5) + 0.31));
		degre = CalculDegré(p);
		polynome05 = CalculPolynome((exposant > 0 ? 0.5 : -0.5), degre);
		polynomeReste = CalculPolynome(reste, degre);
		totalPolynome = reste * (Puissance(polynome05, multipleDe05));
	}else{
		degre = CalculDegré(nbDecimales);
		
		resultatPolynome = CalculPolynome(exposant, degre);
		totalPolynome = resultatPolynome;
	}
	return totalPolynome;
}

int CalculDegré(int nbDecimale){
	int n = 0;
	double Resultat, constante;
	Resultat = CalculPourDegre(n);
	constante = 0.5 * Puissance(10, -nbDecimale);
	printf("Resultat : %.3lf\tConstante : %.5lf\n",Resultat, constante);
	while (Resultat >= constante) {
		n++;
		Resultat = CalculPourDegre(n);
		printf("Resultat : %.3lf\tConstante : %.5lf\tN : %d\n", Resultat, constante,n);
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

double Puissance(double x, double exposant) {
	double result = 1;
	if (x == 0 && exposant == 0) {
		return 1;
	}
	if (exposant > 0) {
		for (int i = 0; i < exposant; i++) {
			result *= x;
		}
	}
	else {
		for (int i = 0; i > exposant; i--) {
			result *= (1 / x);
		}
	}
	return result;
}

int factorielle(int x) {
	if (x > 1)
		return x*factorielle(x-1);
	return 1;
}