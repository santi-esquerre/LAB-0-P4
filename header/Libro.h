#ifndef LIBRO_H
#define LIBRO_H

#include "Publicacion.h"

class Libro : public Publicacion
{
private:
    string editorial;
    set<string> palabrasDestacadas;

public:
    Libro(const string &DOI, const string &titulo, DTFecha &fecha, const string &editorial, set<string> &palabrasDestacadas);
    Libro();
    ~Libro() override;

    string getEditorial();
    set<string> getPalabrasDestacadas();

    void setEditorial(const string &editorial);
    void setPalabrasDestacadas(set<string> &palabrasDestacadas);

    bool contienePalabra(const string &palabra) override;
};

#endif // LIBRO_H