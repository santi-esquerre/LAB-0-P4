#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include "Publicacion.h"

class PaginaWeb : public Publicacion
{
private:
    string URL, contenidoExtraido;

public:
    PaginaWeb(string DOI, string titulo, DTFecha fecha, string URL, string contenidoExtraido);
    PaginaWeb();

    string getURL();
    string getContenidoExtraido();

    void setURL(string URL);
    void setContenidoExtraido(string contenidoExtraido);

    bool contienePalabra(string palabra) override;
};

#endif // PAGINAWEB_H