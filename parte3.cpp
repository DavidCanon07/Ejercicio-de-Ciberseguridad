#include <stdio.h>
#include <string.h>

int main() {
    char mensaje[100];   // Variable para almacenar el mensaje a cifrar
    int desplazamiento;  // Variable para almacenar el número de posiciones a desplazar
    int i; // Variable de control para el bucle

    printf("Ingrese cualquier mensaje: ");
    scanf("%s", mensaje);

    printf("Ingrese el desplazamiento: ");
    scanf("%d", &desplazamiento);          

    for (i = 0; i < (int)strlen(mensaje); i++) {    // Bucle para recorrer cada carácter del mensaje
        if (mensaje[i] >= 'a' && mensaje[i] <= 'z') {
            mensaje[i] = (mensaje[i] - 'a' + desplazamiento) % 26 + 'a'; // Cifrado para letras minúsculas
        } else if (mensaje[i] >= 'A' && mensaje[i] <= 'Z') {
            mensaje[i] = (mensaje[i] - 'A' + desplazamiento) % 26 + 'A';  // Cifrado para letras mayúsculas
        } else {
            mensaje[i] = mensaje[i]; // No se modifica el carácter si no es una letra
        }
    }

    printf("El mensaje cifrado es: %s\n", mensaje); // Imprime el mensaje cifrado
    return 0;
}
