#include "../header/Publicacion.h"
#include "../header/Investigador.h"

#pragma region CONSTRUCTORES-DESTRUCTOR

Publicacion::Publicacion(const string &DOI, const string &titulo, DTFecha &fecha)
{
    this->DOI = DOI;
    this->titulo = titulo;
    this->fecha = fecha;
}

Publicacion::Publicacion()
{
    this->DOI = "";
    this->titulo = "";
    this->fecha = DTFecha();
}

Publicacion::~Publicacion()
{
    for (auto autor : this->autores)
    {
        autor->quitarPublicacion(this);
    }
    this->autores.clear();
}

#pragma endregion

#pragma region GETTERS

string Publicacion::getDOI()
{
    return this->DOI;
}

string Publicacion::getTitulo()
{
    return this->titulo;
}

DTFecha Publicacion::getFecha()
{
    return this->fecha;
}

set<Investigador *> Publicacion::getAutores()
{
    return this->autores;
}

#pragma endregion

#pragma region SETTERS

void Publicacion::setDOI(const string &DOI)
{
    this->DOI = DOI;
}

void Publicacion::setTitulo(const string &titulo)
{
    this->titulo = titulo;
}

void Publicacion::setFecha(DTFecha &fecha)
{
    this->fecha = fecha;
}

void Publicacion::setAutores(set<Investigador *> &autores)
{
    this->autores = autores;
}

#pragma endregion

#pragma region MANEJO DE LA RELACIÓN ESAUTOR

void Publicacion::agregarAutor(Investigador *autor)
{
    this->autores.insert(autor);
    if(!autor->pertenecePublicacion(this)) autor->agregarPublicacion(this);
}

void Publicacion::quitarAutor(Investigador *autor)
{
    if (autor != nullptr)
    {
        this->autores.erase(autor);
        if(autor->pertenecePublicacion(this)) autor->quitarPublicacion(this);       
    }
}

bool Publicacion::perteneceAutor(Investigador *autor)
{
    auto esAutor = this->autores.find(autor);
    return esAutor != this->autores.end();
}

#pragma endregion

#pragma region MÉTODOS

DTRefer Publicacion::getDT()
{
    set<string> autores;
    for (auto autor : this->autores)
    {
        autores.insert(autor->getNombre());
    }
    return DTRefer(this->DOI, this->titulo, this->fecha, autores);
}

#pragma endregion
