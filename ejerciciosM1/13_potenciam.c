#include <stdio.h>

// Función para multiplicar dos matrices de 3x3
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

// Función para copiar una matriz en otra
void copiarMatriz(int origen[3][3], int destino[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

// Función para imprimir una matriz
void imprimirMatriz(int matriz[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para calcular la potencia de una matriz
void potenciaMatriz(int matriz[3][3], int resultado[3][3], int exponente) {
    int temp[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == j)
                resultado[i][j] = 1;  // Diagonal principal 1
            else
                resultado[i][j] = 0;
        }
    }

    // Algoritmo para calcular la potencia
    while (exponente > 0) {
        if (exponente % 2 != 0) {
            multiplicarMatrices(resultado, matriz, temp);
            copiarMatriz(temp, resultado);
        }
        multiplicarMatrices(matriz, matriz, temp);
        copiarMatriz(temp, matriz);
        exponente /= 2;
    }
}

int main() {
    int matriz[3][3];
    int resultado[3][3];
    int i, j, exponente;

    // Leer elementos de la matriz
    printf("Ingrese los elementos de la matriz (3 x 3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Pedir el exponente
    printf("Ingrese el exponente para calcular la potencia de la matriz: ");
    scanf("%d", &exponente);

    // Calcular la potencia de la matriz
    potenciaMatriz(matriz, resultado, exponente);

    // Imprimir el resultado
    printf("\nResultado de la potencia de la matriz:\n");
    imprimirMatriz(resultado);

    return 0;
}
