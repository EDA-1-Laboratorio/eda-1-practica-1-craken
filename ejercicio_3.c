#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para la función sleep() en Linux/Mac (usar <windows.h> y Sleep() en Windows)
//#include <windows.h>

#define FILAS 10
#define COLS 10

int selec;
// 0 = Muerta, 1 = Viva
int mundo[FILAS][COLS];
int siguiente_mundo[FILAS][COLS];

// Inicializa el tablero con algunos patrones predefinidos (o aleatorios)
void inicializarMundo() {
    // Limpiamos todo a 0
    for(int i=0; i<FILAS; i++) 
        for(int j=0; j<COLS; j++) 
            mundo[i][j] = 0;

            printf("\nSeleccione opcion: \n (1)Glider \n(otro)Aleatorio \t");
        scanf("%i", &selec);

    if (selec == 1) {
    // Patrón "Glider" (Deslizador) simple para pruebas
        mundo[1][2] = 1;
        mundo[2][3] = 1;
        mundo[3][1] = 1;
        mundo[3][2] = 1;
        mundo[3][3] = 1;
    } else {
        srand(selec);
            for (int i = 0; i<FILAS; i++) {
                for (int j = 0; j<COLS; j++) {
                    if (rand()%100 <= 25) mundo[i][j] = 1;
                 }
            }
        }
}

void imprimirMundo() {
    // Limpia la consola
    system("clear"); // O system("cls") en Windows
    // system("cls");
    printf("\nEstado Actual:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Imprimimos un caracter visual en lugar de 0 y 1
            printf("%c ", mundo[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("----------------\n");
}

int contarVecinos(int f, int c) {
    int vecinos = 0;

     for (int i = -1; i<=1; i++ ) {
        if (f+i < 0 || f+i > FILAS-1) continue; //Checa limites filas
        for (int j = -1; j<=1; j++) {

            if (c+j < 0 || c+j > COLS-1) continue; //Checa limites columnas
            if ((j==0) && (i==0)) continue; //Se omite a si mismo

            if (mundo[f+i][c+j]==1) vecinos++;//Checa si esta viva
        }
    }
    
    // TODO: Recorrer las 8 celdas alrededor de mundo[f][c]
    // CUIDADO: Debes verificar que los índices no se salgan del arreglo (0 a FILAS-1)
    // Ejemplo de lógica:
    // for (int i = f - 1; i <= f + 1; i++) {
    //    for (int j = c - 1; j <= c + 1; j++) {
    //       ... verifica limites ...
    //       ... si no es la propia celda (f,c) y está viva, vecinos++ ...
    //    }
    // }
    
    return vecinos;
}

void siguienteGeneracion() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            int vecinos = contarVecinos(i, j);

            // Aplicar reglas de Conway en 'siguiente_mundo' (NO modificar 'mundo' aún)
            if (mundo[i][j] == 1) {
                // REGLA 1: Soledad (menos de 2 vecinos) -> Muere
                // REGLA 2: Sobrepoblación (más de 3 vecinos) -> Muere
                // REGLA 3: Estabilidad (2 o 3 vecinos) -> Vive
                
                // TODO: Traducir esto a código if/else asignando a siguiente_mundo[i][j]
                if (vecinos < 2 || vecinos > 3) 
                    siguiente_mundo[i][j] = 0;
                else 
                    siguiente_mundo[i][j] = 1;

            } else {
                // REGLA 4: Reproducción (exactamente 3 vecinos) -> Nace
                if (vecinos == 3) {
                    siguiente_mundo[i][j] = 1;
                     //printf("%i %i nace", i, j);
                }
                // TODO: Completar la lógica para células muertas
            }
        }
    }

    // Copiar el estado siguiente al actual
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            mundo[i][j] = siguiente_mundo[i][j];
        }
    }
}

int main() {
    inicializarMundo();
    int iteraciones = 20; // O infinito while(1)

    for(int k=0; k<iteraciones; k++) {
        imprimirMundo();
        siguienteGeneracion();
        sleep(1); // Pausa para ver la animación
        // Sleep(1);
    }

    return 0;
}

// PREGUNTA: ¿Por qué es obligatoria la matriz siguiente_mundo? ¿Qué pasaría si actualizamos directamente sobre mundo?
