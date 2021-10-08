// NuevoProSO.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include <iostream>
#include "BitacoraP.h";
#include "ControlPrincipal.h";
/*#include "PrioridadProceso.h";*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define limite 5

#include <chrono>
#include <thread>
using namespace std::chrono_literals;
using namespace std;
ControlPrincipal procesos = ControlPrincipal();

int main() {
    int op;
    bool exit;
    do {
        op = 0;
        exit = false;
        cout << "*****BIENVENIDO AL SIMULADOR PCB***** " << endl;
        cout << "1--> LEER ARCHIVO " << endl;
        cout << "2--> ATENDER PROCESOS " << endl;
        cout << "3--> IMPRIMIR BITACORA " << endl;
        cout << "4--> SALIR " << endl;
        cout << "INGRESE LA OPCI�N QUE DESEE " << endl;
        cin >> op;

        switch (op) {

        case 1:
            procesos.LecturadeFichero();
            break;
        case 2:
            system("cls");
            procesos.ControlDeProcesamientoCentral();
            break;
        case 3:
            procesos.mostrarProcesosContenedroTXT();

            break;
        case 4:
            procesos.mostrarProcesos();
            break;
        case 5:
            exit = true;

        default:
            cout << endl << "Ingreso una opcion incorrecta" << endl << endl;

        }
    } while (!exit);
    return 0;

}


