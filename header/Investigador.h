#ifndef INVESTIGADOR_H
#define INVESTIGADOR_H

#include <iostream>
#include <string>
#include <vector>
#include "DTFecha.h"
#include "Publicacion.h"

using namespace std;

class Investigador
{
private:
    string ORCID, nombre, institucion;
    vector<Publicacion> publicaciones;
public:
    Investigador(string ORCID, string nombre, string institucion);
    Investigador();
    ~Investigador();

    string toString();
    vector<string> listarPublicaciones(DTFecha desde, string palabra);

    //Getters
    string getORCID();
    string getNombre();
    string getInstitucion();
    vector<Publicacion> getPublicaciones();

    //Setters
    void setORCID(string ORCID);
    void setNombre(string nombre);
    void setInstitucion(string institucion);
    void setPublicaciones(vector<Publicacion> publicaciones);
};

#endif // INVESTIGADOR_H