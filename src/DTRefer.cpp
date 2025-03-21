#include "../header/DTRefer.h"
//#include "../header/DTFecha.h"


DTRefer::DTRefer(const std::string &DOI, const std::string &titulo, DTFecha &fecha, std::set<std::string> &autores){
    this->DOI = DOI;
    this->titulo = titulo;
    this->fecha = fecha;
    this->autores = autores;
}

DTRefer::DTRefer(){
    this->DOI = "";
    this->titulo = "";
    this->fecha = DTFecha();
    this->autores = std::set<std::string> {""};
}

DTRefer::~DTRefer(){};

//Getters

std::string DTRefer::getDOI(){
    return this->DOI;
}
std::string DTRefer::getTitulo(){
    return this->titulo;
}
DTFecha DTRefer::getFecha(){
    return this->fecha;
}
std::set<std::string> DTRefer::getAutores(){
    return this->autores;
}

//Sobrecarga

std::ostream &operator<<(std::ostream &os, const DTRefer &dtRefer){
    os << dtRefer.DOI << "->" << dtRefer.titulo << "(" << dtRefer.fecha << ")/";
    for (std::set<std::string>::iterator it = dtRefer.autores.begin() ; it != dtRefer.autores.end(); it++){
        if(std::distance (it, dtRefer.autores.end()) > 1 ){
            os << *it << ",";
        } else {
            os << *it;
        }
    }
    return os;
}