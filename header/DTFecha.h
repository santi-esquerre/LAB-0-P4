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
  
    //Operadores
    bool operator>=(const DTFecha &fecha) const;
    friend std::ostream &operator<<(std::ostream &os, const DTFecha &dtFecha);


    //Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

#endif // DTFECHA_H