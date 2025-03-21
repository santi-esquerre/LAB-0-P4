#include "../header/Publicacion.h"
#include "../header/Investigador.h"

#pragma region CONSTRUCTORES-DESTRUCTOR

Publicacion::Publicacion(const std::string &DOI, const std::string &titulo, DTFecha &fecha)
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
    for (std::set<Investigador *>::iterator it = this->autores.begin(); it != this->autores.end(); ++it)
    {
        (*it)->quitarPublicacion(this);
    }
    this->autores.clear();
}

#pragma endregion

#pragma region GETTERS

std::string Publicacion::getDOI()
{
    return this->DOI;
}

std::string Publicacion::getTitulo()
{
    return this->titulo;
}

DTFecha Publicacion::getFecha()
{
    return this->fecha;
}

std::set<Investigador *> Publicacion::getAutores()
{
    return this->autores;
}

#pragma endregion

#pragma region std::setTERS

void Publicacion::setDOI(const std::string &DOI)
{
    this->DOI = DOI;
}

void Publicacion::setTitulo(const std::string &titulo)
{
    this->titulo = titulo;
}

void Publicacion::setFecha(DTFecha &fecha)
{
    this->fecha = fecha;
}

void Publicacion::setAutores(std::set<Investigador *> &autores)
{
    this->autores = autores;
}

#pragma endregion

#pragma region MANEJO DE LA RELACIÓN ESAUTOR

void Publicacion::agregarAutor(Investigador *autor)
{
    this->autores.insert(autor);
    if (!autor->pertenecePublicacion(this))
        autor->agregarPublicacion(this);
}

void Publicacion::quitarAutor(Investigador *autor)
{
    if (autor != nullptr)
    {
        this->autores.erase(autor);
        if (autor->pertenecePublicacion(this))
            autor->quitarPublicacion(this);
    }
}

bool Publicacion::perteneceAutor(Investigador *autor)
{
    return this->autores.find(autor) != this->autores.end();
}

#pragma endregion

#pragma region MÉTODOS

DTRefer Publicacion::getDT()
{
    std::set<std::string> autores;
    for (std::set<Investigador *>::iterator it = this->autores.begin(); it != this->autores.end(); ++it)
    {
        autores.insert((*it)->getNombre());
    }
    return DTRefer(this->DOI, this->titulo, this->fecha, autores);
}

#pragma endregion
