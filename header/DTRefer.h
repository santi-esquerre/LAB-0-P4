#ifndef DTREFER_H
#define DTREFER_H

#include <iostream>
#include <string>
#include <vector>
#include "DTFecha.h"

using namespace std;

class DTRefer
{
private:
    string DOI, titulo;
    DTFecha fecha;
    vector<string> autores;
public:
    //Constructores y destructor
    DTRefer(string DOI, string titulo, DTFecha fecha, vector<string> autores);
    DTRefer();
    ~DTRefer();

    //Getters
    string getDOI();
    string getTitulo();
    DTFecha getFecha();
    vector<string> getAutores();
};

#endif // DTREFER_H