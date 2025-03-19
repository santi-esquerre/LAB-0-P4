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

list<Publicacion*> publicaciones;
std::map<std::string, Publicacion*> map_publicaciones;

std::list<Investigador*> investigadores;
std::map<std::string, Investigador*> map_investigadores;

void coleccion_guardarPublicacion(Publicacion* pub){
	publicaciones.push_back(pub);
	std::pair<std::string, Publicacion*> entry(pub->getDOI(), pub);
    map_publicaciones.insert(entry);
}
void coleccion_eliminarPublicacion(Publicacion* pub){
	publicaciones.remove(pub);
	map_publicaciones.erase(pub->getDOI());
}

void coleccion_guardarInvestigador(Investigador* inv){
	investigadores.push_back(inv);
	std::pair<std::string, Investigador*> entry(inv->getORCID(), inv);
    map_investigadores.insert(entry);
}

Investigador* coleccion_getInvestigador(std::string ORCID){
	return map_investigadores[ORCID];
}

Publicacion* coleccion_getPublicacion(std::string DOI){
	return map_publicaciones[DOI];
}

void main() {
        //Artículo 1
        DTFecha* fecha1 = new DTFecha(15, 5, 2023);

        ArticuloRevista * art1 = new ArticuloRevista("10.1234/abc123", "Fundamentos de POO", fecha1, "Programación Avanzada","Introduccion a los principios fundamentales de la programacion orientada a objetos, explicando sus conceptos clave como clases, objetos, herencia y polimorfismo.");
        
        // Artículo 2
        DTFecha* fecha2 = new DTFecha(10, 2, 2024);

        ArticuloRevista* art2 = new ArticuloRevista("10.4567/jkl012", "Utilidad de diagramas UML", *fecha2, "Modelado de Software", "Ejercicio empirico de como los diagramas UML pueden ayudar en el proceso y documentacion de software, cubriendo los tipos mas importantes utilizados, como clases.");

        // Libro 1
        DTFecha* fecha3 = new DTFecha(20, 8, 2022);
        set<string>* keyWords1 = new set<string>({"Diseno", "OOP", "Class"});

        Libro* libro1 = new Libro("10.2345/def456", "Patrones de Diseno en c++", *fecha3, "Software Design", *keyWords1);

        // Libro 2
        DTFecha* fecha4 = new DTFecha(20, 8, 2022);
        set<string>* keyWords2 = new set<string>({"Diagramas", "UML", "Software", "Modelado"});

        Libro* libro2 = new Libro("10.5678/mno345", "Guia de UML", *fecha4, "IEEE", *keyWords2);

        // Página Web 1
        DTFecha* fecha5 = new DTFecha(20, 10, 2024);

        PaginaWeb* paginaWeb = new PaginaWeb("10.3456/ghi789", "Diagramas para Principiantes", *fecha5, "www.umlparaprincipiantes.com", "En esta pagina web se presenta una gui completa sobre los diagramas UML, abordando los diagramas de casos de uso, de clases, de secuencia y de actividades.");

        //Agregar publicaciones al conjunto
        //TO DO: Hacerlo con set
        coleccion_guardarPublicacion(art1);
        coleccion_guardarPublicacion(art2);
        
        // Imprimir publicaciones
        for (int i = 0; i < publicaciones.size(); i++)
        {
            cout << publicaciones[i].getDT() << endl;
        }
        

        // Crear investigadores
        Investigador investigador1("0000-0003-1234-5678", "Carla Oliveri", "Universidad de la Republica");
        Investigador investigador2("0000-0001-8765-4321", "Alberto Santos", "Instituto Tecnico");

        // Agregar investigadores al conjunto
        investigadores.push_back(investigador1);
        investigadores.push_back(investigador2);

        // Imprimir investigadores
        for (int i = 0; i < investigadores.size(); i++)
        {
            cout << investigadores[i].toString() << endl;
        }




        

}