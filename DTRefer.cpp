#include "../header/DTRefer.h"


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

std::ostream &operator<<(std::ostream &os, DTRefer &dtRefer){
    os << dtRefer.getDOI() << "->" << dtRefer.getTitulo() << "(" << dtRefer.getFecha().getDia() << "/" << dtRefer.getFecha().getMes() << dtRefer.getFecha().getAnio() << ")/";
    for (std::string autor : dtRefer.getAutores()){
        os << autor << ",";
    }
    return os;
}
