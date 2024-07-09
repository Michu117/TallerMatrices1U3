#include <stdio.h>

// Función para sumar matrices
void sumarMatrices(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas], int resultado[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Función para convertir un número decimal a hexadecimal
void decimalAHexadecimal(int numero, char *hexadecimal) {
    char hexDigits[] = "0123456789ABCDEF";
    int indice = 0;
    int residuo;
    char temp[10];  // temporal para almacenar los caracteres en orden inverso

    // Divisiones sucesivas
    do {
        residuo = numero % 16;
        temp[indice++] = hexDigits[residuo];
        numero = numero / 16;
    } while (numero > 0);

    // Invertir el orden de los caracteres
    int j = 0;
    for (int i = indice - 1; i >= 0; i--) {
        hexadecimal[j++] = temp[i];
    }
    hexadecimal[j] = '\0';  // Terminar la cadena con el carácter nulo
}

// Función para imprimir matrices en formato hexadecimal
void imprimirMatrizHexadecimal(int filas, int columnas, int matriz[filas][columnas]) {
    char hex[10];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            decimalAHexadecimal(matriz[i][j], hex);
            printf("%s ", hex);
        }
        printf("\n");
    }
}

int main() {
    int filas = 0, columnas = 0;

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
    
    printf("\nEjercicio 14 (Suma de Matrices Resultado Hexadecimal) \n");

    // Llamo al procedimiento para presentar las matrices ingresadas y su suma en hexadecimal
    printf("\nMatriz 1:\n");
    imprimirMatrizHexadecimal(filas, columnas, matriz1);

    printf("\nMatriz 2:\n");
    imprimirMatrizHexadecimal(filas, columnas, matriz2);

    printf("\nResultado de la suma:\n");
    imprimirMatrizHexadecimal(filas, columnas, resultado);

    return 0;
}
