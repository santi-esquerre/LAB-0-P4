#ifndef DTREFER_H
#define DTREFER_H

#include <iostream>
#include <string>
#include <set>
#include "DTFecha.h"

using namespace std;

class DTRefer
{
private:
    string DOI, titulo;
    DTFecha fecha;
    set<string> autores;
public:
    //Constructores y destructor
    DTRefer(string DOI, string titulo, DTFecha fecha, set<string> autores);
    DTRefer();
    ~DTRefer();

    // Sobrecarga del operador de inserción de flujo
    friend ostream& operator<<(ostream& os, const DTRefer& dtRefer);

    //Getters
    string getDOI();
    string getTitulo();
    DTFecha getFecha();
    set<string> getAutores();
};

#endif // DTREFER_H