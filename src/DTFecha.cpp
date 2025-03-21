#include "../header/DTFecha.h"

bool DTFecha::operator>=(DTFecha fecha)
{
    int anio = fecha.getAnio();
    int mes = fecha.getMes();
    int dia = fecha.getDia();

    return (this->anio > anio) || (this->anio == anio && this->mes > mes) || (this->anio == anio && this->mes == mes && this->dia >= dia);
}