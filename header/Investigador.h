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
    std::set<std::string> listarPublicaciones(const DTFecha &desde, const std::string &palabra) const;

    // Getters
    std::string getORCID() const;
    std::string getNombre() const;
    std::string getInstitucion() const;
    std::set<Publicacion *> getPublicaciones() const;

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