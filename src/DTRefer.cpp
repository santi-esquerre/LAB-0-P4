#include "../header/DTRefer.h"
// #include <iostream>
// #include <string>
// #include <set>
// using namespace std;

DTRefer::DTRefer(const string &DOI, const string &titulo, DTFecha &fecha, set<string> &autores){
    this->DOI = DOI;
    this->titulo = titulo;
    this->fecha = fecha;
    this->autores = autores;
} // Aca capaz que seria bueno cambiar alguna mayuscula en los argumentos de la funcion para que se lean distintos a los elementos de la clase

DTRefer::DTRefer(){
    this->DOI = "";
    this->titulo = "";
    this->fecha = DTFecha();
    this->autores = set<string> {""};
}

// DTRefer::~DTRefer(){

// }


//Getters

string DTRefer::getDOI(){
    return this->DOI;
}
string DTRefer::getTitulo(){
    return this->titulo;
}
DTFecha DTRefer::getFecha(){
    return this->fecha;
}
set<string> DTRefer::getAutores(){
    return this->autores;
}

ostream &operator<<(ostream &os, DTRefer &dtRefer){
    os << dtRefer.getDOI() << "->" << dtRefer.getTitulo() << "(" << dtRefer.getFecha().getDia() << "/" << dtRefer.getFecha().getMes() << dtRefer.getFecha().getAnio() << ")/";
    for (string autor : dtRefer.getAutores()){
        os << autor << ",";
    }
    return os;
}
