#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double CalculTaylorNépérien(int indice, double x, int p);
int rechercheDegré(int nbFois, int p);
double Puissance(double x, double exposant);
double nbDecimale(double x, int Decimale);

void main(void)
{
	double x, Resultat = 0;
	int p = 0, nbFois = 0, degré, nbDecimale;
	printf("Entrez la valeur de x : ");
	scanf_s("%lf", &x);
	while(x <= -1){
		printf("Entrez la valeur de x (au-dessus de -1) : ");
		scanf_s("%lf", &x);
	}
	printf("Entrez la valeur du nombre de decimale : ");
	scanf_s("%d",&nbDecimale);

	x -= 1;
	if (x > -1){
		while (x > 1.4){
			x = x/1.4;
			nbFois++;
		}
		//degré = nombre d'itération
		p = ceil(nbDecimale + (log(nbFois + 1)/log(10.0)));
		degré = rechercheDegré(nbFois, p);
		//p = nombre de décimal avec taylor
		Resultat = CalculTaylorNépérien(degré, 1.4, p)*nbFois;
		Resultat += CalculTaylorNépérien(degré, x, p);
	}
	else {
		printf("ERRRREEEEUR\n");
	}
	afficheDecimales(nbDecimale, Resultat);
	system("pause");
}

int rechercheDegré(int nbFois, int p) {
	int degré = 1;
	
	while (Puissance(0.5, degré + 1) / (degré + 1) > 0.5*Puissance(10, -p)) {
		degré++;
	}
	return degré;
}

double CalculTaylorNépérien(int degré, double x, int p){
	double Resultat = 0;
	x -= 1;
	for (int i = 1; i < degré; i++) {
		Resultat += Puissance(-1, i + 1)*Puissance(x, i)/i;
	}
	return Resultat;
}

double Puissance(double x, double exposant){
	double result = 1;
	if (x == 0 && exposant == 0) {
		return 1;
	}
	if (exposant > 0) {
		for(int i = 0; i < exposant; i++){
			result *= x;
		}
	}else{
		for(int i = 0; i > exposant; i--){
			result *= (1/x);
		}
	}
	return result;
}

double nbDecimale(double x, int Decimale) {
	return round(x*Puissance(10, Decimale)) / Puissance(10, Decimale);
}