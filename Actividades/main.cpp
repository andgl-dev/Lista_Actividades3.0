#include "matriz.h"

using namespace std;

int main()
{
    matriz *ma = new matriz();
/*
    ma->crearActividad("lunes","3pm","sudo");
    ma->crearActividad("lunes","4pm","apt");
    ma->crearActividad("martes","3pm","get");
    ma->crearActividad("miercoles","4pm","br");
    ma->crearActividad("miercoles","5pm","str");
    ma->crearActividad("lunes","6pm","ab");
    ma->crearActividad("viernes","1pm","sss");
    ma->crearActividad("jueves","2pm","asd");
    ma->crearActividad("viernes","4pm","sad");
    ma->crearActividad("miercoles","2pm","dddd");
    ma->imprimirMAtriz();
    ma->graficarMatriz();
*/
    int opcion = 10;
    while(opcion != 0)
        {
            cout<<"Buenas"<<endl;
            cout<<"Ingrese el numero de la opcion a elegir"<<endl;
            cout<<"1. Crear una Actividad"<<endl;
            cout<<"2. Graficar Matriz"<<endl;
            cout<<"3. Ver Actividades de un dia especifico"<<endl;
            cout<<"0. Salir"<<endl;
            cin>>opcion;
            switch(opcion)
            {
            case 1:{
                string dia="";
                string hora="";
                string Actividad="";
                cout<<"Ingrese dia [Lunes - Domingo]"<<endl;
                cin>>dia;
                cout<<"Ingrese una hora [3am o 5pm]"<<endl;
                cin>>hora;
                cout<<"Ingrese una Actividad"<<endl;
                cin>>Actividad;
                ma->crearActividad(dia,hora,Actividad);
                break;
                    }
            case 2:{
                ma->graficarMatriz();
                break;
                    }
            case 3:{
                string d="";
                cout<<"Ingrese dia [Lunes - Domingo]"<<endl;
                cin>>d;
                ma->imprimirDia(d);
                break;
                }
            case 0:
                exit(1);
                break;
            default:
                cout<<"Siga las instrucciones";
                break;
            }
        }


    return 0;
}
