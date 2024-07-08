#include <stdio.h>

void sumarMatrices(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas], int resultado[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;
    // Ingresar las dimensiones de la matriz
    while (filas < 2 || columnas < 2 || filas != columnas) {
        printf("\nIntroduce el número de filas: ");
        scanf("%d", &filas);
        printf("\nIntroduce el número de columnas: ");
        scanf("%d", &columnas);

        // Mínimo de filas y columnas
        if (filas < 2 || columnas < 2) {
            printf("\nLa matriz debe tener al menos 2 filas y 2 columnas.\n");
        }

        // Condición para que la matriz sea cuadrada
        if (filas != columnas) {
            printf("\nIngrese el mismo número de filas y columnas para tener una matriz cuadrada\n");
        }
    }

    // Declarar las matrices
    int matriz1[filas][columnas], matriz2[filas][columnas], resultado[filas][columnas];

    // Ingresar los elementos de la matriz 1
    printf("Introduce los elementos de la primera matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Ingresar los elementos de la matriz 2
    printf("Introduce los elementos de la segunda matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Llamo al procedimiento para sumar las matrices
    sumarMatrices(filas, columnas, matriz1, matriz2, resultado);
    printf("\nEjercicio 10 (Resta de Matrices) \n");
    // Llamo al procedimiento para Presentar las matrices ingresadas y su suma //
    printf("\nMatriz 1:\n");
    imprimirMatriz(filas, columnas, matriz1);

    printf("\nMatriz 2:\n");
    imprimirMatriz(filas, columnas, matriz2);

    printf("\nResultado de la resta:\n");
    imprimirMatriz(filas, columnas, resultado);

    return 0;
}
