#include <stdio.h>

#define MAX_DIM 10  // Tamaño máximo permitido para las matrices

// Función para dividir dos matrices de dimensiones arbitrarias
void dividirMatrices(int mat1[][MAX_DIM], int mat2[][MAX_DIM], float resultado[][MAX_DIM], int filas, int cols) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            if (mat2[i][j] != 0) {
                resultado[i][j] = (float)mat1[i][j] / mat2[i][j];
            } else {
                // Manejo de división por cero, aquí se podría elegir el comportamiento deseado
                resultado[i][j] = 0.0;  // Por ejemplo, asignar un valor específico
            }
        }
    }
}

// Función para imprimir una matriz de dimensiones arbitrarias
void imprimirMatriz(float matriz[][MAX_DIM], int filas, int cols) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, cols;
    
    printf("Ingrese el número de filas y columnas de las matrices (filas x columnas): ");
    scanf("%d %d", &filas, &cols);

    // Declarar matrices estáticas
    int matriz1[MAX_DIM][MAX_DIM], matriz2[MAX_DIM][MAX_DIM];
    float resultado[MAX_DIM][MAX_DIM];
    int i, j;

    // Leer elementos de la matriz 1
    printf("Ingrese los elementos de la matriz 1 (%d x %d):\n", filas, cols);
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Leer elementos de la matriz 2
    printf("Ingrese los elementos de la matriz 2 (%d x %d):\n", filas, cols);
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Dividir las matrices
    dividirMatrices(matriz1, matriz2, resultado, filas, cols);

    // Imprimir el resultado
    printf("\nResultado de la division:\n");
    imprimirMatriz(resultado, filas, cols);

    return 0;
}
