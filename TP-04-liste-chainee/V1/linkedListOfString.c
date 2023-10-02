// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

void afficheElement(Element e) {
	char c = e[0];
	int i=1;
  while (c!='\0')
  {
    printf("%c",e);
		c = e[i];
    i++;
  }
}

void detruireElement(Element e) {
	free(e);
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
  bool b = true;
  int i = 0;
  while (b && e1[i]!='\0')
  {
    b = e1[i]==e2[i];
    i++;
  }
	return b && e2[i]=='\0';
}

char* creerString(char valeur, int nombre){
  char *c = (char*) malloc((nombre+1)*sizeof(char));
  for (int i = 0; i < nombre; i++)
  {
    c[i]=valeur;
  }
  c[nombre]='\0';
  return c;
}

int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	
  char* a = creerString('a',5);
  char* b = creerString('b',3);
  char* c = creerString('c',10);
  char* d = creerString('d',2);
  char* e = creerString('e',1);
  char* f = creerString('f',1);



	l = ajoutTete(a,l);
	l = ajoutTete(b,l);
	l = ajoutTete(c,l);
	l = ajoutTete(d,l);

	// afficheListe_i(l);

	ajoutFin_i(e,l);
	// afficheListe_i(l);

	ajoutFin_r(f,l);
	afficheListe_i(l);

	printf("\nliste a l'envers : ");
	afficheEnvers_r(l);

	p = cherche_i(a,l);
	printf("\ncherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i(e,l);
	if(estVide(p))
		printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r(b,l);
	printf("cherche_r(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r(c,l);
	if(estVide(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i(a,l);
	afficheListe_r(l);

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i(b,l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r(f,l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r(d,l);
	afficheListe_r(l);

	printf("\nliste a l'envers : ");
	afficheEnvers_r(l);

	detruire_r(l);
	return EXIT_SUCCESS;
}