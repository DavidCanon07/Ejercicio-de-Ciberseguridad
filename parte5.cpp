// parte5.cpp
// Parte 5: Generador de Contraseña Aleatoria

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Semilla para números aleatorios

    // --- 1. Pedir longitud ---
    int longitud;
    cout << "¿Cuántos caracteres desea? (8-20): ";
    cin >> longitud;

    if (longitud < 8 || longitud > 20) {
        cout << "Longitud inválida. Usando 12 por defecto." << endl;
        longitud = 12;
    }

    // --- 2. Definir caracteres disponibles ---
    string minusculas = "abcdefghijklmnopqrstuvwxyz";
    string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numeros    = "0123456789";
    string especiales = "!@#$%&*";

    // --- 3. Garantizar al menos uno de cada tipo ---
    string password = "";
    password += mayusculas[rand() % 26];
    password += numeros[rand() % 10];
    password += especiales[rand() % 7];

    // --- 4. Rellenar el resto con minúsculas ---
    for (int i = 3; i < longitud; i++) {
        password += minusculas[rand() % 26];
    }

    // --- 5. Mostrar resultado ---
    cout << "Contraseña generada: " << password << endl;

    return 0;
}