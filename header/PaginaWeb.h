#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include "Publicacion.h"

class PaginaWeb : public Publicacion
{
private:
    string URL, contenidoExtraido;

public:
    PaginaWeb(const string &DOI, const string &titulo, DTFecha &fecha, const string &URL, const string &contenidoExtraido);
    PaginaWeb();
    ~PaginaWeb() override = default;

    string getURL();
    string getContenidoExtraido();

    void setURL(const string &URL);
    void setContenidoExtraido(const string &contenidoExtraido);

    bool contienePalabra(const string &palabra) override;
};

#endif // PAGINAWEB_H