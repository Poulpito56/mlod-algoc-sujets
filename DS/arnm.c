//DENIS Evan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

typedef struct
{
	int index;
	int distance;
} Distance;


const char NUCLEOTIDES[] = "ATCG";

int* statistics(char* sequanceGenetique){
	int* stat = (int*) calloc(4, sizeof(int));
	int n = 0;
	while (sequanceGenetique[n]!='\0')
	{
		if (sequanceGenetique[n]=='A')
		{
			stat[0]++;
		}
		if (sequanceGenetique[n]=='T')
		{
			stat[1]++;
		}
		if (sequanceGenetique[n]=='C')
		{
			stat[2]++;
		}
		if (sequanceGenetique[n]=='G')
		{
			stat[3]++;
		}
		n++;
	}
	for (int i = 0; i < 4; i++)
	{
		stat[i]=stat[i]*100/n;
	}
	return stat;
}

int countDifferences(char *chaine1, char *chaine2){
	int diffTrouvees = 0;
	int parcoursChaines = 0;
	while (chaine1[parcoursChaines]!='\0') // On suppose que les chaînes sont de mêmes tailles
	{
		if (chaine1[parcoursChaines]!=chaine2[parcoursChaines])
		{
			diffTrouvees++;
		}
		parcoursChaines++;
	}
	return diffTrouvees;
}

bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

Distance* computeDifferencesBetween(char *chaine1, char *chaine2){
	int nbDiff = countDifferences(chaine1,chaine2);
	Distance* dist = (Distance*) malloc(nbDiff*sizeof(Distance)); // La fonction countDifferences permet d'optimiser la place en mémoire utilisée
	int diffTrouvees = 0;
	int parcoursChaines = 0;
	while (diffTrouvees!=nbDiff) // On évite ainsi de parcourir toute la séquence une 2eme fois si les différences sont au début
	{
		if (chaine1[parcoursChaines]!=chaine2[parcoursChaines])
		{

			dist[diffTrouvees].index = parcoursChaines;
			dist[diffTrouvees].distance = distanceBetweenNucleotides(chaine1[parcoursChaines],chaine2[parcoursChaines]);
			diffTrouvees++;
		}
		parcoursChaines++;
	}
	return dist;
}

void printDifferences(char *chaine1, char *chaine2){
	Distance* dist = computeDifferencesBetween(chaine1,chaine2);
	for (int i = 0; i < countDifferences(chaine1,chaine2); i++)
	{
		printf("<%i,%i> ",dist[i].index,dist[i].distance);
	}
}

// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

	int* stat = statistics("AAGCTTTACA");
	for (int i = 0; i < 4; i++)
	{
		printf("%i ",stat[i]);
	}

	printf("\ntableaux des differences entre 'ATGC' et 'ATCG' : ");

	printDifferences("ATGC","ATCG");
	
	printf("\nnombre de differences entre moderna et pfizer : ");

	printf("%i",countDifferences(code_proteine_spike_moderna,code_proteine_spike_pfizer));

	printf("\ntableaux des differences entre moderna et pfizer : ");

	printDifferences(code_proteine_spike_moderna,code_proteine_spike_pfizer);

	return EXIT_SUCCESS;
}

