#ifndef TABLAH
#define TABLAH

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include "Columna.h"

using namespace std;

class Tabla {
private:
	Columna<string>* nombres;
	Columna<string>* apellidos;
	Columna<int>* edades;
	Columna<float>* notasExamenP;
	Columna<float>* notasAcumulativo;
	Columna<float>* notasExamenF;

public:
	//Constructor
	Tabla() {
		nombres = new Columna<string>();
		apellidos = new Columna<string>();
		edades = new Columna<int>();
		notasExamenP = new Columna<float>();
		notasAcumulativo = new Columna<float>();
		notasExamenF = new Columna<float>();
	}

	//Destructor
	~Tabla() {
		delete nombres;
		delete apellidos;
		delete edades;
		delete notasExamenP;
		delete notasAcumulativo;
		delete notasExamenF;
	}

	//Cargar los datos del TXT
	void cargarArchivoRegistros() {
		ifstream archivo("RegistrosUNITEC.txt");
		if (!archivo) {
			cout << "No se pudo abrir el archivo de registros." << endl;
			return;
		}

		string linea;
		while (getline(archivo, linea)) {
			stringstream ss(linea);
			string nombre, apellido, edadStr, notaExamenPStr, notaAcumulativoStr, notaExamenFStr;

			if (getline(ss, nombre, ',') && getline(ss, apellido, ',') && getline(ss, edadStr, ',') &&
				getline(ss, notaExamenPStr, ',') && getline(ss, notaAcumulativoStr, ',') &&
				getline(ss, notaExamenFStr, ',')) {
				nombres->agregarDato(nombre);
				apellidos->agregarDato(apellido);
				edades->agregarDato(stoi(edadStr));
				notasExamenP->agregarDato(stof(notaExamenPStr));
				notasAcumulativo->agregarDato(stof(notaAcumulativoStr));
				notasExamenF->agregarDato(stof(notaExamenFStr));
			}
		}

		archivo.close();
		cout << "Archivo de registros cargado correctamente." << endl;
	}

	//Imprimir todos los valores del TXT
	void imprimirTabla() {
		if (nombres->obtenerDatos().empty()) {
			cout << "No existe la tabla, abra el archivo de registros." << endl;
			return;
		}
		else {
			cout << "Tabla de Registros:" << endl;

			cout << "|   Nombres   |  Apellidos  |  Edades  | Nota P | Nota Acum | Nota F |" << endl;

			vector<string>& nombresDatos = nombres->obtenerDatos();
			vector<string>& apellidosDatos = apellidos->obtenerDatos();
			vector<int>& edadesDatos = edades->obtenerDatos();
			vector<float>& notasExamenPDatos = notasExamenP->obtenerDatos();
			vector<float>& notasAcumulativoDatos = notasAcumulativo->obtenerDatos();
			vector<float>& notasExamenFDatos = notasExamenF->obtenerDatos();

			size_t numRegistros = nombresDatos.size();
			for (size_t i = 0; i < numRegistros; i++) {
				cout << "| " << left << setw(12) << nombresDatos[i] << "| " << setw(12) << apellidosDatos[i] << "| "
					<< setw(8) << edadesDatos[i] << " | " << setw(6) << notasExamenPDatos[i] << " | " << setw(10)
					<< notasAcumulativoDatos[i] << " | " << setw(6) << notasExamenFDatos[i] << " |" << endl;
			}
		}
		//Conste que dijeron que... Como sea pero que Imprima JAJAJA
	}

