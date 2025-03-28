#include "header/ArticuloRevista.h"
#include "header/DTFecha.h"
#include "header/DTRefer.h"
#include "header/Investigador.h"
#include "header/Libro.h"
#include "header/PaginaWeb.h"
#include "header/Publicacion.h"
#include <list>
#include <map>

using namespace std;

list<Publicacion *> publicaciones;
std::map<std::string, Publicacion *> map_publicaciones;

std::list<Investigador *> investigadores;
std::map<std::string, Investigador *> map_investigadores;

void coleccion_guardarPublicacion(Publicacion *pub)
{
    publicaciones.push_back(pub);
    std::pair<std::string, Publicacion *> nuevaEntrada(pub->getDOI(), pub);
    map_publicaciones.insert(nuevaEntrada);
}
void coleccion_eliminarPublicacion(Publicacion *pub)
{
    publicaciones.remove(pub);
    map_publicaciones.erase(pub->getDOI());
}

void coleccion_guardarInvestigador(Investigador *inv)
{
    investigadores.push_back(inv);
    std::pair<std::string, Investigador *> nuevaEntrada(inv->getORCID(), inv);
    map_investigadores.insert(nuevaEntrada);
}

Investigador *coleccion_getInvestigador(std::string ORCID)
{
    return map_investigadores[ORCID];
}

Publicacion *coleccion_getPublicacion(std::string DOI)
{
    return map_publicaciones[DOI];
}

void parte_A(){
    // Artículo 1
    DTFecha fecha1(15, 5, 2023);

    ArticuloRevista *art1 = new ArticuloRevista("10.1234/abc123", "Fundamentos de POO", fecha1, "Programación Avanzada", "Introduccion a los principios fundamentales de la programacion orientada a objetos, explicando sus conceptos clave como clases, objetos, herencia y polimorfismo.");

    // Artículo 2
    DTFecha fecha2(10, 2, 2024);

    ArticuloRevista *art2 = new ArticuloRevista("10.4567/jkl012", "Utilidad de diagramas UML", fecha2, "Modelado de Software", "Ejercicio empirico de como los diagramas UML pueden ayudar en el proceso y documentacion de software, cubriendo los tipos mas importantes utilizados, como clases.");

    coleccion_guardarPublicacion(art1);
    coleccion_guardarPublicacion(art2);
}

void parte_B(){
    // Libro 1
    DTFecha fecha3(20, 8, 2022);
    set<string> keyWords1;
    keyWords1.insert("Diseno");
    keyWords1.insert("OOP");
    keyWords1.insert("Class");

    Libro *libro1 = new Libro("10.2345/def456", "Patrones de Diseno en c++", fecha3, "Software Design", keyWords1);

    // Libro 2
    set<string> keyWords2;
    keyWords2.insert("Diagramas");
    keyWords2.insert("UML");
    keyWords2.insert("Software");
    keyWords2.insert("Modelado");

    Libro *libro2 = new Libro("10.5678/mno345", "Guia de UML", fecha3, "IEEE", keyWords2);

    coleccion_guardarPublicacion(libro1);
    coleccion_guardarPublicacion(libro2);
}

void parte_C(){
    // Página Web 1
    DTFecha fecha4(20, 10, 2024);

    PaginaWeb *paginaWeb = new PaginaWeb("10.3456/ghi789", "Diagramas para Principiantes", fecha4, "www.umlparaprincipiantes.com", "En esta pagina web se presenta una gui completa sobre los diagramas UML, abordando los diagramas de casos de uso, de clases, de secuencia y de actividades.");

    coleccion_guardarPublicacion(paginaWeb);
}

void parte_D(){
    // Imprimir publicaciones
    for (list<Publicacion *>::iterator publi = publicaciones.begin(); publi != publicaciones.end(); ++publi)
    {
        cout << (*publi)->getDT() << endl;
    }
}

void parte_E(){
    // Crear investigadores
    Investigador *investigador1 = new Investigador("0000-0003-1234-5678", "Carla Oliveri", "Universidad de la Republica");
    Investigador *investigador2 = new Investigador("0000-0001-8765-4321", "Alberto Santos", "Instituto Tecnico");

    // Agregar investigadores al conjunto
    coleccion_guardarInvestigador(investigador1);
    coleccion_guardarInvestigador(investigador2);
}

void parte_F(){
    // Imprimir investigadores
    for (list<Investigador *>::iterator inv = investigadores.begin(); inv != investigadores.end(); ++inv)
    {
        cout << (*inv)->toString() << endl;
    }
}

