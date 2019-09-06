#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int menu()
{
    printf("Bienvenidos a la calculadora!\n");
    printf("\n1-Ingrese el primer numero (A=x)\n");
    float numUno = pedirDato();
    fflush(stdin);
    printf("2-Ingrese el segundo (B=y)\n");
    float numDos = pedirDato();
    system("pause");
    system("cls");
    printf("Ingresaste: A=%.2f y B=%.2f", numUno, numDos);
    printf("\n\n---------------------------\n");
    printf("\nQue desea hacer?\n");
    printf("\n3-Calcular las operaciones (suma, resta, multiplicacion, division, factorial)\n4-Ver resultados\n5-Salir\n");
    int operacion = pedirDato();
    calcular(numUno,numDos,operacion);
}
int pedirDato()
{
    int datoObtenido;
    scanf("%d", &datoObtenido);
    return datoObtenido;
}
void calcular(float numUno, float numDos, int operacion)
{
    float resultadoSuma;
    float resultadoResta;
    float resultadoMulti;
    float resultadoFac1;
    float division;
    float resultadoFac2;
    char rta;
    int flag = 0;
    switch(operacion)
    {
    case 3:

        printf("Calculando resultados...\nResultados listos, presione 4 para visualizarlos\n");
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
        fflush(stdin);

        resultadoSuma = sumar(numUno, numDos);
        resultadoResta = restar(numUno, numDos);
        resultadoMulti = multiplicar(numUno, numDos);
        division = dividir(numUno, numDos);
        resultadoFac1 = factorialUno(numUno);
        resultadoFac2 = factorialDos(numDos);
        while(!(pedirDato()==4))
        {
            printf("\nError, ingrese 4 para ver los resultados\n");
        }
        flag = 1;
    case 4:
        system("cls");
        if(flag==0)
        {
            printf("\n\aERROR! Primero se deben calcular las operaciones marcando la opcion 3\n");
        }
        else
        {
            printf("\nEl resultado de la suma es: %.2f \n", resultadoSuma);
            printf("\nEl resultado de la resta es: %.2f \n", resultadoResta);
            printf("\nEl resultado de la multiplicacion es: %.2f \n", resultadoMulti);
            if(numDos!=0)
            {
                printf("\nEl resultado de la division es: %.2f \n", division);

            }
            else
            {
                printf("\nNo se puede dividir por cero.\n");

            }
            printf("\nEl factorial del numero A es: %.2f\n", resultadoFac1);
            printf("\nEl factorial del numero B es: %.2f\n", resultadoFac2);
        }



        break;
    case 5:
        printf("\nEsta seguro que desea salir? s/n \n");
        fflush(stdin);
        scanf("%c", &rta);
        if(rta=='s')
        {
            printf("\nHasta luego...");
            return 0;
        }
        else if(rta=='n')
        {
            system("cls");
            return main();
        }
        break;
    default:
        printf("\aOpcion invalida\n");
        return 0;
    }
}
