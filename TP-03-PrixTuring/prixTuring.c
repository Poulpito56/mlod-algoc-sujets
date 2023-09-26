/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


typedef struct {
  int annee;
  char *nom;
  char *travaux;
} Ligne;


int numberOfWinners(FILE* f){
	int caractere;
	int count = 1;
	
	while ((caractere = fgetc(f)) != EOF) {
    if (caractere=='\n')
		{
			count++;
		}
  }
	return count;
};

char *readStringFromFileUntil(FILE *f, char c){
	int caractere;
	char *result = (char*) malloc(512*sizeof(char));
	int i = 0;
	while ((caractere = fgetc(f)) != EOF) {
    if (caractere==c)
		{
			return result;
		}
		result[i]=caractere;
		i++;
  }
};

void readWinners(FILE *f, Ligne *ligne){
	fscanf(f, "%i", &ligne->annee);
	ligne->nom=readStringFromFileUntil(f, ';');
	ligne->travaux=readStringFromFileUntil(f, ';');
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE* f;
	FILE* of;
	f = fopen(filename,"r");
	of = fopen(outputFilename, "a");
	
	printf("%i", numberOfWinners(f));
	
	fclose(f);
	fclose(f);
	return EXIT_SUCCESS;

}