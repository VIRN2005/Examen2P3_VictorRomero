#ifndef COLUMNAH
#define COLUMNA

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Columna {
public:
    vector<T> datosColumna;

    void agregarDato(T values) {
        datosColumna.push_back(values);
    }

    void imprimir() {
        for (const auto& dato : datosColumna) {
            cout << dato << " ";
        }
        cout << endl;
    }

    vector<T>& obtenerDatos() {
        return datosColumna;
    }
};

#endif
