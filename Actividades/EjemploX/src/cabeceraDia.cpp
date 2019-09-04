#include "cabeceraDia.h"

cabeceraDia::cabeceraDia()
{
    this->dia="";
    this->dato=0;
    this->sig = NULL;
    this->Inicial = NULL;
}

cabeceraDia::cabeceraDia(const string& dia_)
{
    string dia = dia_;
    this->dia = dia;
    if(dia=="lunes")
    {
        this->dato=1;
    }
    else if(dia=="martes")
    {
        this->dato=2;
    }
    else if(dia=="miercoles")
    {
        this->dato=3;
    }
    else if(dia=="jueves")
    {
        this->dato=4;
    }
    else if(dia=="viernes")
    {
        this->dato=5;
    }
    else if(dia=="sabado")
    {
        this->dato=6;
    }
    else if(dia=="domingo")
    {
        this->dato=7;
    }
    else
    {
        this->dato=0;
    }

    this->Inicial = NULL;
    this->sig = NULL;
}

void cabeceraDia::insertarAct(interno*nuevo)
{

    if(this->Inicial == NULL)
    {
        this->Inicial=nuevo;
    }
    else if(nuevo->hr < this->Inicial->hr)
    {
        nuevo->setAbajo(this->Inicial);
        this->Inicial->setArriba(nuevo);
        this->Inicial = nuevo;
    }
    else
    {
        interno*aux = this->Inicial;
        bool insertado = false;
        while(aux->getAbajo()!=NULL)
        {
            if(nuevo->hr < aux->getAbajo()->hr)
            {
                nuevo->setArriba(aux->getArriba());
                aux->getArriba()->setAbajo(nuevo);
                nuevo->setAbajo(aux);
                aux->setArriba(nuevo);
                insertado =true;
                break;
            }
            aux = aux->getAbajo();
        }
        if(!(insertado))
        {
            nuevo->setArriba(aux);
            aux->setAbajo(nuevo);
        }

    }
}


interno *cabeceraDia::getInicial()
{
    return this->Inicial;
}

int cabeceraDia::getDato()
{
    return this->dato;
}

string cabeceraDia::getDia()
{
    return this->dia;
}

void cabeceraDia::setInicial(interno *act)
{
    this->Inicial = act;
}

cabeceraDia *cabeceraDia::getSig()
{
    return this->sig;
}

void cabeceraDia::setSig(cabeceraDia *next)
{
    this->sig = next;
}

void cabeceraDia::imprimir()
{
    interno*aux = this->getInicial();
    while(aux != NULL)
    {
        cout<<aux->getActividad()<<endl;
        aux = aux->getAbajo();
    }
}



cabeceraDia::~cabeceraDia()
{
    //dtor
}
