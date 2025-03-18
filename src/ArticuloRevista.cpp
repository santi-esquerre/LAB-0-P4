#include "../header/ArticuloRevista.h"

#pragma region CONSTRUCTORES

ArticuloRevista::ArticuloRevista() : Publicacion()
{
    this->revista = "";
    this->extracto = "";
}

ArticuloRevista::ArticuloRevista(const string &DOI, const string &titulo, DTFecha &fecha, const string &revista, const string &extracto) : Publicacion(DOI, titulo, fecha)
{
    this->revista = revista;
    this->extracto = extracto;
}

#pragma endregion

#pragma region GETTERS

string ArticuloRevista::getRevista()
{
    return this->revista;
}

string ArticuloRevista::getExtracto()
{
    return this->extracto;
}

#pragma endregion

#pragma region SETTERS

void ArticuloRevista::setRevista(const string &revista)
{
    this->revista = revista;
}

void ArticuloRevista::setExtracto(const string &extracto)
{
    this->extracto = extracto;
}

#pragma endregion

#pragma region MÉTODOS

bool ArticuloRevista::contienePalabra(const string &palabra)
{
    return this->extracto.find(palabra) != string::npos;
}

#pragma endregion