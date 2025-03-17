#ifndef LIBRO_H
#define LIBRO_H

#include "Publicacion.h"

class Libro : public Publicacion
{
private:
    string editorial;
    vector<string> palabrasDestacadas;
public:
    Libro(string DOI, string titulo, DTFecha fecha, string editorial, vector<string> palabrasDestacadas);
    Libro();
    ~Libro();

    string getEditorial();
    vector<string> getPalabrasDestacadas();

    void setEditorial(string editorial);
    void setPalabrasDestacadas(vector<string> palabrasDestacadas);
};

#endif // LIBRO_H