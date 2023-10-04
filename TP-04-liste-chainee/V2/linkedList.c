#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l = (Liste) malloc(sizeof(Cellule));
	l->suiv = NULL;
	l->val = v;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste p = creer(v);
	p->suiv=l;
	return p;
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste p = l;
	while (!estVide(p))
	{
		afficheElement(p->val);
		p=p->suiv;
	}
}

// version recursive
void afficheListe_r(Liste l) {
	if (!estVide(l))
	{
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste p = l;
	while (!estVide(p))
	{
		detruireElement(p->val);
		p=l->suiv;
		free(l);
		l=p;
	}
	free(p);
}

// version récursive
void detruire_r(Liste l) {
	if (!estVide(l))
	{
		detruire_r(l->suiv);
	}
	free(l);
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if (estVide(l))
	{
		return creer(v);
	}
	Liste actuel = l;
	Liste suivant = l->suiv;
	while (!estVide(suivant))
	{
		actuel = suivant;
		suivant = suivant->suiv;
	}
	actuel->suiv=creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if (!estVide(l))
	{
		l->suiv = ajoutFin_r(v, l->suiv);
		return l;
	}
	l = creer(v);
	return l;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste p = l;
	while (!estVide(p))
	{
		if (equalsElement(p->val, v))
		{
			return p;
		}
		p=p->suiv;
	}
	return p;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (!estVide(l) && !equalsElement(l->val,v))
	{
		return cherche_r(v, l->suiv);
	}
	return l;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	if (estVide(l))
	{
		return l;
	}
	if (equalsElement(l->val,v))
	{
		l = l->suiv;
		return l;
	}
	Liste actuel = l;
	Liste suivant = l->suiv;
	while (!estVide(suivant))
	{
		if (equalsElement(v, suivant->val))
		{
			actuel->suiv=suivant->suiv;
			return l;
		}
		actuel=suivant;
		suivant=suivant->suiv;
	}	
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (!estVide(l))
	{
		if (equalsElement(v,l->val))
		{
			l=l->suiv;
			return l;
		}
		else
		{
			l->suiv=retirePremier_r(v, l->suiv);
		}		
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	if (!estVide(l))
	{
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}



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

int numberOfMusic(FILE* f){
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

void readMusic(FILE *f, Music *music){
	music->name=readStringFromFileUntil(f, ',');
	music->artist=readStringFromFileUntil(f, ',');
	music->album=readStringFromFileUntil(f, ',');
	music->genre=readStringFromFileUntil(f, ',');
	fscanf(f, "%d", &music->discNumber);
	fscanf(f, "%di", &music->trackNumber);
	fscanf(f, "%d", &music->year);
};

Music* returnMusic(FILE *f){
	Music *music = (Music*) malloc(sizeof(Music));
	readMusic(f, music);
	return music;
}