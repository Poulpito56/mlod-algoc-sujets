#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef unsigned long long TypeEntier;


TypeEntier factorielle(TypeEntier n) {
    TypeEntier produit = 1;
    
    for (int i = 2; i <= n; i++) {
        produit *= i;
    }
    return produit;
}

int main() {
    for (int i = 1; i <= 15; i++) {
        printf("%i \n", (int)factorielle(i));
    }
    return 0;
}