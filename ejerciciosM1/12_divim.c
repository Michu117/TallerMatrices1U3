#include <stdio.h>
// Función para calcular el determinante de una matriz 3x3
float determinante(float matriz[3][3]) {
    return matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) -
           matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) +
           matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
}

// Función para calcular la matriz adjunta
void adjunta(float matriz[3][3], float adj[3][3]) {
    adj[0][0] =  matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1];
    adj[0][1] = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]);
    adj[0][2] =  matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0];

    adj[1][0] = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]);
    adj[1][1] =  matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0];
    adj[1][2] = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]);

    adj[2][0] =  matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1];
    adj[2][1] = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]);
    adj[2][2] =  matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
}

// Función para calcular la matriz inversa
void inversa(float matriz[3][3], float inversa[3][3]) {
    float det = determinante(matriz);
    if (det == 0) {
        printf("La matriz no tiene inversa.\n");
        return;
    }
    float adj[3][3];
    adjunta(matriz, adj);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inversa[i][j] = adj[i][j] / det;
        }
    }
}

// Función para multiplicar dos matrices 3x3
void multiplicar(float matriz1[3][3], float matriz2[3][3], float resultado[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[j][k];
            }
        }
    }
}

int main() {
    float matriz1[3][3];
    matriz1[0][0]= 11;
    matriz1[0][1]= 25;
    matriz1[0][2]= 34;
    matriz1[1][0]= 45;
    matriz1[1][1]= 56;
    matriz1[1][2]= 61;
    matriz1[2][0]= 71;
    matriz1[2][1]= 82;
    matriz1[2][2]= 91;
    

    float matriz2[3][3];
    matriz2[0][0]= 10;
    matriz2[0][1]= 15;
    matriz2[0][2]= 3;
    matriz2[1][0]= 8;
    matriz2[1][1]= 7;
    matriz2[1][2]= 6;
    matriz2[2][0]= 7;
    matriz2[2][1]= 8;
    matriz2[2][2]= 9;


    float inv[3][3];
    float resultado[3][3];

    inversa(matriz2, inv);
    multiplicar(matriz1, inv, resultado);
    printf("\nEjercicio 12 (División de Matrices) \n");
    printf("Resultado de la division de las dos matrices:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
