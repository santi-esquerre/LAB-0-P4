#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include "Publicacion.h"

class PaginaWeb : public Publicacion
{
private:
    std::string URL, contenidoExtraido;

public:
    PaginaWeb(const std::string &DOI, const std::string &titulo, DTFecha &fecha, const std::string &URL, const std::string &contenidoExtraido);
    PaginaWeb();
    ~PaginaWeb() override = default;

    std::string getURL();
    std::string getContenidoExtraido();

    void setURL(const std::string &URL);
    void setContenidoExtraido(const std::string &contenidoExtraido);

    bool contienePalabra(const std::string &palabra) override;
};

#endif // PAGINAWEB_H