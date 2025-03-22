#ifndef ARTICULOREVISTA_H
#define ARTICULOREVISTA_H

#include <iostream>
#include <string>
#include "DTFecha.h"
#include "Publicacion.h"

class ArticuloRevista : public Publicacion
{
private:
    std::string revista, extracto;

public:
    ArticuloRevista(const std::string &DOI, const std::string &titulo, DTFecha &fecha, const std::string &revista, const std::string &extracto);
    ArticuloRevista();
    ~ArticuloRevista();

    std::string getRevista();
    std::string getExtracto();

    void setRevista(const std::string &revista);
    void setExtracto(const std::string &extracto);

    bool contienePalabra(const std::string &palabra);
};

#endif // ARTICULOREVISTA_H