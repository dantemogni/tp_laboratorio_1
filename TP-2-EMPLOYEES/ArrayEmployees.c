#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

void mainMenu(eEmployee* list, int len)
{
    int option;
    system("cls");
    printf("\nADMINISTRACION DE NOMINA DE EMPLEADOS\n");
    int flag=0;
    do
    {
    printf("\n1 - ALTA \n");
    printf("2 - MODIFICACION \n");
    printf("3 - BAJA \n");
    printf("4 - LISTAR \n");
    printf("5 - SALIR\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&option);

    while(option<0 || option>5)
    {
        printf("Error, ingrese una opcion entre 1 y 5: \n");
        scanf("%d",&option);
        fflush(stdin);
    }
    int idEmployee = 0;

        switch(option)
        {

        case 1:
            enterEmployee(list,len,&idEmployee);
            flag=1;
            break;
        case 2:
            if(flag==1)
            {
                changeEmployee(list,len);
            }
            else
            {
                printf("Error, ningun empleado ha sido ingresado\n");
            }
            system("pause");
            break;
        case 3:
            if(flag==1)
            {
                deleteEmployee(list,len);
            }
            else
            {
                printf("Error, ningun empleado ha sido ingresado\n");
            }
            system("pause");

            break;
        case 4:
            if(flag==1)
            {
                sortEmployees(list,len,1);
                printEmployees(list,len);
            }
            else
            {
                printf("Error, ningun empleado ha sido ingresado\n");
            }
            system("pause");
            break;
        }
    } while(option != 5);
}

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

    int retorno=-1;
    if (list!=NULL && len>0)
    {
        strcpy (list[id].name,name);
        strcpy (list[id].lastName,lastName);
        list[id].salary = salary;
        list[id].sector = sector;
        list[id].isEmpty=0;
        retorno=0;
    }
    return retorno;
}
int initEmployees(eEmployee* list,int len)
{
    int retorno=-1;
    if (list != NULL && len>0)
    {
        for (int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
int findEmployeeById(eEmployee* list, int len,int id)
{
    int retorno=-1;
    if (list!=NULL && len>0)
    {
        for (int i=0; i<len; i++)
        {
            if (list[i].id==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int removeEmployee(eEmployee* list, int len, int id)
{
    int retorno=-1;
    if (list!=NULL && len>0)
    {
        for (int i=0; i<len; i++)
        {
            if (list[i].id==id)
            {
                list[i].isEmpty=1;
                retorno=0;
                break;
            }
            else
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}
int sortEmployees(eEmployee* list, int len, int order)
{
    int sortMenu;
    eEmployee aux;
    int retorno=-1;
    float sumaSalary=0;
    int counter=0;
    float totalAverage;
    int i;
    int j;

    printf("\n1 - LISTADO DE LOS EMPLEADOS ORDENADOS POR APELLIDO Y SECTOR\n2 - TOTAL Y PROMEDIO DE LOS SALARIOS\n");
    scanf("%d", &sortMenu);
    switch(sortMenu)
    {
    case 1:
        if (list!=NULL && len>0)
        {
            for (i=0; i<len-1; i++)
            {
                for (j=i+1; j<len; j++)
                {
                    if (order==1)
                    {
                        if (strcmp(list[i].lastName,list[j].lastName)>0)
                        {
                            aux = list[i];
                            list[i]=list[j];
                            list[j]=aux;
                        }
                        else if (strcmp(list[i].lastName,list[j].lastName)==0)
                        {
                            if (list[i].sector>list[j].sector)
                            {
                                aux = list[i];
                                list[i]=list[j];
                                list[j]=aux;
                            }
                        }
                    }
                }
            }
            retorno=0;
        }
        return retorno;
        printEmployees(list,len);
        break;

    case 2:
        for(i=0; i<len; i++)
        {
            if (list[i].isEmpty==0)
            {
                sumaSalary = list[i].salary + sumaSalary;
                counter++;
            }
        }
        totalAverage = sumaSalary/counter;
        printf("\nTOTAL SALARIOS: %.f\n", sumaSalary);
        printf("PROMEDIO SALARIOS: %.f\n", totalAverage);

        break;
    default:
        printf("\nOpcion invalida.\n");
        break;
    }
}

int printEmployees(eEmployee* list, int len)
{
    int retorno=-1;
    if (list!=NULL && len>0)
    {
        printf("ID \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR\n");
        for (int i=0; i<len; i++)
        {
            if (list[i].isEmpty==0)
            {
                printEmploye(list[i]);
                retorno=0;
            }
        }
    }
    return retorno;
}

void printEmploye(eEmployee list)
{
    printf("%d \t %s \t\t %s \t\t %.f \t\t %d\n",list.id,list.name,list.lastName,list.salary,list.sector);
}

int searchFreeEmployees(eEmployee* list, int len)
{
    int i;
    int index = -1;
    for( i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void enterEmployee(eEmployee* list, int len, int* pId)
{
    eEmployee nuevoEmployee;
    int idEmployee = *pId;
    int index;
    char name[51];
    char lastName[51];
    int sector;
    float salary;

    index = searchFreeEmployees(list, len);

    if(index== -1 )
    {
        printf("\nNo hay espacios libres.\n\n");
    }
    else
    {
        nuevoEmployee.id = idEmployee;

        nuevoEmployee.isEmpty=0;

        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(name);

        while((name[index] != ' ') && (name[index] < 'a' || name[index] > 'z') && (name[index] < 'A' || name[index] > 'Z'))
        {
            printf("ERROR, reingrese el nombre: ");
            fflush(stdin);
            gets(name);
        }

        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(lastName);

        while((lastName[index] != ' ') && (lastName[index] < 'a' || lastName[index] > 'z') && (lastName[index] < 'A' || lastName[index] > 'Z'))
        {
            printf("ERROR, reingrese el apellido: ");
            fflush(stdin);
            gets(lastName);
        }

        printf("Ingrese salario: ");
        scanf("%f",&salary);

        /* while(salario < 0 || salario > 9)
         {
         printf("ERROR, reingrese el salario: ");
         fflush(stdin);
         scanf("%f",&salario);
         }
         */
        printf("Ingrese sector: ");
        scanf("%d",&sector);

        /* while(sector < 0 || sector > 9)
        {
        printf("ERROR, reingrese el sector: ");
        fflush(stdin);
        scanf("%f",&sector);
        }
        */

        list[index] = nuevoEmployee;

        *pId = idEmployee +1;

        nuevoEmployee.isEmpty = 0;

        list[index] = nuevoEmployee;

        addEmployee(list,len,idEmployee,name,lastName,salary,sector);
    }
}

void changeEmployee(eEmployee* list, int len)
{
    int auxId;
    int toModify;
    char confirma;
    char newLastName[51];
    char newName[51];
    float newSalary;
    int newSector;

    system("cls");
    printf("MODIFICACION DE EMPLEADOS\n\n");

    printEmployees(list,len);

    printf("Ingrese el ID del empleado a modificar: ");
    scanf("%d", &auxId);

    toModify = findEmployeeById(list, len, auxId);

    if(toModify == -1)
    {
        printf("\nEl ID %d no se encuentra en el sistema\n\n", auxId);

    }
    else
    {
        printEmploye(list[toModify]);
        do
        {
            switch(changeMenu())
            {
            case 1:
                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(newName);
                while((newName[toModify] != ' ') && (newName[toModify] < 'a' || newName[toModify] > 'z') && (newName[toModify] < 'A' || newName[toModify] > 'Z'))
                {
                printf("\nERROR. Ingrese nuevo nombre valido: ");
                fflush(stdin);
                gets(newName);
                }
                strcpy(list[toModify].name, newName);
                break;
            case 2:
                 printf("\nIngrese nuevo apellido: ");
                fflush(stdin);
                gets(newLastName);
                 while((newLastName[toModify] != ' ') && (newLastName[toModify] < 'a' || newLastName[toModify] > 'z') && (newLastName[toModify] < 'A' || newLastName[toModify] > 'Z'))
                {
                printf("\nERROR. Ingrese nuevo apellido valido: ");
                fflush(stdin);
                gets(newLastName);
                }
                strcpy(list[toModify].lastName, newLastName);
                break;
            case 3:
                printf("Ingrese nuevo salario: ");
                fflush(stdin);
                scanf("%f", &newSalary);
                list[toModify].salary = newSalary;
                break;
            case 4:
                printf("Ingrese nuevo sector: ");
                scanf("%d", &newSector);
                list[toModify].sector = newSector;
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
            }
        }
        while(changeMenu()!=5);
    }
}

int changeMenu()
{
    int option;
    system("cls");
    printf("\nMODIFICAR EMPLEADO:\n\n");
    printf(" 1- NOMBRE \n");
    printf(" 2- APELLIDO \n");
    printf(" 3- SALARIO \n");
    printf(" 4- SECTOR\n");
    printf(" 5- SALIR\n\n");
    printf(" Ingrese opcion: \n");
    scanf("%d",&option);

    while(option<0 || option>5)
    {
        printf("ERROR. Vuelva a ingresar una opcion: \n");
        scanf("%d",&option);
        fflush(stdin);
    }
    return option;
}

void deleteEmployee(eEmployee* list, int len)
{
    int auxId;
    int toDelete;

    system("cls");
    printf("BAJA DE EMPLEADO\n\n");

    printEmployees(list, len);

    printf("Ingrese el ID del empleado a dar de baja:\n");
    while(scanf("%d", &auxId) !=1)
    {
        printf("ERROR. Reingrese un ID: ");
        scanf("%d", &auxId);
        fflush(stdin);
    }

    toDelete = findEmployeeById(list,len, auxId);

    if(toDelete== -1)
    {
        printf("\nEl ID %d no se encuentra en el sistema.\n\n", auxId);
    }
    else
    {
        printEmploye(list[toDelete]);

         removeEmployee(list,len,auxId);
    }
}
