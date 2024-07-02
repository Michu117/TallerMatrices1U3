#include <stdio.h>
// Función para calcular el determinante de una matriz 3x3
float determinante(float matriz[3][3]) {
    return matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) -
           matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) +
           matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
}

// Función para calcular la adjunta de una matriz 3x3
void adjunta(float matriz[3][3], float adj[3][3]) {
    adj[0][0] = (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]);
    adj[0][1] = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]);
    adj[0][2] = (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    adj[1][0] = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]);
    adj[1][1] = (matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0]);
    adj[1][2] = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]);

    adj[2][0] = (matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1]);
    adj[2][1] = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]);
    adj[2][2] = (matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0]);
}
int main() {
    // Declarar e inicializar una matriz de 3x3
    float matriz5[3][3];
    matriz5[0][0]= 2;
    matriz5[0][1]= -1;
    matriz5[0][2]= 0;
    matriz5[1][0]= 1;
    matriz5[1][1]= 3;
    matriz5[1][2]= 4;
    matriz5[2][0]= 0;
    matriz5[2][1]= -2;
    matriz5[2][2]= 5;

    // Presentar la matriz original //
    printf("\nMatriz original:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%6.2f ", matriz5[i][j]);
        }
        printf("\n");
    }

    // Calcular el determinante de la matriz
    float det = determinante(matriz5);

    if (det == 0) {
        printf("\nLa matriz no tiene inversa porque su determinante es 0.\n");
        return -1;
    }

    // Calcular la matriz adjunta
    float adj[3][3];
    adjunta(matriz5, adj);

    // Calcular la inversa dividiendo la adjunta por el determinante
    float inversa[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inversa[i][j] = adj[i][j] / det;
        }
    }
    printf("\n");
    printf("Ejercicio 5 (Presentar la matriz inversa) \n");
    printf("\n");
    // Imprimir la matriz inversa
    printf("\nLa matriz inversa es:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%6.2f ", inversa[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}