#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

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
    float division;
    division=numUno/numDos;
    return division;
}
float factorial (float numero)
{
    float factorial;
    float resultadoFactorial = 1;

    for (factorial = numero; factorial > 0; factorial--)
    {
        resultadoFactorial *= factorial;
    }

    return resultadoFactorial;
}

