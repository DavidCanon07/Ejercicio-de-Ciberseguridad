#include <iostream>
#include <string>
using namespace std;
int main() {
    string mensaje;
    int desplazamiento, i;
    
    cout << "Ingrese cualquier mensaje: ";
    cin >> mensaje;

    cout << "Ingrese el desplazamiento: ";
    cin >> desplazamiento;          

    for (i = 0; i < mensaje.length(); i++) {    // Bucle para recorrer cada carácter del mensaje
        if (mensaje[i] >= 'a' && mensaje[i] <= 'z') {
            mensaje[i] = (mensaje[i] - 'a' + desplazamiento) % 26 + 'a'; // Cifrado para letras minúsculas
        } else if (mensaje[i] >= 'A' && mensaje[i] <= 'Z') {
            mensaje[i] = (mensaje[i] - 'A' + desplazamiento) % 26 + 'A';  // Cifrado para letras mayúsculas
        } else {
            mensaje[i] = mensaje[i]; // No se modifica el carácter si no es una letra
        }
    }

    cout << "El mensaje cifrado es: " << mensaje << endl; // Imprime el mensaje cifrado
    return 0;
}
