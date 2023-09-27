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
	char *result = (char*) calloc(512, sizeof(char)); //On prend la place pour 512 char maximum
	int i = 0;
	int j = -1; //indice décalé car la chaine ce char peut commencer par un ;
	while ((caractere = fgetc(f)) != EOF && i<511) {
    if (caractere==c && i>0)
		{
			result[j]='\0';
			return result;
		}
		if (caractere != c)
		{
			if (i==0)
			{
				j++;
			}
			result[j]=caractere;
		}
		i++;
		j++;
  };
	result[i]='\0';
	return result;
};

void supprimer(Ligne *ligne){
	free(ligne->nom);	
	free(ligne->travaux);
	free(ligne);
}

void readWinners(FILE *f, Ligne *ligne){
	fscanf(f, "%i", &ligne->annee);
	ligne->nom=readStringFromFileUntil(f, ';');
	ligne->travaux=readStringFromFileUntil(f, '\n');
};

Ligne* returnLigneWinner(FILE *f){
	Ligne *ligne = (Ligne*) malloc(sizeof(Ligne));
	readWinners(f, ligne);
	return ligne;
}

void afficherTableauChar(char *string){
	int i=0;
	while (i<512 && string[i]!='\0')
	{	
		printf("%c", string[i]);
		i++;
	}
	printf("\n");
};

void ecrireLigne(Ligne *ligne, FILE *fichierPourEcrire){
	fprintf(fichierPourEcrire, "%d;", ligne->annee);
	fprintf(fichierPourEcrire, "%s;", ligne->nom);
	fprintf(fichierPourEcrire, "%s\n", ligne->travaux);
}

int nbWinners(char filename[]){
	FILE *fichierACopier = fopen(filename,"r");
	int nbWin = numberOfWinners(fichierACopier);
	fclose(fichierACopier);
	return nbWin;
}

void printWinners(char filename[], char outputFilename[]){
	Ligne *ligne;
	int nbWin = nbWinners(filename);
	FILE *fichierACopier = fopen(filename,"r");
	FILE *fichierPourEcrire = fopen(outputFilename,"w");
	for (int i = 0; i < nbWin; i++)
	{
		ligne=returnLigneWinner(fichierACopier);
		ecrireLigne(ligne, fichierPourEcrire);
		supprimer(ligne);
	}
	fclose(fichierACopier);
	fclose(fichierPourEcrire);
}

Ligne* searchLineByAnnee(char filename[], int annee){
	Ligne *ligne;
	int nbWin = nbWinners(filename);
	FILE *fichierACopier = fopen(filename,"r");
	for (int i = 0; i < nbWin; i++)
	{
		ligne=returnLigneWinner(fichierACopier);
		if (ligne->annee==annee)
		{
			return ligne;
		}
		supprimer(ligne);
	}
	fclose(fichierACopier);
	return ligne;
}


void infoAnnee(char filename[], int annee){
	Ligne *ligne = searchLineByAnnee(filename, annee);
	printf("L'annee %i, le(s) gagnant(s) ont été : %s\nNature des travaux : %s\n", annee, ligne->nom, ligne->travaux);
	supprimer(ligne);
}


int anneeMin(char filename[]){
	Ligne *ligne;
	int nbWin = nbWinners(filename);
	FILE *fichierACopier = fopen(filename,"r");
	int anneeMin = 3000;
	for (int i = 0; i < nbWin; i++)
	{
		ligne=returnLigneWinner(fichierACopier);
		if (ligne->annee<anneeMin)
		{
			anneeMin=ligne->annee;
		}
		supprimer(ligne);
	}
	fclose(fichierACopier);
	return anneeMin;
}

void sortTuringWinnersByYear(char filename[], char outputFilename[]){
	Ligne *ligne;
	int nbWin = nbWinners(filename);
	int annee = anneeMin(filename);
	FILE *fichierACopier = fopen(filename,"r");
	FILE *fichierPourEcrire = fopen(outputFilename,"w");
	for (int i = 0; i < nbWin; i++)
	{
		ligne=searchLineByAnnee(filename, annee);
		ecrireLigne(ligne, fichierPourEcrire);
		supprimer(ligne);
		annee++; //On suppose que un prix est gagné chaque année ici
	}
	fclose(fichierACopier);
	fclose(fichierPourEcrire);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	char sortedFile[] = "sortedWinners.csv";
	
	printWinners(filename, outputFilename);
	sortTuringWinnersByYear(filename, sortedFile);
	infoAnnee(filename, 2003);

	return EXIT_SUCCESS;

}