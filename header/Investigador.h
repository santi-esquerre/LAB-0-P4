#ifndef INVESTIGADOR_H
#define INVESTIGADOR_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "Publicacion.h"

class Publicacion;

class Investigador
{
private:
    std::string ORCID, nombre, institucion;
    std::set<Publicacion *> publicaciones;

public:
    Investigador(const std::string &ORCID, const std::string &nombre, const std::string &institucion);
    Investigador();
    ~Investigador();

    std::string toString();
    std::set<std::string> listarPublicaciones(DTFecha &desde, const std::string &palabra);

    // Getters
    std::string getORCID();
    std::string getNombre();
    std::string getInstitucion();
    std::set<Publicacion *> getPublicaciones();

    // Setters
    void setORCID(const std::string &ORCID);
    void setNombre(const std::string &nombre);
    void setInstitucion(const std::string &institucion);
    void setPublicaciones(std::set<Publicacion *> &publicaciones);

    // Manejo de la lógica de la relación esAutor
    void agregarPublicacion(Publicacion *publicacion);
    void quitarPublicacion(Publicacion *publicacion);
    bool pertenecePublicacion(Publicacion *publicacion);
};

#endif // INVESTIGADOR_H