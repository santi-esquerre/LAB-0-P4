#include "../header/Investigador.h"

Investigador::Investigador(const std::string &ORCID, const std::string &nombre, const std::string &institucion)
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
    for (std::set<Publicacion *>::iterator it = this->publicaciones.begin(); it != this->publicaciones.end(); ++it)
    {
        (*it)->quitarAutor(this);
    }
    this->publicaciones.clear();
}

std::string Investigador::toString()
{
    std::string informacion = this->ORCID + "->" + this->nombre + "/" + this->institucion;
    return informacion;
}

std::set<std::string> Investigador::listarPublicaciones(DTFecha &desde, const std::string &palabra)
{
    std::set<std::string> listaDesde;
    std::set<Publicacion *> listaPublicaciones = this->getPublicaciones();

    for (std::set<Publicacion *>::iterator it = listaPublicaciones.begin(); it != listaPublicaciones.end(); ++it)
    {
        Publicacion *publicacion = *it;
        if (publicacion->getFecha() >= desde && publicacion->contienePalabra(palabra))
            listaDesde.insert(publicacion->getDOI());
    }

    return listaDesde;
}

std::string Investigador::getORCID()
{
    return this->ORCID;
}

std::string Investigador::getNombre()
{
    return this->nombre;
}

std::string Investigador::getInstitucion()
{
    return this->institucion;
}

std::set<Publicacion *> Investigador::getPublicaciones()
{
    return this->publicaciones;
}

void Investigador::setORCID(const std::string &ORCID)
{
    this->ORCID = ORCID;
}

void Investigador::setNombre(const std::string &nombre)
{
    this->nombre = nombre;
}

void Investigador::setInstitucion(const std::string &institucion)
{
    this->institucion = institucion;
}

void Investigador::setPublicaciones(std::set<Publicacion *> &publicaciones)
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
