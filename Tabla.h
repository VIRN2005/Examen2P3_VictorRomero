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

