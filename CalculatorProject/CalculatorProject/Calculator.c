#include "stdafx.h"

int affichageMenu(void) {
	int choixMenu;
	printf("Choix de l'opération à effectuer : \n\n");
	printf("1 - Calcul d'une exponentielle\n");
	printf("2 - Calcul d'un logarithme népérien\n");
	printf("3 - Calcul d'un sinus\n");
	printf("4 - Calucl d'une probabilité\n");
	scanf("%d", &choixMenu);
	while (choixMenu != 1 || choixMenu != 2 || choixMenu != 3 || choixMenu != 4){
		printf("Veuillez choisir un numéro de menu (1-4) : ");
		scanf("%d", &choixMenu);
	} 
	return choixMenu;
}

void menu(int choixMenu) {
	double resultat, x;
	int nbDecimales;
	switch (choixMenu) {
		case 1:
			resultat = expo(x, nbDecimales);
			break;
		case 2:
			resultat = ln(x, nbDecimales);
			break;
		case 3:
			resultat = sin(x, nbDecimales);
			break;
		case 4:
			resultat = proba(x, nbDecimales);
			break;
	}

}