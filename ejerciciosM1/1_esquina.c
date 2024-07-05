#include <stdio.h>
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

    int matriz[filas][columnas];

    // Ingresar los valores de cada posición en la matriz //
    printf("Introduce los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Presentar la matriz original //
    printf("\nMatriz original:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
    printf("Ejercicio 1 (Presentar los 4 elementos de la esquinas de la matriz) \n");

    printf("\n");
    // Presentar los 4 elementos de las esquinas //
    printf("\nElementos de las esquinas:\n");
    printf("Esquina superior izquierda: %d\n", matriz[0][0]);
    printf("Esquina superior derecha: %d\n", matriz[0][columnas - 1]);
    printf("Esquina inferior izquierda: %d\n", matriz[filas - 1][0]);
    printf("Esquina inferior derecha: %d\n", matriz[filas - 1][columnas - 1]);

    return 0;
}
