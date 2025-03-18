#ifndef ARTICULOREVISTA_H
#define ARTICULOREVISTA_H

#include <iostream>
#include <string>
#include "DTFecha.h"
#include "Publicacion.h"

using namespace std;

class ArticuloRevista : public Publicacion
{
private:
    string revista, extracto;

public:
    ArticuloRevista(string DOI, string titulo, DTFecha fecha, string revista, string extracto);
    ArticuloRevista();

    string getRevista();
    string getExtracto();

    void setRevista(string revista);
    void setExtracto(string extracto);

    bool contienePalabra(string palabra) override;
};

#endif // ARTICULOREVISTA_H