	//Fusión tipo Goku JAJAJA
	void fusionarColumnas() {
		if (nombres->obtenerDatos().empty()) {
			cout << "No existe la tabla, abra el archivo de registros." << endl;
			return;
		}

		Columna<string>* nombresCompletos = new Columna<string>();
		Columna<int>* edadesFusion = new Columna<int>();
		Columna<float>* notaFinal = new Columna<float>();

		vector<string>& nombresDatos = nombres->obtenerDatos();
		vector<string>& apellidosDatos = apellidos->obtenerDatos();
		vector<int>& edadesDatos = edades->obtenerDatos();
		vector<float>& notasExamenPDatos = notasExamenP->obtenerDatos();
		vector<float>& notasAcumulativoDatos = notasAcumulativo->obtenerDatos();
		vector<float>& notasExamenFDatos = notasExamenF->obtenerDatos();

		size_t numRegistros = nombresDatos.size();
		for (size_t i = 0; i < numRegistros; i++) {
			string nombreCompleto = nombresDatos[i] + " " + apellidosDatos[i];
			nombresCompletos->agregarDato(nombreCompleto);

			int edad = edadesDatos[i];
			edadesFusion->agregarDato(edad);

			float nota = (notasExamenPDatos[i] + notasAcumulativoDatos[i] + notasExamenFDatos[i]);
			notaFinal->agregarDato(nota);
		}

		cout << "Columnas fusionadas:" << endl;
		cout << "Nombres Completos:" << endl;
		nombresCompletos->imprimir();
		cout << endl;

		cout << "Edades:" << endl;
		edadesFusion->imprimir();
		cout << endl;

		cout << "Nota Final:" << endl;
		notaFinal->imprimir();
		cout << endl;

		delete nombresCompletos;
		delete edadesFusion;
		delete notaFinal;
	}

	void guardarFusionColumnas() {
		if (nombres->obtenerDatos().empty()) {
			cout << "No existe la tabla, abra el archivo de registros." << endl;
			return;
		}

		Columna<string>* nombresCompletos = new Columna<string>();
		Columna<int>* edadesFusion = new Columna<int>();
		Columna<float>* notaFinal = new Columna<float>();

		vector<string>& nombresDatos = nombres->obtenerDatos();
		vector<string>& apellidosDatos = apellidos->obtenerDatos();
		vector<int>& edadesDatos = edades->obtenerDatos();
		vector<float>& notasExamenPDatos = notasExamenP->obtenerDatos();
		vector<float>& notasAcumulativoDatos = notasAcumulativo->obtenerDatos();
		vector<float>& notasExamenFDatos = notasExamenF->obtenerDatos();

		size_t numRegistros = nombresDatos.size();
		for (size_t i = 0; i < numRegistros; i++) {
			string nombreCompleto = nombresDatos[i] + " " + apellidosDatos[i];
			nombresCompletos->agregarDato(nombreCompleto);

			int edad = edadesDatos[i];
			edadesFusion->agregarDato(edad);

			float nota = (notasExamenPDatos[i] + notasAcumulativoDatos[i] + notasExamenFDatos[i]);
			notaFinal->agregarDato(nota);
		}

		ofstream archivo("RegistrosFusionados.txt");
		if (!archivo) {
			cout << "No se pudo crear el archivo de fusionados." << endl;
			return;
		}

		archivo << "NombreCompleto, Edad, NotaFinal, EstadoClase" << endl;

		vector<string>& nombresCompletosDatos = nombresCompletos->obtenerDatos();
		vector<int>& edadesFusionDatos = edadesFusion->obtenerDatos();
		vector<float>& notaFinalDatos = notaFinal->obtenerDatos();

		for (size_t i = 0; i < numRegistros; i++) {
			archivo << nombresCompletosDatos[i] << ", " << edadesFusionDatos[i] << ", " << notaFinalDatos[i] << ", ";
			if (notaFinalDatos[i] < 60) {
				archivo << "Reprobó";
			}
			else {
				archivo << "Aprobó";
			}
			archivo << endl;
		}

		archivo.close();
		cout << "Columnas fusionadas guardadas en el archivo RegistrosFusionados.txt." << endl;

		delete nombresCompletos;
		delete edadesFusion;
		delete notaFinal;
	}
};

#endif

