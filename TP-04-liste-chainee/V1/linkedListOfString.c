// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element e) {
	printf("%s ", (char*)e);
}

void detruireElement(Element e) {}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return (char*) e1 == (char*) e2;
}

int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");



	l = ajoutTete("a",l);
	l = ajoutTete("b",l);
	l = ajoutTete("r",l);
	l = ajoutTete("a",l);
	l = ajoutTete("k",l);
	l = ajoutTete("a",l);
	l = ajoutTete("d",l);
	l = ajoutTete("a",l);
	l = ajoutTete("b",l);
	l = ajoutTete("r",l);
	l = ajoutTete("a",l);

	// afficheListe_i(l);

	ajoutFin_i("epoque",l);
	// afficheListe_i(l);

	ajoutFin_r("blablabla",l);
	afficheListe_i(l);

	printf("\nliste a l'envers : ");
	afficheEnvers_r(l);

	p = cherche_i("hhhh",l);
	printf("\ncherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("a",l);
	if(estVide(p))
		printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("z",l);
	printf("cherche_r(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("a",l);
	if(estVide(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i("a",l);
	afficheListe_r(l);

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i("a",l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r("epoque",l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r("k",l);
	afficheListe_r(l);

	printf("\nliste a l'envers : ");
	afficheEnvers_r(l);

	detruire_r(l);
	return EXIT_SUCCESS;
}