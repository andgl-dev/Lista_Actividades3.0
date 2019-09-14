#include "interno.h"

interno::interno()
{
    this->dia = 0;
    this->hr = 0;
    this->actividad = "";

    this->sig = NULL;
    this->ant = NULL;
    this->arriba = NULL;
    this->abajo = NULL;
}

interno::interno(int dia, int hr,const string& act)
{
    this->dia = dia;
    this->hr = hr;
    this->actividad = act;

    this->sig = NULL;
    this->ant = NULL;
    this->arriba = NULL;
    this->abajo = NULL;
}

string interno::getActividad()
{
    return this->actividad;
}



interno *interno::getSiguiente()
{
    return this->sig;
}

interno *interno::getAnterior()
{
    return this->ant;
}

void interno::setSiguiente(interno *sig)
{
    this->sig = sig;
}

void interno::setAnterior(interno *ant)
{
    this->ant = ant;
}
//------------------------------------------
interno *interno::getArriba()
{
    return this->arriba;
}

interno *interno::getAbajo()
{
    return this->abajo;
}

void interno::setArriba(interno *arr)
{
    this->arriba = arr;
}

void interno::setAbajo(interno *aba)
{
    this->abajo = aba;
}




interno::~interno()
{
    //dtor
}
