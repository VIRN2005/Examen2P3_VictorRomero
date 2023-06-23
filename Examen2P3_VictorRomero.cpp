#include <iostream>
using namespace std;
#include "Tabla.h"

void menu() {
	Tabla tabla;

	int opcion;
	do {
		cout << "--MENU--" << endl;
		cout << "1) Cargar Archivo de Registro" << endl;
		cout << "2) Imprimir Tabla" << endl;
		cout << "3) Fusión de Columnas" << endl;
		cout << "4) Guardar Fusión de Columnas" << endl;
		cout << "5) Salir" << endl;
		cout << "Ingrese la opción: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			tabla.cargarArchivoRegistros();
			break;
		case 2:
			tabla.imprimirTabla();
			break;
		case 3:
			tabla.fusionarColumnas();
			break;
		case 4:
			tabla.guardarFusionColumnas();
			break;
		case 5:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
			break;
		}

		cout << endl;
	} while (opcion != 5);
}

int main() {
	menu();
}