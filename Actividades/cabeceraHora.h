#ifndef CABECERAHORA_H
#define CABECERAHORA_H
#include "interno.h"

class cabeceraHora
{
public:
    cabeceraHora();
    cabeceraHora(const string& hora);
    void insertarAct(interno * nuevo);
    interno * getInicial();
    int getHora();
    string getStHora();
    cabeceraHora * getAbajo();
    void setAbajo(cabeceraHora * next);
    void imprimir();

    virtual ~cabeceraHora();

private:
    int hora;
    string sthora;
    cabeceraHora * abajo;
    interno * inicial;
};

#endif // CABECERAHORA_H
