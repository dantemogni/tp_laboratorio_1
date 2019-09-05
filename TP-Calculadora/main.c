#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    printf("Bienvenidos a la calculadora\n1-Ingresar 1er operando (A=x)\n");
    float numUno = pedirDato();
    fflush(stdin);
    printf("2-Ingresar 2do operando (B=y)\n");
    float numDos = pedirDato();
    system("pause");
    system("cls");
    printf("Ingresaste: A=%.2f y B=%.2f", numUno, numDos);
    printf("\nCalcular las operaciones:\n\t1-Calcular la suma (A+B)\n\t2-Calcular la resta (A-B)\n\t3-Calcular la multiplicacion (A*B)\n\t4-Calcular la division (A/B)\n\t5-Calcular el factorial (A!)\n\t6-Salir\n");
    int operacion = pedirDato();
    calcular(numUno,numDos,operacion);
}
