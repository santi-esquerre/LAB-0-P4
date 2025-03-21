#ifndef DTREFER_H
#define DTREFER_H

#include <string>
#include <set>
#include "DTFecha.h"
#include <ostream>

class DTRefer
{
private:
    std::string DOI, titulo;
    DTFecha fecha;
    std::set<std::string> autores;

public:
    // Constructores y destructor
    DTRefer(const std::string &DOI, const std::string &titulo, DTFecha &fecha, std::set<std::string> &autores);
    DTRefer();
    //~DTRefer();

    // Sobrecarga del operador de inserción de flujo
    friend std::ostream &operator<<(std::ostream &os, const DTRefer &dtRefer);

    // Getters
    std::string getDOI();
    std::string getTitulo();
    DTFecha getFecha();
    std::set<std::string> getAutores();
};

#endif // DTREFER_H