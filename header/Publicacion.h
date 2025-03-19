#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <iostream>
#include <string>
#include <set>
#include "DTFecha.h"
#include "DTRefer.h"

class Investigador;

using namespace std;

class Publicacion
{
protected:
    string DOI, titulo;
    DTFecha fecha;
    set<Investigador *> autores;

public:
    Publicacion(const string &DOI, const string &titulo, DTFecha &fecha);
    Publicacion();
    virtual ~Publicacion();

    DTRefer getDT();

    //! ES CASE SENSITIVE
    virtual bool contienePalabra(const string &palabra) = 0;

    // Getters
    string getDOI();
    string getTitulo();
    DTFecha getFecha();
    set<Investigador *> getAutores();

    // Setters
    void setDOI(const string &DOI);
    void setTitulo(const string &titulo);
    void setFecha(DTFecha &fecha);
    void setAutores(set<Investigador *> &autores);

    // Manejo de la lógica de la relación esAutor
    void agregarAutor(Investigador *autor);
    void quitarAutor(Investigador *autor);
    bool perteneceAutor(Investigador *autor);
};

#endif // PUBLICACION_H
