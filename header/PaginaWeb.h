#include "Publicacion.h"

class PaginaWeb : public Publicacion
{
private:
    string URL, contenidoExtraido;
public:
    PaginaWeb(string DOI, string titulo, DTFecha fecha, string URL, string contenidoExtraido);
    PaginaWeb();
    ~PaginaWeb();

    string getURL();
    string getContenidoExtraido();

    void setURL(string URL) ;
    void setContenidoExtraido(string contenidoExtraido) ;
};
