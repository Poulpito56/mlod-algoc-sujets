#pragma once
#include <stdint.h>


typedef struct {
  uint16_t nblignes;
  uint16_t nbcolonnes;
  int64_t** valeurs;
} Matrice;

Matrice* creer(int64_t valParDef, uint16_t l, uint16_t c);
void supprimer(Matrice* mat);
void matrix_print(Matrice* mat);
void initialiserLigne(int64_t val, int16_t ligne, Matrice *mat);
Matrice* multiplier(Matrice* matrice1,Matrice* matrice2);