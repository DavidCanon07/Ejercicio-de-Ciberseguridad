// Parte 2 — Login con Bloqueo por Intentos

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Usuario y contraseña correctos predefinidos
    string usuarioCorrecto = "admin";
    string contrasenaCorrecta = "HardPass123*";

    string usuarioIngresado, contrasenaIngresada;
    int intentos = 0;          
    bool acceso = false;   

    
    while (intentos < 3 && !acceso) {
        cout << "--- Intento " << (intentos + 1) << " de 3 ---" << endl;

        cout << "User: ";
        cin >> usuarioIngresado;
        cout << "Password: ";
        cin >> contrasenaIngresada;

        
        if (usuarioIngresado == usuarioCorrecto && contrasenaIngresada == contrasenaCorrecta) {
            cout << "Acceso concedido" << endl;
            acceso = true; 
        } else {
            cout << "Credenciales incorrectas." << endl;
            intentos++; 
        }
    }

    
    if (!acceso) {
        cout << "CUENTA BLOQUEADA" << endl;
    }

    return 0;
}
