#include "produitMatrice.h"
#include <stdint.h>
#include <stdio.h>

void matrix_mult(int64_t matriceResultat[5][5],int64_t matrice1[][5],int64_t matrice2[][5]) {
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      int64_t somme =0;
      for (int k = 0; k < 5; k++)
      {
        somme += matrice1[i][k]*matrice2[k][j];
      }
      matriceResultat[i][j] = somme;
    }
    
  }
  
};

void matrix_print(int64_t matriceResultat[5][5]){
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%ld ", matriceResultat[i][j]);
    }
    printf("\n");
  }
}