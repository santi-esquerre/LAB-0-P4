#include "../header/PaginaWeb.h"

#pragma region CONSTRUCTORES-DESTRUCTOR

PaginaWeb::PaginaWeb(const std::string &DOI, const std::string &titulo, DTFecha &fecha, const std::string &URL, const std::string &contenidoExtraido) : Publicacion(DOI, titulo, fecha)
{
    this->URL = URL;
    this->contenidoExtraido = contenidoExtraido;
}

PaginaWeb::PaginaWeb() : Publicacion(){}

PaginaWeb::~PaginaWeb() {}

#pragma endregion

#pragma region GETTERS

std::string PaginaWeb::getURL()
{
    return this->URL;
}

std::string PaginaWeb::getContenidoExtraido()
{
    return this->contenidoExtraido;
}

#pragma endregion

#pragma region SETTERS

void PaginaWeb::setURL(const std::string &URL)
{
    this->URL = URL;
}

void PaginaWeb::setContenidoExtraido(const std::string &contenidoExtraido)
{
    this->contenidoExtraido = contenidoExtraido;
}

#pragma endregion

#pragma region METODOS

bool PaginaWeb::contienePalabra(const std::string &palabra)
{
    return this->contenidoExtraido.find(palabra) != std::string::npos;
}

#pragma endregion