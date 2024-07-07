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

    printf("Ejercicio 4 (Presentar los elementos que no esten en las esquinas de la matriz) \n");

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // Condición para verificar si el elemento no está en una esquina
            if (!((i == 0 && j == 0) || 
                  (i == 0 && j == columnas - 1) || 
                  (i == filas - 1 && j == 0) || 
                  (i == filas - 1 && j == columnas - 1))) {
                printf("%d ", matriz[i][j]);
            }
        }
    }

    return 0;
}
