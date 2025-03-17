#include <iostream>
#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTRefer.h"
#include "Investigador.h"

using namespace std;

class Publicacion
{
protected:
    string DOI, titulo;
    DTFecha fecha;
    vector<Investigador> autores;
public:
    Publicacion(string DOI, string titulo, DTFecha fecha);
    Publicacion();
    ~Publicacion();

    virtual DTRefer getDT();
    virtual bool contienePalabra(string palabra);

    //Getters
    string getDOI();
    string getTitulo();
    DTFecha getFecha();
    vector<Investigador> getAutores();

    //Setters
    void setDOI(string DOI);
    void setTitulo(string titulo);
    void setFecha(DTFecha fecha);
    void setAutores(vector<Investigador> autores);
};

