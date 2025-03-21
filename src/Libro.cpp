#include "../header/Libro.h"

#pragma region CONSTRUCTORES-DESTRUCTOR

Libro::Libro() : Publicacion()
{
    this->editorial = "";
    this->palabrasDestacadas = {};
}

Libro::Libro(const std::string &DOI, const std::string &titulo, DTFecha &fecha, const std::string &editorial, std::set<std::string> &palabrasDestacadas) : Publicacion(DOI, titulo, fecha)
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

std::string Libro::getEditorial()
{
    return this->editorial;
}

std::set<std::string> Libro::getPalabrasDestacadas()
{
    return this->palabrasDestacadas;
}

#pragma endregion

#pragma region SETTERS

void Libro::setEditorial(const std::string &editorial)
{
    this->editorial = editorial;
}

void Libro::setPalabrasDestacadas(std::set<std::string> &palabrasDestacadas)
{
    this->palabrasDestacadas = palabrasDestacadas;
}

#pragma endregion

#pragma region MÉTODOS

bool Libro::contienePalabra(const std::string &palabra)
{
    return this->palabrasDestacadas.find(palabra) != this->palabrasDestacadas.end();
}

#pragma endregion