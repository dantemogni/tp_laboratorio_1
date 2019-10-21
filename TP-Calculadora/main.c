#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
int main()
{
    float numUno;
    float numDos;
    int opciones;
    float division;
    float resta;
    float multiplicacion;
    float suma;
    float factorialUno;
    float factorialDos;
    int flagNumUno = 0;
    int flagNumDos = 0;
    int flagCalculo = 0;

    printf("\n****BIENVENIDOS A LA CALCULADORA****\n");
    do
    {
        printf("\n1 - Ingrese el primer numero (A=%.2f)\n2 - Ingrese el segundo numero (B=%.2f)", numUno, numDos);
        printf("\n3 - Calcular las operaciones (suma, resta, multiplicacion, division, factorial)\n4 - Ver resultados\n5 - Salir\n");
        printf("Que desea hacer? ");
        scanf("%d", &opciones);
        switch(opciones)
        {
        case 1:
            printf("\nPRIMER NUMERO: ");
            fflush(stdin);
            scanf("%f", &numUno);
            flagNumUno = 1;
            break;
        case 2:
            printf("\nSEGUNDO NUMERO: ");
            fflush(stdin);
            scanf("%f", &numDos);
            flagNumDos = 1;
            break;
        case 3:
            if(flagNumUno==0 || flagNumDos == 0)
            {
                printf("\nERROR. NO SE HAN INGRESADO DOS OPERADORES");
                break;
            }
            printf("\nCalculando resultados...\nResultados listos, presione 4 para visualizarlos\n\n");
            division = dividir(numUno, numDos);
            resta = restar(numUno, numDos);
            multiplicacion = multiplicar(numUno, numDos);
            suma = sumar(numUno, numDos);
            factorialUno = factorial(numUno);
            factorialDos = factorial(numDos);
            flagCalculo = 1;
            break;
        case 4:
            if(flagNumUno==0 || flagNumDos == 0)
            {
                printf("\nERROR. NO SE HAN INGRESADO DOS OPERADORES\n");
                break;
            }
            if(flagCalculo==0)
            {
                printf("\nERROR. NO SE HA REALIZADO EL CALCULO. PRESIONE 3 PARA REALIZARLO\n");
                break;
            }
            printf("\n\nLa suma de %.2f y %.2f es: %.2f", numUno, numDos, suma);
            printf("\n\nLa resta de %.2f y %.2f es: %.2f", numUno, numDos, resta);
            printf("\n\nLa multiplicacion de %.2f y %.2f es: %.2f", numUno, numDos, multiplicacion);
            if(numUno<0)
            {
                printf("\nERROR. NO SE PUEDE OBTENER EL FACTORIAL DE UN NUMERO NEGATIVO");
            }
            else
            {
                printf("\n\nEl factorial de %.2f es: %.2f", numUno, factorialUno);

            }
            if(numDos<0)
            {
                printf("\nERROR. NO SE PUEDE OBTENER EL FACTORIAL DE UN NUMERO NEGATIVO");
            }
            else
            {
                printf("\n\nEl factorial de %.2f es: %.2f", numDos, factorialDos);
            }
            if(numDos==0)
            {
                printf("\nERROR. NO SE PUEDE DIVIDIR POR CERO\n");
            }
            else
            {
                printf("\n\nLa division de %.2f y %.2f es: %.2f", numUno, numDos, division);
            }
            break;
        }
    }
    while(opciones!=5);
    return 0;
}
