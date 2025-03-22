#include "../header/Investigador.h"
using std::set;
using std::string;

Investigador::Investigador(const string &ORCID, const string &nombre, const string &institucion)
{
    this->ORCID = ORCID;
    this->nombre = nombre;
    this->institucion = institucion;
}

Investigador::Investigador()
{
    this->ORCID = "";
    this->nombre = "";
    this->institucion = "";
}

Investigador::~Investigador()
{
   set<Publicacion*> copiaPublicaciones = this->publicaciones;
   for (set<Publicacion *>::iterator it = copiaPublicaciones.begin(); it != copiaPublicaciones.end(); ++it)
   {
       (*it)->quitarAutor(this);
   } 
    this->publicaciones.clear();
}

string Investigador::toString()
{
    string informacion = this->ORCID + "->" + this->nombre + "/" + this->institucion;
    return informacion;
}

set<string> Investigador::listarPublicaciones(const DTFecha &desde, const string &palabra) const
{
    set<string> listaDesde;
    set<Publicacion *> listaPublicaciones = this->publicaciones;

    for (set<Publicacion *>::iterator it = listaPublicaciones.begin(); it != listaPublicaciones.end(); ++it)
    {
        Publicacion *publicacion = *it;
        if (publicacion->getFecha() >= desde && publicacion->contienePalabra(palabra))
            listaDesde.insert(publicacion->getDOI());
    }

    return listaDesde;
}

string Investigador::getORCID() const
{
    return this->ORCID;
}

string Investigador::getNombre() const
{
    return this->nombre;
}

string Investigador::getInstitucion() const
{
    return this->institucion;
}

set<Publicacion *> Investigador::getPublicaciones() const
{
    return this->publicaciones;
}

void Investigador::setORCID(const string &ORCID)
{
    this->ORCID = ORCID;
}

void Investigador::setNombre(const string &nombre)
{
    this->nombre = nombre;
}

void Investigador::setInstitucion(const string &institucion)
{
    this->institucion = institucion;
}

void Investigador::setPublicaciones(set<Publicacion *> &publicaciones)
{
    this->publicaciones = publicaciones;
}

void Investigador::agregarPublicacion(Publicacion *publicacion)
{
    this->publicaciones.insert(publicacion);
    if (!publicacion->perteneceAutor(this))
        publicacion->agregarAutor(this);
}

void Investigador::quitarPublicacion(Publicacion *publicacion)
{
    if (publicacion != NULL)
    {
        this->publicaciones.erase(publicacion);
        if (publicacion->perteneceAutor(this))
            publicacion->quitarAutor(this);
    }
}

bool Investigador::pertenecePublicacion(Publicacion *publicacion)
{
    return this->publicaciones.find(publicacion) != this->publicaciones.end();
}
