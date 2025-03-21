#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTRefer.h"

class Investigador;

class Publicacion
{
protected:
    std::string DOI, titulo;
    DTFecha fecha;
    std::set<Investigador *> autores;

public:
    Publicacion(const std::string &DOI, const std::string &titulo, DTFecha &fecha);
    Publicacion();
    virtual ~Publicacion();

    DTRefer getDT();

    //! ES CASE SENSITIVE
    virtual bool contienePalabra(const std::string &palabra) = 0;

    // Getters
    std::string getDOI();
    std::string getTitulo();
    DTFecha getFecha();
    std::set<Investigador *> getAutores();

    // Setters
    void setDOI(const std::string &DOI);
    void setTitulo(const std::string &titulo);
    void setFecha(DTFecha &fecha);
    void setAutores(std::set<Investigador *> &autores);

    // Manejo de la lógica de la relación esAutor
    void agregarAutor(Investigador *autor);
    void quitarAutor(Investigador *autor);
    bool perteneceAutor(Investigador *autor);
};

#endif // PUBLICACION_H
