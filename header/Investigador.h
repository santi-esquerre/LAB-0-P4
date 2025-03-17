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
    set<Publicacion*> publicaciones;
public:
    Investigador(string ORCID, string nombre, string institucion);
    Investigador();
    ~Investigador();

    string toString();
    set<string> listarPublicaciones(DTFecha desde, string palabra);

    //Getters
    string getORCID();
    string getNombre();
    string getInstitucion();
    set<Publicacion*> getPublicaciones();

    //Setters
    void setORCID(string ORCID);
    void setNombre(string nombre);
    void setInstitucion(string institucion);
    void setPublicaciones(set<Publicacion*> publicaciones);
};

#endif // INVESTIGADOR_H