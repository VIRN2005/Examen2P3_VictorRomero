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
    Tabla() {
        nombres = new Columna<string>();
        apellidos = new Columna<string>();
        edades = new Columna<int>();
        notasExamenP = new Columna<float>();
        notasAcumulativo = new Columna<float>();
        notasExamenF = new Columna<float>();
    }

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

