#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"
int pedirDato()
{
    int datoObtenido;
    scanf("%d", &datoObtenido);
    return datoObtenido;
}
void calcular(float numUno, float numDos, int operacion)
{
    float resultado;
    char rta;
    char menu;
    switch(operacion)
    {
    case 1:
        system("cls");
        resultado = sumar(numUno, numDos);
        printf("El resultado es %.2f \n", resultado);
        break;
    case 2:
        system("cls");
        resultado = restar(numUno, numDos);
        printf("El resultado es %.2f \n", resultado);
        break;
    case 3:
        system("cls");
        resultado = multiplicar(numUno, numDos);
        printf("El resultado es %.2f \n", resultado);
        break;
    case 4:
        system("cls");
        resultado = dividir(numUno, numDos);
        break;
    case 5:
        system("cls");
        resultado = factorialUno(numUno);
        printf("El factorial del numero A es: %.2f\n", resultado);
        resultado = factorialDos(numDos);
        printf("El factorial del numero B es: %.2f\n", resultado);
        break;
    case 6:
        system("cls");
        printf("Esta seguro que desea salir? s/n \n");
        fflush(stdin);
        scanf("%c", &rta);
        if(rta=='s')
        {
            printf("Hasta luego...");
        }
        else if(rta=='n')
        {
            system("cls");
            main();
        }
        break;
    default:
        printf("Opcion invalida\n");
    }
}
