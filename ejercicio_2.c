#include <stdio.h>

// Definimos un tamaño máximo para facilitar la gestión de memoria en esta práctica
#define MAX 20

void generarEspiral(int n, int matriz[MAX][MAX]) {
    int valor = 1, i,j;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    
    while (valor <= n * n) {
        for(i=left; i<=right; i++){
            matriz[top][i]=valor++;
        }
        top++;
        
        for(i=top; i<=bottom; i++){
            matriz[i][right]=valor++;
        }
        right--;
        
        if (top <= bottom) {
            for(i=right; i>=left; i--){
                matriz[bottom][i]=valor++;
            }
            bottom--;
        }

        if (left <= right) {
            for(i=bottom; i>=top; i--){
                matriz[i][left]=valor++;
            }
            left++;
        }
    }
}

void imprimirMatriz(int n, int matriz[MAX][MAX]) {
    printf("\n--- Matriz Espiral de %dx%d ---\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]); // %4d para alinear columnas
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[MAX][MAX];

    printf("Ingrese el tamaño N de la matriz (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: El tamaño excede el máximo permitido.\n");
        return 1;
    }

    generarEspiral(n, matriz);
    imprimirMatriz(n, matriz);

    return 0;
}

// PREGUNTA: ¿Qué sucede si se omite la verificación if (top <= bottom) -linea 21- dentro del bucle?
