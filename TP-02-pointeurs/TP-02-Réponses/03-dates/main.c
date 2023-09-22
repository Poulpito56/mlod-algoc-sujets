#include <stdint.h>
#include <stdlib.h>
#include "dates.h"

#define SIZE 5

int main(void) {
	struct Date d;
	initialiseDate(&d); //Pourquoi a t-on ajouté un &?
	afficheDate(&d);

	struct Date d2;
	d2 = creerDateParCopie();
	afficheDate(&d2);

	struct Date *date;
	date = newDate();
	afficheDate(date);
	free(date);
	date=NULL;

	return EXIT_SUCCESS;
}