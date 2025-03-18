#include "../header/Libro.h"

#pragma region CONSTRUCTORES - DESCTRUCTOR

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

// TODO: Falta implementar el destructor

#pragma endregion