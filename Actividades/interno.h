#ifndef INTERNO_H
#define INTERNO_H
#include <string> //para utilizar cadenas
#include <cstring> // utilar NULL
#include <cstdlib> // biblioteca que contiene las funciones de entrada y salida de c++ . Viene Input/Output Stream
#include <iostream>
using namespace std;

class interno
{
public:
    interno();
    interno(int dia, int hr,const string& act);
    string getActividad();

    interno* getSiguiente();
    interno* getAnterior();
    interno* getArriba();
    interno* getAbajo();

    void setSiguiente(interno* sig);
    void setAnterior(interno* ant);
    void setArriba(interno* sig);
    void setAbajo(interno* ant);

    //coordenadas
    int dia;
    int hr;
    virtual ~interno();

private:
    string actividad;
    interno* sig;
    interno* ant;
    interno* arriba;
    interno* abajo;
};

#endif // INTERNO_H
