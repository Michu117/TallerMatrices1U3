#include <stdio.h>

#define MAX_DIM 10  // Tamaño máximo permitido para la matriz

// Función para multiplicar dos matrices //
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

// Función para copiar una matriz en otra
void copiarMatriz(int origen[][MAX_DIM], int destino[][MAX_DIM], int filas, int cols) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

// Función para imprimir una matriz
void imprimirMatriz(int matriz[][MAX_DIM], int filas, int cols) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para calcular la potencia de una matriz
void potenciaMatriz(int matriz[][MAX_DIM], int resultado[][MAX_DIM], int filas, int cols, int exponente) {
    int temp[MAX_DIM][MAX_DIM];
    int i, j;

    
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            if (i == j)
                resultado[i][j] = 1;  // Diagonal principal 1
            else
                resultado[i][j] = 0;
        }
    }

    // Algoritmo para calcular la potencia
    while (exponente > 0) {
        if (exponente % 2 != 0) {
            multiplicarMatrices(resultado, matriz, temp, filas, cols, cols);
            copiarMatriz(temp, resultado, filas, cols);
        }
        multiplicarMatrices(matriz, matriz, temp, filas, cols, cols);
        copiarMatriz(temp, matriz, filas, cols);
        exponente /= 2;
    }
}

int main() {
    int filas, cols, exponente;
    
    printf("Ingrese el número de filas y columnas de la matriz (cuadrada): ");
    scanf("%d", &filas);
    cols = filas;

    int matriz[MAX_DIM][MAX_DIM];
    int resultado[MAX_DIM][MAX_DIM];
    int i, j;

    // Leer elementos de la matriz
    printf("Ingrese los elementos de la matriz (%d x %d):\n", filas, cols);
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Pedir el exponente
    printf("Ingrese el exponente para calcular la potencia de la matriz: ");
    scanf("%d", &exponente);

    // Calcular la potencia de la matriz
    potenciaMatriz(matriz, resultado, filas, cols, exponente);

    // Imprimir el resultado
    printf("\nResultado de la potencia de la matriz:\n");
    imprimirMatriz(resultado, filas, cols);

    return 0;
}
