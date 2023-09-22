#include "produitMatrice.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

Matrice* creer(int64_t valParDef, uint16_t l, uint16_t c) {
  Matrice* mat = (Matrice*) malloc(sizeof(Matrice));
  mat->nblignes = l;
  mat->nbcolonnes = c;
 // int64_t* ptab[c];
  int64_t** val = (int64_t**) malloc(sizeof(int64_t*)*l);
  mat->valeurs = val;
  for (int i = 0; i < l; i++)
  {
    int64_t* pl = (int64_t*) malloc(sizeof(int64_t)*c);
    val[i] = pl;
    for (int j = 0; j < c; j++)
    {
      val[i][j] = valParDef;
    }
    
  }
  return mat;
};

void supprimer(Matrice* mat) {
  for (int i = 0; i < mat->nblignes; i++)
  {
    free((mat->valeurs)[i]);
  }
  free(mat->valeurs);
  free(mat);
  mat=NULL;
}

void initialiserLigne(int64_t val, int16_t ligne, Matrice *mat) {
  for (int i = 0; i < mat->nbcolonnes; i++)
  {
    (mat->valeurs)[ligne][i]=val;
  }
  
};

Matrice* multiplier(Matrice* matrice1,Matrice* matrice2) {
  Matrice* matriceResultat = creer(1, matrice1->nblignes, matrice2->nbcolonnes);
  for (int i = 0; i < matriceResultat->nblignes; i++)
  {
    for (int j = 0; j < matriceResultat->nbcolonnes; j++)
    {
      int64_t somme =0;
      for (int k = 0; k < matrice1->nbcolonnes; k++)
      {
        somme += (matrice1->valeurs)[i][k]*(matrice2->valeurs)[k][j];
      }
      (matriceResultat->valeurs)[i][j] = somme;
    }
    
  }
  return matriceResultat;
};

void matrix_print(Matrice* mat){
  for (int i = 0; i < mat->nblignes; i++)
  {
    for (int j = 0; j < mat->nbcolonnes; j++)
    {
      printf("%ld ", (mat->valeurs)[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}