#include "cabeceraHora.h"

cabeceraHora::cabeceraHora()
{
    this->abajo = NULL;
    this->inicial = NULL;
    this->sthora ="";
    this->hora = 0;
}

cabeceraHora::cabeceraHora(const string& hora)
{
    this->abajo = NULL;
    this->inicial = NULL;
    this->sthora = hora;
    this->hora = atoi(hora.c_str());
}


void cabeceraHora::insertarAct(interno * nuevo)
{
    if(this->inicial == NULL)
    {
        this->inicial = nuevo;
    }
    else if(nuevo->dia < this->inicial->dia)
    {
        nuevo->setSiguiente(this->inicial);
        this->inicial->setAnterior(nuevo);
        this->inicial = nuevo;
    }
    else
    {
        interno*aux = this->inicial;
        bool insertado = false;
        while(aux->getSiguiente() != NULL)
        {
            if(nuevo->dia < aux->getSiguiente()->dia)
            {
                nuevo->setAnterior(aux);
                nuevo->setSiguiente(aux->getSiguiente());
                aux->getSiguiente()->setAnterior(nuevo);
                aux->setSiguiente(nuevo);
                insertado = true;
                break;
            }
            aux = aux->getSiguiente();
        }
        if(!(insertado))
        {
            nuevo->setAnterior(aux);
            aux->setSiguiente(nuevo);
        }

    }
}

interno *cabeceraHora::getInicial()
{
    return this->inicial;
}

int cabeceraHora::getHora()
{
    return this->hora;
}

string cabeceraHora::getStHora()
{
    return this->sthora;
}

cabeceraHora *cabeceraHora::getAbajo()
{
    return this->abajo;
}

void cabeceraHora::setAbajo(cabeceraHora *next)
{
    this->abajo = next;
}


cabeceraHora::~cabeceraHora()
{
    //dtor
}
