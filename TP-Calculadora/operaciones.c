#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float sumar(float numUno, float numDos)
{
    float suma = numUno+numDos;
    return suma;
}
float restar(float numUno, float numDos)
{
    float resta=numUno-numDos;
    return resta;
}
float multiplicar(float numUno, float numDos)
{
    float multiplico=numUno*numDos;
    return multiplico;
}
float dividir(float numUno, float numDos)
{
    if(numDos!=0)
    {
        float division=numUno/numDos;
        printf("El resultado es %.2f \n", division);
        return division;
    }
    else
    {
        printf("No se puede dividir por cero.\n");
    }

}
float factorialUno(float numUno)
{
    float factorizacionUno;
    if(numUno==0)
    {
        factorizacionUno = 1;
    }
    else
    {
        factorizacionUno = numUno * factorialUno(numUno-1);
    }
    return factorizacionUno;
}
float factorialDos(float numDos)
{
    float factorizacionDos;
    if(numDos==0)
    {
        factorizacionDos = 1;
    }
    else
    {
        factorizacionDos = numDos * factorialDos(numDos-1);
    }
    return factorizacionDos;
}

