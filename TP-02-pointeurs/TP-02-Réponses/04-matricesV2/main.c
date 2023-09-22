#include <stdint.h>
#include <stdlib.h>
#include "produitMatrice.h"

int main(void) {
	Matrice *A, *B, *C;
	A = creer(1, 2, 3); // valeurInitiale, nbreLignes, nbreColonnes
	B = creer(1, 3, 3);
	initialiserLigne(2, 1, A);
	initialiserLigne(2, 2, B);
	C = multiplier(A, B);
	matrix_print(A);
	matrix_print(B);
	matrix_print(C);

	supprimer(A);
	supprimer(B);
	supprimer(C);

	return EXIT_SUCCESS;
}