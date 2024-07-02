#include <stdio.h>

#define MAX_DIM 10  // Máximo tamaño permitido para las dimensiones de las matrices

// Función para multiplicar dos matrices de dimensiones arbitrarias
void multiplicarMatrices(int mat1[][MAX_DIM], int mat2[][MAX_DIM], int resultado[][MAX_DIM], int filas1, int cols1, int cols2) {
    int i, j, k;
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < cols2; j++) {
            resultado[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                resultado[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Función para imprimir una matriz de dimensiones arbitrarias
void imprimirMatriz(int matriz[][MAX_DIM], int filas, int cols) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas1, cols1, filas2, cols2;

    printf("Ingrese el número de filas y columnas de la matriz 1 (filas x columnas): ");
    scanf("%d %d", &filas1, &cols1);

    printf("Ingrese el número de filas y columnas de la matriz 2 (filas x columnas): ");
    scanf("%d %d", &filas2, &cols2);

    // Verificar que las matrices sean multiplicables
    if (cols1 != filas2) {
        printf("No se pueden multiplicar las matrices. Las dimensiones no son válidas.\n");
        return 1;
    }

    // Declarar matrices estáticas
    int matriz1[MAX_DIM][MAX_DIM], matriz2[MAX_DIM][MAX_DIM], resultado[MAX_DIM][MAX_DIM];
    int i, j;

    // Leer elementos de la matriz 1
    printf("Ingrese los elementos de la matriz 1 (%d x %d):\n", filas1, cols1);
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Leer elementos de la matriz 2
    printf("Ingrese los elementos de la matriz 2 (%d x %d):\n", filas2, cols2);
    for (i = 0; i < filas2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Multiplicar las matrices
    multiplicarMatrices(matriz1, matriz2, resultado, filas1, cols1, cols2);

    // Imprimir el resultado
    printf("\n");
    printf("Matriz 1 \n");
    imprimirMatriz(matriz1, filas1, cols1);
    printf("\nMatriz 2 \n");
    imprimirMatriz(matriz2, filas2, cols2);
    printf("\nResultado de la multiplicacion:\n");
    imprimirMatriz(resultado, filas1, cols2);

    return 0;
}
