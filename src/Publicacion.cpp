#include "../header/Publicacion.h"
#include "../header/Investigador.h"

#pragma region CONSTRUCTORES-DESTRUCTOR

Publicacion::Publicacion(string DOI, string titulo, DTFecha fecha)
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

void Publicacion::setDOI(string DOI)
{
    this->DOI = DOI;
}

void Publicacion::setTitulo(string titulo)
{
    this->titulo = titulo;
}

void Publicacion::setFecha(DTFecha fecha)
{
    this->fecha = fecha;
}

void Publicacion::setAutores(set<Investigador *> autores)
{
    this->autores = autores;
}

#pragma endregion

#pragma region MANEJO DE LA RELACIÓN ESAUTOR

void Publicacion::agregarAutor(Investigador *autor)
{
    this->autores.insert(autor);
    autor->agregarPublicacion(this);
}

void Publicacion::quitarAutor(Investigador *autor)
{
    this->autores.erase(autor);
    autor->quitarPublicacion(this);
}

#pragma endregion

#pragma region MÉTODOS

DTRefer Publicacion::getDT()
{
    set<string> autores;
    for (auto autor : this->autores)
    {
        autores.insert(autor->toString());
    }
    return DTRefer(this->DOI, this->titulo, this->fecha, autores);
}

#pragma endregion
