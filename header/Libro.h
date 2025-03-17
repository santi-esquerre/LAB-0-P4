#ifndef LIBRO_H
#define LIBRO_H

#include "Publicacion.h"

class Libro : public Publicacion
{
private:
    string editorial;
    set<string> palabrasDestacadas;
public:
    Libro(string DOI, string titulo, DTFecha fecha, string editorial, set<string> palabrasDestacadas);
    Libro();
    ~Libro();

    string getEditorial();
    set<string> getPalabrasDestacadas();

    void setEditorial(string editorial);
    void setPalabrasDestacadas(set<string> palabrasDestacadas);
};

#endif // LIBRO_H