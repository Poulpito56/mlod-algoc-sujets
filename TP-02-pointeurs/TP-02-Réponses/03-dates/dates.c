#include "dates.h"
#include <stdint.h>
#include <stdio.h>

void initialiseDate(struct Date* d) {
int jour;
enum Mois mois;
int annee;
printf("jour : "); scanf("%i", &jour);
printf("mois : "); scanf("%d", &mois);
printf("annee : "); scanf("%i", &annee);
(*d).jour = jour;
(*d).mois = mois;
(*d).annee = annee;
};

struct Date creerDateParCopie() {
struct Date d;
int jour;
enum Mois mois;
int annee;
printf("jour : "); scanf("%i", &jour);
printf("mois : "); scanf("%d", &mois);
printf("annee : "); scanf("%i", &annee);
d.jour = jour;
d.mois = mois;
d.annee = annee;
return d;
};

void afficheDate(struct Date *d){
  printf("jour : %i, mois : %d, annee : %i\n", (*d).jour, (*d).mois, (*d).annee);    
}