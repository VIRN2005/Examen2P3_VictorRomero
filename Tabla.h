#ifndef TABLAH
#define TABLAH

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

	//Cargar los datos del TXT
	void cargarArchivoRegistros() {
		fstream archivo("RegistrosUNITEC.txt");
		if (!archivo) {
			cout << "No se pudo abrir el archivo de registros." << endl;
			return;
		}

		string nombre, apellido;
		int edad;
		float notaP, notaA, notaF;

		while (archivo >> nombre >> apellido >> edad >> notaP >> notaA >> notaF) {
			nombres->agregarDato(nombre);
			apellidos->agregarDato(apellido);
			edades->agregarDato(edad);
			notasExamenP->agregarDato(notaP);
			notasAcumulativo->agregarDato(notaA);
			notasExamenF->agregarDato(notaF);
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

		cout << ">> TABLA DE REGISTROS <<" << endl;
		cout << "-Nombres: ";
		nombres->imprimir();
		apellidos->imprimir();

		cout << "-Edades: ";
		edades->imprimir();

		cout << "-Notas Examen Parcial: ";
		notasExamenP->imprimir();

		cout << "-Notas Acumulativo: ";
		notasAcumulativo->imprimir();

		cout << "-Notas Examen Final: ";
		notasExamenF->imprimir();

		//Conste que dijeron que... Como sea pero que Imprima JAJAJA
	}

	//Fusión tipo Goku JAJAJA
	void fusionarColumnas() {
		if (nombres->obtenerDatos().empty()) {
			cout << "No existe la tabla, abra el archivo de registros." << endl;
			return;
		}

		Columna<string>* nombresCompletos = new Columna<string>();
		Columna<int>* edadesFusionadas = new Columna<int>();
		Columna<float>* notaFinal = new Columna<float>();

		vector<string>& nombresDatos = nombres->obtenerDatos();
		vector<string>& apellidosDatos = apellidos->obtenerDatos();
		vector<int>& edadesDatos = edades->obtenerDatos();
		vector<float>& notasExamenFDatos = notasExamenF->obtenerDatos();

		for (size_t i = 0; i < nombresDatos.size(); i++) {
			nombresCompletos->agregarDato(nombresDatos[i] + " " + apellidosDatos[i]);
			edadesFusionadas->agregarDato(edadesDatos[i]);
			float nota = notasExamenFDatos[i];
			if (nota < 60) {
				nota = 0;
			}
			notaFinal->agregarDato(nota);
		}

		nombres = nombresCompletos;
		apellidos = nullptr;
		edades = edadesFusionadas;
		notasExamenP = nullptr;
		notasAcumulativo = nullptr;
		notasExamenF = notaFinal;

		cout << "Columnas fusionadas correctamente." << endl;
	}

	void guardarFusionColumnas() {
		//O sea... que si los valores no se cumplen que vuelva a leer
		if (nombres == nullptr || apellidos != nullptr || notasExamenP != nullptr || notasAcumulativo != nullptr || notasExamenF == nullptr) {
			cout << "Debe realizar la fusión antes de guardarla." << endl;
			return;
		}

		fstream archivo("RegistrosFusionados.txt");
		if (!archivo) {
			cout << "No se pudo crear el archivo de fusionados." << endl;
			return;
		}

		vector<string>& nombresDatos = nombres->obtenerDatos();
		vector<int>& edadesDatos = edades->obtenerDatos();
		vector<float>& notaFinalDatos = notasExamenF->obtenerDatos();
		// A este punto la verdad que todo sirve :)

		for (size_t i = 0; i < nombresDatos.size(); i++) {
			archivo << nombresDatos[i] << ", " << edadesDatos[i] << ", " << notaFinalDatos[i] << ", ";
			if (notaFinalDatos[i] < 60) {
				archivo << "Reprobó";
			} else {
				archivo << "Aprobó";
			}
			archivo << endl;
		}

		archivo.close();
		cout << "Fusión de columnas guardada correctamente en RegistrosFusionados.txt." << endl;
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
};

#endif

