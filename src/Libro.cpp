#include "../header/Libro.h"

#pragma region CONSTRUCTORES-DESTRUCTOR

Libro::Libro() : Publicacion()
{
    this->editorial = "";
    this->palabrasDestacadas = {};
}

Libro::Libro(string DOI, string titulo, DTFecha fecha, string editorial, set<string> palabrasDestacadas) : Publicacion(DOI, titulo, fecha)
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

void Libro::setEditorial(string editorial)
{
    this->editorial = editorial;
}

void Libro::setPalabrasDestacadas(set<string> palabrasDestacadas)
{
    this->palabrasDestacadas = palabrasDestacadas;
}

#pragma endregion

#pragma region MÉTODOS

bool Libro::contienePalabra(string palabra)
{
    return this->palabrasDestacadas.find(palabra) != this->palabrasDestacadas.end();
}

#pragma endregion