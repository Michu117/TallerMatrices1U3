#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para verificar que los números no se repiten
int buscar_num(int matriz[], int numero, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        if (matriz[i] == numero) {
            return 1;
        }
    }
    return 0;
}

// Método Burbuja Para ordenar un arreglo //
void ordenar(int tamaño, int matriz[]) {
    int temp;
    for (int i = 0; i < tamaño - 1; i++) {
        for (int j = 0; j < tamaño - i - 1; j++) {
            if (matriz[j] > matriz[j + 1]) {
                temp = matriz[j];
                matriz[j] = matriz[j + 1];
                matriz[j + 1] = temp;
            }
        }
    }
}

// Función para generar números aleatorios únicos
void generar_numeros(int tamaño, int matriz[]) {
    int numero;
    for (int i = 0; i < tamaño; i++) {
        do {
            numero = (rand() % 13) + 1; // Genera un número aleatorio entre 1 y 13
        } while (buscar_num(matriz, numero, i) == 1); // Verifica si el número ya está en la matriz
        matriz[i] = numero; // Asigna el número a la matriz
    }
}


int main() {
    const int NUM_PALOS = 4;
    const int NUM_CARTAS = 13;
    srand(time(0));

    int matriz_madre[NUM_PALOS][NUM_CARTAS];
    int matriz1[NUM_CARTAS];
    int matriz2[NUM_CARTAS];
    int matriz3[NUM_CARTAS];
    int matriz4[NUM_CARTAS];

    generar_numeros(NUM_CARTAS, matriz1);
    generar_numeros(NUM_CARTAS, matriz2);
    generar_numeros(NUM_CARTAS, matriz3);
    generar_numeros(NUM_CARTAS, matriz4);

    // Copiar los números aleatorios a la matriz madre
    for (int i = 0; i < NUM_CARTAS; i++) {
        matriz_madre[0][i] = matriz1[i];
        matriz_madre[1][i] = matriz2[i];
        matriz_madre[2][i] = matriz3[i];
        matriz_madre[3][i] = matriz4[i];
    }

    // Imprime la matriz con números aleatorios
    printf("Las cartas en desorden se ubican asi:\n");
    for (int i = 0; i < NUM_PALOS; i++) {
        for (int j = 0; j < NUM_CARTAS; j++) {
            if (matriz_madre[i][j] == 1 || matriz_madre[i][j] == 11 || matriz_madre[i][j] == 12 || matriz_madre[i][j] == 13) {
                if (matriz_madre[i][j] == 1) {
                    printf("A");
                } else if (matriz_madre[i][j] == 11) {
                    printf("J");
                } else if (matriz_madre[i][j] == 12) {
                    printf("Q");
                } else if (matriz_madre[i][j] == 13) {
                    printf("K");
                }
            } else {
                printf("%d", matriz_madre[i][j]);
            }
            printf("%c ", 3 + i);
        }
        printf("\n");
    }

    // Ordenar los arreglos individuales
    ordenar(NUM_CARTAS, matriz1);
    ordenar(NUM_CARTAS, matriz2);
    ordenar(NUM_CARTAS, matriz3);
    ordenar(NUM_CARTAS, matriz4);

    // Rellena la matriz madre con los números ordenados
    for (int i = 0; i < NUM_CARTAS; i++) {
        matriz_madre[0][i] = matriz1[i];
        matriz_madre[1][i] = matriz2[i];
        matriz_madre[2][i] = matriz3[i];
        matriz_madre[3][i] = matriz4[i];
    }

    // Imprime los valores de la matriz ordenados
    printf("\nLas cartas en orden se ubican asi:\n");
    for (int i = 0; i < NUM_PALOS; i++) {
        for (int j = 0; j < NUM_CARTAS; j++) {
            if (matriz_madre[i][j] == 1 || matriz_madre[i][j] == 11 || matriz_madre[i][j] == 12 || matriz_madre[i][j] == 13) {
                if (matriz_madre[i][j] == 1) {
                    printf("A");
                } else if (matriz_madre[i][j] == 11) {
                    printf("J");
                } else if (matriz_madre[i][j] == 12) {
                    printf("Q");
                } else if (matriz_madre[i][j] == 13) {
                    printf("K");
                }
            } else {
                printf("%d", matriz_madre[i][j]);
            }
            printf("%c ", 3 + i);
        }
        printf("\n");
    }

    return 0;
}
