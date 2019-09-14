#ifndef CABECERADIA_H
#define CABECERADIA_H
#include "interno.h"


class cabeceraDia
{
public:
    cabeceraDia();
    cabeceraDia(const string& dia);
    void insertarAct(interno * nuevo);
    interno* getInicial();
    int getDato();
    string getDia();
    void setInicial(interno* act);
    cabeceraDia * getSig();
    void setSig(cabeceraDia* next);
    void imprimir();
    virtual ~cabeceraDia();

private:
    string dia;
    int dato;
    cabeceraDia* sig;
    interno* Inicial;
};

#endif // CABECERADIA_H
