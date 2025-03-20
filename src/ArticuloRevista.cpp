#include "../header/ArticuloRevista.h"

#pragma region CONSTRUCTORES

ArticuloRevista::ArticuloRevista() : Publicacion()
{
    this->revista = "";
    this->extracto = "";
}

ArticuloRevista::ArticuloRevista(const std::string &DOI, const std::string &titulo, DTFecha &fecha, const std::string &revista, const std::string &extracto) : Publicacion(DOI, titulo, fecha)
{
    this->revista = revista;
    this->extracto = extracto;
}

#pragma endregion

#pragma region GETTERS

std::string ArticuloRevista::getRevista()
{
    return this->revista;
}

std::string ArticuloRevista::getExtracto()
{
    return this->extracto;
}

#pragma endregion

#pragma region SETTERS

void ArticuloRevista::setRevista(const std::string &revista)
{
    this->revista = revista;
}

void ArticuloRevista::setExtracto(const std::string &extracto)
{
    this->extracto = extracto;
}

#pragma endregion

#pragma region MÉTODOS

bool ArticuloRevista::contienePalabra(const std::string &palabra)
{
    return this->extracto.find(palabra) != std::string::npos;
}

#pragma endregion