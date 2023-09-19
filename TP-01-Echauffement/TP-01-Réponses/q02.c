#include <stdio.h>

int estNombreParfait(int n) {
    int sommeDiviseurs = 0;
    
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sommeDiviseurs += i;
        }
    }
    
    if (sommeDiviseurs == n) {
        return 1; // Le nombre est parfait
    } else {
        return 0; // Le nombre n'est pas parfait
    }
}

int main() {
    int nombre;
    
    printf("Entrez un nombre : ");
    scanf("%d", &nombre);
    
    for (int i = 1; i <= nombre; i++) {
        if (estNombreParfait(i)) {
            printf("%d est un nombre parfait.\n", i);
        }
    }
    
    return 0;
}