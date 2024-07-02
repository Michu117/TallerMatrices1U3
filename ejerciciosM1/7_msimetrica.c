#include <stdio.h>
int main() {
    int matriz[3][3];
    matriz[0][0]= 1;
    matriz[0][1]= 2;
    matriz[0][2]= 3;
    matriz[1][0]= 2;
    matriz[1][1]= 4;
    matriz[1][2]= 5;
    matriz[2][0]= 3;
    matriz[2][1]= 5;
    matriz[2][2]= 6;

    // Presentar la matriz original //
    printf("\nMatriz original:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Ejercicio 6 (Presentar la matriz simétrica) \n");
    int transpuesta[3][3];
    // Calcular la matriz traspuesta
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    // Mostrar la matriz traspuesta
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transpuesta[i][j]);
        }
        printf("\n");
    }

    return 0;
}