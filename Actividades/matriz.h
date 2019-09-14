#ifndef MATRIZ_H
#define MATRIZ_H
#include <fstream>
#include "cabeceraDia.h"
#include "cabeceraHora.h"

class matriz
{
public:
    matriz();
    void crearActividad(const string& dia,const string& hora, const string& act);
    void imprimirDia(const string& dia);
    void insertarEnDia(cabeceraDia*nuevo, interno* actividad);
    void insertarEnHora(cabeceraHora* nuevo,interno* actividad);
    void graficarMatriz();
    void imprimirMAtriz();
    virtual ~matriz();
private:
    cabeceraDia* diaUno;
    cabeceraHora* horaUno;
};

#endif // MATRIZ_H