void parte_G(){
    // Agregar publicaciones a investigadores
    coleccion_getInvestigador("0000-0003-1234-5678")->agregarPublicacion(coleccion_getPublicacion("10.1234/abc123"));
    coleccion_getInvestigador("0000-0003-1234-5678")->agregarPublicacion(coleccion_getPublicacion("10.4567/jkl012"));
    coleccion_getInvestigador("0000-0003-1234-5678")->agregarPublicacion(coleccion_getPublicacion("10.5678/mno345"));
    coleccion_getInvestigador("0000-0003-1234-5678")->agregarPublicacion(coleccion_getPublicacion("10.3456/ghi789"));
    coleccion_getInvestigador("0000-0001-8765-4321")->agregarPublicacion(coleccion_getPublicacion("10.1234/abc123"));
    coleccion_getInvestigador("0000-0001-8765-4321")->agregarPublicacion(coleccion_getPublicacion("10.2345/def456"));
    coleccion_getInvestigador("0000-0001-8765-4321")->agregarPublicacion(coleccion_getPublicacion("10.4567/jkl012"));
    // Agregar investigadores a publicaciones
    coleccion_getPublicacion("10.1234/abc123")->agregarAutor(coleccion_getInvestigador("0000-0003-1234-5678"));
    coleccion_getPublicacion("10.1234/abc123")->agregarAutor(coleccion_getInvestigador("0000-0001-8765-4321"));
    coleccion_getPublicacion("10.4567/jkl012")->agregarAutor(coleccion_getInvestigador("0000-0003-1234-5678"));
    coleccion_getPublicacion("10.4567/jkl012")->agregarAutor(coleccion_getInvestigador("0000-0001-8765-4321"));
    coleccion_getPublicacion("10.5678/mno345")->agregarAutor(coleccion_getInvestigador("0000-0003-1234-5678"));
    coleccion_getPublicacion("10.2345/def456")->agregarAutor(coleccion_getInvestigador("0000-0001-8765-4321"));
    coleccion_getPublicacion("10.3456/ghi789")->agregarAutor(coleccion_getInvestigador("0000-0003-1234-5678"));
}

void parte_H(){
    DTFecha desdeFecha(10, 12, 2023);
    set<string> publis = coleccion_getInvestigador("0000-0003-1234-5678")->listarPublicaciones(desdeFecha, "UML");

    for (set<string>::iterator pub = publis.begin(); pub != publis.end(); pub++)
    {
        cout << *pub << endl;
    }
}

void parte_I(){
    Publicacion *pubAEliminar = coleccion_getPublicacion("10.4567/jkl012");
    coleccion_eliminarPublicacion(pubAEliminar);
    delete pubAEliminar;
    pubAEliminar = NULL;
}

void parte_J(){
    DTFecha desdeFecha2(1, 1, 2020);
    set<string> publis2 = coleccion_getInvestigador("0000-0003-1234-5678")->listarPublicaciones(desdeFecha2, "UML");

    for (set<string>::iterator pub = publis2.begin(); pub != publis2.end(); pub++)
    {
        cout << *pub << endl;
    }
}

void parte_K(){
    // Imprimir publicaciones
    for (list<Publicacion *>::iterator publi = publicaciones.begin(); publi != publicaciones.end(); ++publi)
    {
        cout << (*publi)->getDT() << endl;
    }
}

int main()
{
    // Parte A
    cout << "Parte A" << endl;

    parte_A();

    // Parte B
    cout << "Parte B" << endl;

    parte_B();

    // Parte C
    cout << "Parte C" << endl;

    parte_C();

    // Parte D
    cout << "Parte D" << endl;

    parte_D();

    // Parte E
    cout << "Parte E" << endl;

    parte_E();

    // Parte F
    cout << "Parte F" << endl;

    parte_F();

    // Parte G
    cout << "Parte G" << endl;

    parte_G();

    // Parte H
    cout << "Parte H" << endl;

    parte_H();

    // Parte I
    cout << "Parte I" << endl;

    parte_I();

    // Parte J
    cout << "Parte J" << endl;

    parte_J();

    // Parte K
    cout << "Parte K" << endl;

    parte_K();

    for (list<Publicacion *>::iterator publi = publicaciones.begin(); publi != publicaciones.end(); ++publi)
    {
        delete *publi;
        *publi = NULL;
    }

    for (list<Investigador *>::iterator inv = investigadores.begin(); inv != investigadores.end(); ++inv)
    {
        delete *inv;
        *inv = NULL;
    }


    cout << "FIN" << endl;
}