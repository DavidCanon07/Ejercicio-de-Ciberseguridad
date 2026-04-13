// Parte 4 — Login con Bloqueo por Intentos

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {

    // Usuario y contraseña correctos predefinidos
    string usuarioCorrecto[] = {"admin", "user1", "user2"}; // Array de usuarios válidos
    string contrasenaCorrecta[] = {"HardPass123*", "Pass456!", "Secret789!"}; // Array de contraseñas válidas

    int intentosGenerales = 0; // Contador de intentos generales para bloquear después de 3 intentos fallidos
    string usuarioIngresado, contrasenaIngresada;
    int intentos[] = {0,0,0}; // Array para contar intentos por usuario     
    bool alertaSeguridad[5] = {false, false, false, false, false}; // Array para marcar alertas de seguridad por usuario
    int controlSeguridad = 0; // Tasa de intentos fallidos para activar alerta de seguridad después de 5 intentos seguidos
    float fallidos = 0; 
    float tasa = 0; 
    bool encontrado = false; // Variable para verificar si el usuario fue encontrado
    string historialUsuarios[5]; // Array para almacenar el historial de usuarios ingresados
    string historialContrasenas[5]; // Array para almacenar el historial de contraseñas ingresadas
    string estado[5] = {"FALLIDO", "FALLIDO", "FALLIDO", "FALLIDO", "FALLIDO"};
    int intentosExitosos = 0;



    
   
    while (true) {

        encontrado = false; // Reiniciar la variable encontrado para cada intento de login
       
        if (fallidos >= 5) {
                    cout << "Alerta de seguridad: Se han alcanzado 5 intentos seguidos en total. Se ha enviado un reporte al equipo de seguridad." << endl;
                }


        if (controlSeguridad >= 5) {
                for (int i = 0; i < 5; i++) {
                    if (alertaSeguridad[i] == false) {
                        fallidos++;
                        tasa = (fallidos / 5) * 100; // Calcular la tasa de intentos fallidos
                        if (tasa >= 60) {
                            cout << "Muchos intentos fallidos detectados, se cerrara el sistema por su seguridad." << endl;




                            cout << "\n========== REPORTE DE SEGURIDAD ==========" << endl;
                            for (int i = 0; i < controlSeguridad; i++) {
                                cout << "--- Registro# "<< i+1 << "--- \n Usuario: " << historialUsuarios[i] << "\n | Contrasena: " << historialContrasenas[i] << "\n | Estado: " << estado[i] << endl << "\n-----------------------------------------\n" << endl;}
                            
                            for (int i = 0; i < controlSeguridad; i++) {
                                cout << "Usuario: " << historialUsuarios[i] << " | Estado: " << estado[i] << "\n" << endl;                                
                            }

                            intentosExitosos = abs(fallidos - 5);
                            
                            cout <<"Intentos exitosos: " << intentosExitosos << "\n Tasa de fallo: " << tasa << "%" << "\n ***ALERTA: TASA DE FALLO ALTA - POSIBLE ATAQUE ***" << endl;                                                      
                        }
                    }
                }   
                        if (tasa <= 59) {
                            cout << "tasa se seguridad dentro de lo normal" << endl;  
                            controlSeguridad = 0;
                            fallidos = 0;
                            for (int i = 0; i < 5; i++) {
                                alertaSeguridad[i] = false; // Reiniciar las alertas de seguridad para el próximo ciclo
                            }
                        }
                    
                
            }else if (controlSeguridad > 0) {
            alertaSeguridad[controlSeguridad] = 1;
            cout <<"aumento la seguridad: " << controlSeguridad << endl;
            }
        

        for (int i = 0; i < 3; i++) {
            if (intentos[i] >= 3) {               
                cout << "Alerta de seguridad: Usuario " << usuarioCorrecto[i] << " bloqueado por 3 intentos fallidos." << endl;
                break;              
            }} 

        
        // INICIO DEL PROGRAMA DE LOGIN

        cout << "--- login de usuario ---" << endl;
        cout << "User: ";
        cin >> usuarioIngresado;
        cout << "Password: ";
        cin >> contrasenaIngresada;

        

        for(int i = 0; i < 3; i++) {           
            if (usuarioCorrecto[i] == usuarioIngresado && contrasenaCorrecta[i] == contrasenaIngresada) {
                cout << "Acceso concedido" << endl;
                alertaSeguridad[controlSeguridad] = 1; //marco la ubicacion del usuario correcto en el array de booleanos para que no se cuente como intento confirmado
                historialUsuarios[controlSeguridad] = usuarioIngresado; // Guardo el usuario ingresado en el historial
                historialContrasenas[controlSeguridad] = contrasenaIngresada; // Guardo la contraseña ingresada en el historial
                estado[controlSeguridad] = "CONFIRMADO"; // Marco el estado como confirmado
                 controlSeguridad+=1; // Incremento la posición para el próximo usuario
                 encontrado = true;
                 break;

            }else if(usuarioIngresado == usuarioCorrecto[i] && contrasenaIngresada != contrasenaCorrecta[i]){
                    cout << "Contrasena u usuario incorrecto intente de nuevo." << endl;
                    intentos[i]+=1;
                    cout << "intento para el usuario: " <<usuarioCorrecto[i] << ": " << intentos[i] << endl;
                    alertaSeguridad[controlSeguridad] = 0; // en la ubicacion del numero de intentos se pondra como fallido
                    historialContrasenas[controlSeguridad] = contrasenaIngresada; // Guardo la contraseña ingresada en el historial
                    estado[controlSeguridad] = "FALLIDO"; // Marco el estado como fallido
                    historialUsuarios[controlSeguridad] = usuarioIngresado; // Guardo el usuario ingresado en el historial
                    controlSeguridad+=1;
                    encontrado = true;
                    break;
            } 
        }

        if (encontrado == false) {
            cout << "Usuario no encontrado, intente de nuevo." << endl;
            intentosGenerales+=1;
            cout << "Intentos generales: " << intentosGenerales << endl;
            alertaSeguridad[controlSeguridad] = 0; // en la ubicacion del numero de intentos se pondra como fallido
            historialUsuarios[controlSeguridad] = "USUARIO_NO_ENCONTRADO"; // Guardo el usuario ingresado en el historial
            historialContrasenas[controlSeguridad] = contrasenaIngresada; // Guardo la contraseña ingresada en el historial
            estado[controlSeguridad] = "FALLIDO"; // Marco el estado como fallido
            controlSeguridad+=1;
        }
    }

    
     return 0;   
    }




    

