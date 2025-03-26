#include "../header/DTFecha.h"

DTFecha::DTFecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

DTFecha::DTFecha()
{
    this->dia = 0;
    this->mes = 0;
    this->anio = 0;
}

DTFecha::~DTFecha() {}

int DTFecha::getDia() const
{
    return this->dia;
}

int DTFecha::getMes() const
{
    return this->mes;
}

int DTFecha::getAnio() const
{
    return this->anio;
}

bool DTFecha::operator>=(const DTFecha &fecha) const
{

    int anio = fecha.getAnio();
    int mes = fecha.getMes();
    int dia = fecha.getDia();

    return (this->anio > anio) || (this->anio == anio && this->mes > mes) || (this->anio == anio && this->mes == mes && this->dia >= dia);
}

std::ostream &operator<<(std::ostream &os, const DTFecha &dtFecha)
{
    os << dtFecha.dia << "/" << dtFecha.mes << "/" << dtFecha.anio;
    return os;
}