// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element e) {
	printf("%s ", ((Music*)e)->name);
	printf("%s ", ((Music*)e)->artist);
	printf("%s ", ((Music*)e)->album);
	printf("%s ", ((Music*)e)->genre);
	printf("%i ", ((Music*)e)->discNumber);
	printf("%i ", ((Music*)e)->trackNumber);
	printf("%i \n ", ((Music*)e)->year);
}

void detruireElement(Element e) {
	free(((Music*)e)->name);
	free(((Music*)e)->artist);
	free(((Music*)e)->album);
	free(((Music*)e)->genre);
	free((Music*)e);
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	bool b = true;
	b = b && ((Music*)e1)->name==((Music*)e2)->name;
	b = b && ((Music*)e1)->artist==((Music*)e2)->artist;
	b = b && ((Music*)e1)->album==((Music*)e2)->album;
	b = b && ((Music*)e1)->genre==((Music*)e2)->genre;
	b = b && ((Music*)e1)->discNumber==((Music*)e2)->discNumber;
	b = b && ((Music*)e1)->trackNumber==((Music*)e2)->trackNumber;
	b = b && ((Music*)e1)->year==((Music*)e2)->year;
	return b;
}

int main(void){
	Liste l;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	
	FILE* f = fopen("music.csv","r");

	printf("%i\n", numberOfMusic(f));

	for (int i = 0; i < 3; i++)
	{
		l = ajoutTete(returnMusic(f),l);
	}
	
	afficheListe_i(l);

	printf("\nliste a l'envers : \n");
	afficheEnvers_r(l);
	/*
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
	*/

	fclose(f);
	detruire_r(l);
	return EXIT_SUCCESS;
}