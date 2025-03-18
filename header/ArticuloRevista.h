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
    ArticuloRevista(const string &DOI, const string &titulo, DTFecha &fecha, const string &revista, const string &extracto);
    ArticuloRevista();
    ~ArticuloRevista() override = default;

    string getRevista();
    string getExtracto();

    void setRevista(const string &revista);
    void setExtracto(const string &extracto);

    bool contienePalabra(const string &palabra) override;
};

#endif // ARTICULOREVISTA_H