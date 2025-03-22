#ifndef LIBRO_H
#define LIBRO_H

#include "Publicacion.h"

class Libro : public Publicacion
{
private:
    std::string editorial;
    std::set<std::string> palabrasDestacadas;

public:
    Libro(const std::string &DOI, const std::string &titulo, DTFecha &fecha, const std::string &editorial, std::set<std::string> &palabrasDestacadas);
    Libro();
    ~Libro();

    std::string getEditorial();
    std::set<std::string> getPalabrasDestacadas();

    void setEditorial(const std::string &editorial);
    void setPalabrasDestacadas(std::set<std::string> &palabrasDestacadas);

    bool contienePalabra(const std::string &palabra);
};

#endif // LIBRO_H