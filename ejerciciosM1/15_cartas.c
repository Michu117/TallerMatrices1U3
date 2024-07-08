#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar números aleatorios únicos del 1 al 13
void generar_numeros_aleatorios(int arreglo[], int tam) {
    int numeros_disponibles[tam];
    int indice, num_generado;

    // Inicializar los números disponibles del 1 al tam
    for (indice = 0; indice < tam; ++indice) {
        numeros_disponibles[indice] = indice + 1;
    }

    // Generar números aleatorios únicos
    for (indice = 0; indice < tam; ++indice) {
        int posicion = rand() % (tam - indice);
        num_generado = numeros_disponibles[posicion];
        arreglo[indice] = num_generado;

        // Eliminar el número generado de los disponibles
        numeros_disponibles[posicion] = numeros_disponibles[tam - indice - 1];
    }
}

// Función para ordenar un arreglo de menor a mayor
void ordenar_arreglo(int arreglo[], int tam) {
    int i, j, temp;
    for (i = 0; i < tam - 1; ++i) {
        for (j = i + 1; j < tam; ++j) {
            if (arreglo[i] > arreglo[j]) {
                temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
}

// Función para imprimir un arreglo de cartas con su etiqueta de palo
void imprimir_arreglo(int arreglo[], int tam, char palo) {
    for (int i = 0; i < tam; ++i) {
        printf("%d%c ", arreglo[i], palo);
    }
    printf("\n");
}

int main() {
    const int NUM_PALOS = 4;
    const int NUM_CARTAS = 13;

    int picas[NUM_CARTAS];
    int corazones[NUM_CARTAS];
    int treboles[NUM_CARTAS];
    int diamantes[NUM_CARTAS];

    srand(time(NULL)); // Inicializar la semilla para números aleatorios

    // Generar y mostrar los arreglos de cartas para cada palo (sin ordenar)
    generar_numeros_aleatorios(picas, NUM_CARTAS);
    generar_numeros_aleatorios(corazones, NUM_CARTAS);
    generar_numeros_aleatorios(treboles, NUM_CARTAS);
    generar_numeros_aleatorios(diamantes, NUM_CARTAS);
    printf("\nEjercicio 15 (Ordenar Cartas) \n");
    printf("Arreglos generados sin ordenar:\n");
    printf("Picas: ");
    imprimir_arreglo(picas, NUM_CARTAS, 'P');
    printf("Corazones: ");
    imprimir_arreglo(corazones, NUM_CARTAS, 'C');
    printf("Treboles: ");
    imprimir_arreglo(treboles, NUM_CARTAS, 'T');
    printf("Diamantes: ");
    imprimir_arreglo(diamantes, NUM_CARTAS, 'D');
    printf("\n");

    // Ordenar los arreglos de cada palo
    ordenar_arreglo(picas, NUM_CARTAS);
    ordenar_arreglo(corazones, NUM_CARTAS);
    ordenar_arreglo(treboles, NUM_CARTAS);
    ordenar_arreglo(diamantes, NUM_CARTAS);
    
    // Imprimir la matriz de cartas ordenadas
    printf("Arreglos ordenados:\n");
    printf("Picas: ");
    imprimir_arreglo(picas, NUM_CARTAS, 'P');
    printf("Corazones: ");
    imprimir_arreglo(corazones, NUM_CARTAS, 'C');
    printf("Treboles: ");
    imprimir_arreglo(treboles, NUM_CARTAS, 'T');
    printf("Diamantes: ");
    imprimir_arreglo(diamantes, NUM_CARTAS, 'D');

    return 0;
}
