#include "../header/PaginaWeb.h"

#pragma region CONSTRUCTORES

PaginaWeb::PaginaWeb(const string &DOI, const string &titulo, DTFecha &fecha, const string &URL, const string &contenidoExtraido) : Publicacion(DOI, titulo, fecha)
{
    this->URL = URL;
    this->contenidoExtraido = contenidoExtraido;
}

PaginaWeb::PaginaWeb() : Publicacion()
{
    this->URL = "";
    this->contenidoExtraido = "";
}

#pragma endregion

#pragma region GETTERS

string PaginaWeb::getURL()
{
    return this->URL;
}

string PaginaWeb::getContenidoExtraido()
{
    return this->contenidoExtraido;
}

#pragma endregion

#pragma region SETTERS

void PaginaWeb::setURL(const string &URL)
{
    this->URL = URL;
}

void PaginaWeb::setContenidoExtraido(const string &contenidoExtraido)
{
    this->contenidoExtraido = contenidoExtraido;
}

#pragma endregion

#pragma region METODOS

bool PaginaWeb::contienePalabra(const string &palabra)
{
    return this->contenidoExtraido.find(palabra) != string::npos;
}

#pragma endregion