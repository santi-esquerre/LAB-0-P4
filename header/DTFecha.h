#ifndef DTFECHA_H
#define DTFECHA_H
#include <ostream>
class DTFecha
{
private:
    int dia, mes, anio;
public:
    //Constructor y destructor
    DTFecha(int dia, int mes, int anio);
    DTFecha();
    ~DTFecha();
    bool operator>=(DTFecha);
    friend std::ostream &operator<<(std::ostream &os, const DTFecha &dtFecha);

    //Getters
    int getDia();
    int getMes();
    int getAnio();
};

#endif // DTFECHA_H