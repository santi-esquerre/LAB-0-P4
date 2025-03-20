#include "../header/DTFecha.h" 

DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

DTFecha::DTFecha(){
    this->dia = 0;
    this->mes = 0;
    this->anio = 0;
}

int DTFecha::getDia(){
    return this->dia;
}

int DTFecha::getMes(){
    return this->mes;
}

int DTFecha::getAnio(){
    return this->anio;
}

bool DTFecha::operator>=(DTFecha fecha) {
    int anio = fecha.getAnio();
    int mes = fecha.getMes();
    int dia = fecha.getDia();

    return (this->anio > anio) || (this->anio == anio && this->mes > mes) || (this->anio == anio && this->mes == mes && this->dia >= dia);
}