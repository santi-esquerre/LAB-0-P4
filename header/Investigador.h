#ifndef INVESTIGADOR_H
#define INVESTIGADOR_H

#include <iostream>
#include <string>
#include <set>
#include "DTFecha.h"

class Publicacion;

using namespace std;

class Investigador
{
private:
    string ORCID, nombre, institucion;
    set<Publicacion *> publicaciones;

public:
    Investigador(const string &ORCID, const string &nombre, const string &institucion);
    Investigador();
    ~Investigador();

    string toString();
    set<string> listarPublicaciones(DTFecha &desde, const string &palabra);

    // Getters
    string getORCID();
    string getNombre();
    string getInstitucion();
    set<Publicacion *> getPublicaciones();

    // Setters
    void setORCID(const string &ORCID);
    void setNombre(const string &nombre);
    void setInstitucion(const string &institucion);
    void setPublicaciones(set<Publicacion *> &publicaciones);

    // Manejo de la lógica de la relación esAutor
    void agregarPublicacion(Publicacion *publicacion);
    void quitarPublicacion(Publicacion *publicacion);
};

#endif // INVESTIGADOR_H