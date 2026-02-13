#include <stdio.h>
#include <string.h>

// Prototipos de funciones (declaración)
void crearMensaje();
void descifrarMensaje();

int main() {
    int opcion = 0;
    
    while (1) {  //Garantiza un bucle infinito, siempre se cumple la condición    
        printf("\n\t*** ESCÍTALA ESPARTANA ***\n");
        printf("1) Crear mensaje cifrado (Cifrar).\n");
        printf("2) Descifrar mensaje.\n");
        printf("3) Salir.\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {  // El usuario puede elegir que desea hacer en el programa
            case 1:
                crearMensaje();
                break;
            case 2:
                descifrarMensaje();
                break;
            case 3:
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }
    return 0;
}

void crearMensaje() {
    int ren, col, i, j, k = 0;

    printf("\n--- CIFRADO ---\n");
    printf("Ingresar el tamaño de la escítala (Renglones): ");      //Se le pregunta al usuario, las dimensiones de la matriz en la escítala
    scanf("%d", &ren);
    printf("Ingresar el tamaño de la escítala (Columnas/Caras): ");
    scanf("%d", &col);

    char escitala[ren][col];
    char texto[ren*col]; // Arreglo lineal para el texto original, el número de caracteres del arreglo

    printf("Escriba el texto a cifrar (sin espacios): ");
    scanf("%s", texto);

    // PASO 1: Llenar la matriz con el texto original
    // La escítala se escribe a lo largo de la vara (fila por fila en la matriz lógica)
    
    /* TODO: Escribe aquí los bucles anidados para llenar 'escitala[i][j]' 
       usando los caracteres de 'texto'.
       Tip: Necesitas recorrer renglones y luego columnas. */
       
    // ... (Tu código aquí) ...

    for(i=0; i<ren; i++){         // Almacenando los caracteres del arreglo texto en cada uno de los índices de la escítala por reglones, izquierda a derecha
        for(j=0; j<col; j++){
            escitala[i][j]=texto[k++];
        }
    }
    
    printf("El texto cifrado (leído de la tira) es:\n");

    // PASO 2: Leer la matriz para obtener el cifrado
    // Al desenrollar la tira, leemos verticalmente (columna por columna)
    
    /* TODO: Escribe aquí los bucles para imprimir el mensaje cifrado.
       Tip: Ahora el bucle externo debe controlar las columnas y el interno los renglones. */

    // ... (Tu código aquí) ...

    for(i=0; i<col; i++){     // Imprime el texto cifrado de manera lineal, el arreglo escítala columna por columna 
        for(j=0; j<ren; j++){
            printf("%c", escitala[j][i]);
        }
    }
    printf("\n");
}

void descifrarMensaje() {
    int ren, col, i, j, k = 0;

    printf("\n--- DESCIFRADO ---\n");
    printf("Ingresar el tamaño de la escítala (Renglones original): ");  //Por medio de las dimensiones de la matriz, se arma la matriz original
    scanf("%d", &ren);
    printf("Ingresar el tamaño de la escítala (Columnas original): ");
    scanf("%d", &col);

    char escitala[ren][col];
    char texto[ren * col];

    printf("Escriba el texto cifrado: ");
    scanf("%s", texto);

    // PASO 1: Reconstruir la matriz desde la tira cifrada
    // Recuerda: El texto cifrado viene en orden de columnas (vertical),
    // por lo tanto, debemos llenarlo en ese mismo orden.

    /* TODO: Escribe aquí los bucles para llenar la matriz 'escitala'.
       Tip: El orden de los bucles 'for' es inverso al llenado del cifrado normal. 
       Debes llenar columna por columna usando el 'texto' cifrado. */

    // ... (Tu código aquí) ...+

    for(i=0; i<col; i++){     //Cada uno de los caracteres almacenados en los índices del arreglo lineal texto, son asignados en los índices de la escitala, 
        for(j=0; j<ren; j++){         // columna por columna
            escitala[j][i]=texto[k++];
        }
    }
    printf("El texto descifrado es:\n");

    // PASO 2: Leer el mensaje original
    // Una vez reconstruida la matriz, leemos fila por fila normalmente.

    /* TODO: Escribe aquí los bucles para imprimir el mensaje original. */

    // ... (Tu código aquí) ...

    for(i=0; i<ren; i++){      //Imprime el contenido de los índices del arreglo escítala, reglón por reglón
        for(j=0; j<col; j++){
            printf("%c", escitala[i][j]);
        }
    }
    printf("\n");
}

// PREGUNTA: En la implementación se una matriz auxiliar de dimensiones ren × col para realizar la transposición. 
// Si tuvieras una restricción de memoria severa y no pudieras crear esa matriz bidimensional, 
// ¿qué fórmula matemática utilizarías para imprimir el carácter correcto directamente desde el arreglo original texto[] ?
