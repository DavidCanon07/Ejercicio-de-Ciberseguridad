#include <iostream>
using namespace std;

int main() {

    string password;
    bool validacion[4] = {false, false, false, false}; // array booleano para validar cada criterio de la contraseña
    int valor_validacion = 0; // variable para contar el número de validaciones cumplidas
    string caracteres_especiales[7] = {"!", "@", "#", "$", "%", "&", "*"}; // array de caracteres especiales permitidos


    cout << "ingrese su contrasena: ";
    cin >> password;


    //Validar el largo de la contraseña
    if (password.length() >= 8){
        validacion[0] = true;
    }

    //Validar que la contraseña tenga al menos una letra mayúscula
    for (string::size_type i = 0; i < password.length(); i++){
        if(password[i] >= 'A' && password[i] <= 'Z'){
            validacion[1] = true;

        } 
    }

    //Validar que la contraseña tenga al menos un número
    for (string::size_type i = 0; i < password.length(); i++){
        if(password[i] >= '0' && password[i] <= '9'){
            validacion[2] = true;

        }
    }

    //Validar que la contraseña tenga al menos un caracter especial
    for(string::size_type i = 0; i < password.length(); i++){
        for(int x = 0; x < 7; x++){
            if(password[i] == caracteres_especiales[x][0]){
                validacion[3] = true;
    
            }
        }
    }

    valor_validacion = validacion[0] + validacion[1] + validacion[2] + validacion[3]; // sumar el número de validaciones cumplidas

    // Evalua el valor de seguridad de la contaseña y retorna el resultado
    if(valor_validacion >= 0 && valor_validacion <= 2) {
        cout << "Su contrasena es: 'DEBIL'" << endl;
    }else if(valor_validacion == 3){
        cout << "Su contrasena es: 'MEDIA'" << endl;
    }else {
        cout << "Su contrasena es: 'FUERTE'" << endl;
    }

    return 0;
}