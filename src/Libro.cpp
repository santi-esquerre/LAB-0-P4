#include "../header/Libro.h"

#pragma region CONSTRUCTORES-DESTRUCTOR

Libro::Libro() : Publicacion()
{
    this->editorial = "";
    this->palabrasDestacadas = {};
}

Libro::Libro(const string &DOI, const string &titulo, DTFecha &fecha, const string &editorial, set<string> &palabrasDestacadas) : Publicacion(DOI, titulo, fecha)
{
    this->editorial = editorial;
    this->palabrasDestacadas = palabrasDestacadas;
}

Libro::~Libro()
{
    this->palabrasDestacadas.clear();
}

#pragma endregion

#pragma region GETTERS

string Libro::getEditorial()
{
    return this->editorial;
}

set<string> Libro::getPalabrasDestacadas()
{
    return this->palabrasDestacadas;
}

#pragma endregion

#pragma region SETTERS

void Libro::setEditorial(const string &editorial)
{
    this->editorial = editorial;
}

void Libro::setPalabrasDestacadas(set<string> &palabrasDestacadas)
{
    this->palabrasDestacadas = palabrasDestacadas;
}

#pragma endregion

#pragma region MÉTODOS

bool Libro::contienePalabra(const string &palabra)
{
    return this->palabrasDestacadas.find(palabra) != this->palabrasDestacadas.end();
}

#pragma endregion