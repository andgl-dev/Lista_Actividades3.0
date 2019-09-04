#include "matriz.h"

matriz::matriz()
{
    this->diaUno=NULL;
    this->horaUno=NULL;
}


void matriz::crearActividad(const string& dia,const string& hora, const string& act)
{
    cabeceraDia* cabDia = new cabeceraDia(dia);
    cabeceraHora* cabHora = new cabeceraHora(hora);
    interno * actividad = new interno(cabDia->getDato(),cabHora->getHora(),act);
    this->insertarEnDia(cabDia,actividad);
    this->insertarEnHora(cabHora,actividad);
}

void matriz:: insertarEnDia(cabeceraDia* cabDia, interno* actividad)
{
    if(this->diaUno == NULL)
    {
        cabDia->insertarAct(actividad);
        this->diaUno = cabDia;
    }
    else if(cabDia->getDato() < this->diaUno->getDato())
    {
        cabDia->insertarAct(actividad);
        cabDia->setSig(this->diaUno);
        this->diaUno = cabDia;
    }
    else
    {
        cabeceraDia* aux= this->diaUno;
        bool existe = false;
        while(aux->getSig() != NULL)
        {
            if(aux->getDato() == cabDia->getDato())
            {
                aux->insertarAct(actividad);
                existe = true;
                break;
            }
            else if(aux->getSig()->getDato() > cabDia->getDato())
            {
                cabDia->insertarAct(actividad);
                cabDia->setSig(aux->getSig());
                aux->setSig(cabDia);
                existe = true;
                break;
            }
            aux = aux->getSig();
        }
        if(!existe)
        {
            if(aux->getDato() == cabDia->getDato())
            {
                aux->insertarAct(actividad);
            }
            else
            {
                cabDia->insertarAct(actividad);
                aux->setSig(cabDia);
            }
        }

    }

}

void matriz::insertarEnHora(cabeceraHora* nuevo,interno* actividad)
{
    if(this->horaUno == NULL)
    {
        nuevo->insertarAct(actividad);
        this->horaUno = nuevo;
    }
    else if(nuevo->getHora() < this->horaUno->getHora())
    {
        nuevo->insertarAct(actividad);
        nuevo->setAbajo(this->horaUno);
        this->horaUno = nuevo;
    }
    else
    {
        cabeceraHora * aux = this->horaUno;
        bool insertado = false;
        while(aux->getAbajo() != NULL)
        {
            if(aux->getHora()==nuevo->getHora())
            {
                aux->insertarAct(actividad);
                insertado = true;
                break;
            }
            else if(nuevo->getHora() < aux->getAbajo()->getHora())
            {
                nuevo->insertarAct(actividad);
                nuevo->setAbajo(aux->getAbajo());
                aux->setAbajo(nuevo);
                insertado = true;
                break;
            }
            aux = aux->getAbajo();
        }
        if(!(insertado))
        {
            if(aux->getHora() == nuevo->getHora())
            {
                aux->insertarAct(actividad);
            }
            else
            {
                nuevo->insertarAct(actividad);
                aux->setAbajo(nuevo);
            }

        }
    }
}

void matriz::imprimirMAtriz()
{
    if(this->diaUno != NULL)
    {
        cabeceraDia*aux = this->diaUno;
        cabeceraHora*aux2 = this->horaUno;
        cout <<"Imprimiendo Actividades"<<endl;
        while(aux != NULL)
        {
            cout <<"Dia: "<<aux->getDia()<<endl;
            interno*auxAct = aux->getInicial();
            while(auxAct != NULL)
            {
                cout <<"Actividad: "<<auxAct->getActividad()<<" hora: "<<auxAct->hr<<endl;
                auxAct = auxAct->getAbajo();
            }
            cout <<"---------------------------------------"<<endl;
            aux=aux->getSig();
        }

        cout <<"---------Imprimiendo por horas-------------"<<endl;

        while(aux2 != NULL)
        {
            cout <<"Hora: "<<aux2->getStHora()<<" --> "<<ends;
            interno*auxAct = aux2->getInicial();
            while(auxAct != NULL)
            {
                cout <<"Actividad: "<<auxAct->getActividad()<<" dia: "<<auxAct->dia<<" --> "<<ends;
                auxAct = auxAct->getSiguiente();
            }
            cout<<"\n"<<endl;
            aux2=aux2->getAbajo();
        }

    }
    else
    {
        cout <<"la lista de actividades esta vacia"<<endl;
    }

}



