#include <stdio.h>
// Función para multiplicar dos matrices 3x3
void multiplicarMatrices(int mat1[3][3], int mat2[3][3], int resultado[3][3]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (k = 0; k < 3; k++) {
                resultado[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Función para imprimir una matriz 3x3
void imprimirMatriz(int matriz[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declarar matrices estáticas
    int matriz1[3][3];
    matriz1[0][0]= 1;
    matriz1[0][1]= 2;
    matriz1[0][2]= 3;
    matriz1[1][0]= 4;
    matriz1[1][1]= 5;
    matriz1[1][2]= 6;
    matriz1[2][0]= 7;
    matriz1[2][1]= 8;
    matriz1[2][2]= 9;
    
    int matriz2[3][3];
    matriz2[0][0]= 9;
    matriz2[0][1]= 8;
    matriz2[0][2]= 7;
    matriz2[1][0]= 6;
    matriz2[1][1]= 5;
    matriz2[1][2]= 4;
    matriz2[2][0]= 3;
    matriz2[2][1]= 2;
    matriz2[2][2]= 1;
    
    int resultado[3][3];

    // Multiplicar las matrices
    multiplicarMatrices(matriz1, matriz2, resultado);
    printf("\nEjercicio 11 (Multiplicación de Matrices) \n");
    // Imprimir el resultado
    printf("\nMatriz 1:\n");
    imprimirMatriz(matriz1);
    printf("\nMatriz 2:\n");
    imprimirMatriz(matriz2);
    printf("\nResultado de la multiplicación:\n");
    imprimirMatriz(resultado);

    return 0;
}
