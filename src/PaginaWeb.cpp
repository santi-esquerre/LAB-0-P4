#include "../header/PaginaWeb.h"

#pragma region CONSTRUCTORES

PaginaWeb::PaginaWeb(string DOI, string titulo, DTFecha fecha, string URL, string contenidoExtraido) : Publicacion(DOI, titulo, fecha)
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

void PaginaWeb::setURL(string URL)
{
    this->URL = URL;
}

void PaginaWeb::setContenidoExtraido(string contenidoExtraido)
{
    this->contenidoExtraido = contenidoExtraido;
}

#pragma endregion

#pragma region METODOS

bool PaginaWeb::contienePalabra(string palabra)
{
    return this->contenidoExtraido.find(palabra) != string::npos;
}

#pragma endregion