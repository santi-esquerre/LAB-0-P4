#include "../header/Investigador.h"

Investigador::Investigador(const string &ORCID, const string &nombre, const string &institucion) {
    this-> ORCID = ORCID;
    this-> nombre = nombre;
    this-> institucion = institucion;

}

Investigador::Investigador() {
    this-> ORCID = "";
    this-> nombre = "";
    this-> institucion = "";
}

Investigador::~Investigador() {
    for (auto publicacion : this->publicaciones) publicacion->quitarAutor(this);
    this->publicaciones.clear();
}

string Investigador::toString() {
    string informacion = this->ORCID + "->" + this->nombre + "/" + this->institucion;
    return informacion; 
}

set<string> Investigador::listarPublicaciones(DTFecha &desde, const string &palabra) {
    set<string> listaDesde;
    set<Publicacion *> listaPublicaciones = this->getPublicaciones();
    for (auto publicacion : listaPublicaciones) {
        if (publicacion->getFecha() >= desde && publicacion->contienePalabra(palabra)) listaDesde.insert(publicacion->getDOI());
    }
    return listaDesde;
}


string Investigador::getORCID() {
    return this->ORCID;
}

string Investigador::getNombre() {
    return this->nombre;
}

string Investigador::getInstitucion() {
    return this->institucion;
}

set<Publicacion *> Investigador::getPublicaciones() {
    return this->publicaciones;
}

void Investigador::setORCID(const string &ORCID) {
    this->ORCID = ORCID;
}

void Investigador::setNombre(const string &nombre) {
    this->nombre = nombre;
}

void Investigador::setInstitucion(const string &institucion) {
    this->institucion = institucion;
}

void Investigador::setPublicaciones(set<Publicacion *> &publicaciones) {
    this->publicaciones = publicaciones;
}

void Investigador::agregarPublicacion(Publicacion *publicacion) {
    this->publicaciones.insert(publicacion);
    if(!publicacion->perteneceAutor(this)) publicacion->agregarAutor(this);
}

void Investigador::quitarPublicacion(Publicacion *publicacion) {
    if (publicacion != nullptr){
        this->publicaciones.erase(publicacion);
        if (publicacion->perteneceAutor(this)) publicacion->quitarAutor(this);       
    }
}

bool Investigador::pertenecePublicacion(Publicacion *publicacion) {
    auto tienePublicacion = this->publicaciones.find(publicacion);
    return tienePublicacion != this->publicaciones.end();
}




