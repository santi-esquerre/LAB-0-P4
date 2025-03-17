#ifndef DTFECHA_H
#define DTFECHA_H
class DTFecha
{
private:
    int dia, mes, anio;
public:
    //Constructor y destructor
    DTFecha(int dia, int mes, int anio);
    DTFecha();
    ~DTFecha();

    //Getters
    int getDia();
    int getMes();
    int getAnio();
};

#endif // DTFECHA_H