void matriz::imprimirDia(const string &dia)
{
    if(this->diaUno != NULL)
    {
        cabeceraDia *aux = this->diaUno;
        while(aux != NULL)
        {
            if(aux->getDia()==dia)
            {
                break;
            }
            aux = aux->getSig();
        }
        if(aux != NULL)
        {
            std::cout <<"---------------------------------------"<<std::endl;
            std::cout <<"Dia: "<<aux->getDia()<<std::endl;
            interno* auxAct = aux->getInicial();
            while(auxAct != NULL)
            {
                std::cout <<"Actividad: "<<auxAct->getActividad()<<std::endl;
                auxAct = auxAct->getAbajo();
            }
            std::cout <<"---------------------------------------"<<std::endl;
        }
        else
        {
            std::cout <<"El dia "<<dia<< " no existe :'("<<std::endl;
        }
    }
    else
    {
        std::cout <<"la lista de actividades esta vacia"<<std::endl;
    }
}

void matriz:: graficarMatriz()
{
    if(this->diaUno != NULL){
    ofstream archivo; //declarando
    archivo.open("grafo.dot",ios::out); //abriendo o creando el archivo
    if(archivo.fail())
    {
        cout<<"no se pudo abrir archivo"<<endl;
        exit(1);
    }
    archivo<<"digraph G{\n";
    archivo<<"ranksep=.75;";
    archivo<<" size= \"4.5,4.5\";\n{";
    archivo<<"node [shape = plaintext,font=16];\n";
    cabeceraDia* aux = this->diaUno;
    cabeceraHora* aux2 = this->horaUno;
    archivo<<"\"Inicio\"->";
    archivo<<"\""+aux2->getStHora()+"\"\n";
    //para las horas
    while(aux2 != NULL)
        {
            archivo<<"\""+aux2->getStHora()+"\"";
            if(aux2->getAbajo() !=NULL)
                {
                    archivo<<"->";
                }
            aux2 = aux2->getAbajo();
        }
        archivo<<";}";
    archivo<<"node [shape=box];{ rank = same; \"Inicio\"->";
    while(aux!=NULL)
        {
            archivo<<"\""+aux->getDia()+"\"";
            if(aux->getSig() != NULL)
                {
                    archivo<<"->";
                }
            aux = aux->getSig();
        }
        archivo<<";}";
     aux2=this->horaUno;

     while(aux2 !=NULL)
        {
            archivo<<"{rank =same;\""+aux2->getStHora()+"\"->";
            interno* aux3=aux2->getInicial();
            while(aux3 != NULL)
                {
                    if(aux3->getSiguiente() != NULL)
                        {
                            archivo<<"\""+aux3->getActividad()+"\""+"->\""+aux3->getSiguiente()->getActividad()+"\";\n";
                            archivo<<"\""+aux3->getSiguiente()->getActividad()+"\"->"+"\""+aux3->getActividad()+"\";\n";
                        }
                    else if(aux3==aux2->getInicial())
                        {
                            archivo<<"\""+aux3->getActividad()+"\";";
                        }
                    aux3 = aux3->getSiguiente();
                }
                archivo<<"}\n";
                aux2 = aux2->getAbajo();
        }

    aux=this->diaUno;
    while(aux != NULL)
        {
            interno* aux3 = aux->getInicial();
            while(aux3 != NULL)
                {
                    if(aux3->getArriba()!=NULL)
                        {
                            archivo<<"\""+aux3->getActividad()+"\"->"+"\""+aux3->getArriba()->getActividad()+"\";\n";
                            archivo<<"\""+aux3->getArriba()->getActividad()+"\"->"+"\""+aux3->getActividad()+"\";\n";
                        }
                        aux3 = aux3->getAbajo();
                }
                archivo<<"\""+aux->getDia()+"\"->"+"\""+aux->getInicial()->getActividad()+"\";\n";
                aux = aux->getSig();
        }

    archivo<<"}";
    archivo.close();//cerrando archivo
    system("dot -Tpng grafo.dot -o grafo.png");
    system("nohup display grafo.png &" );
    }
    else
        {
            cout<<"No hay matriz xD"<<endl;
        }
}


matriz::~matriz()
{
    //dtor
}
