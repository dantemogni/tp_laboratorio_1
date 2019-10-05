#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define EMPLOYEE_QUANTITY 1000

int main()
{
    eEmployee employee[EMPLOYEE_QUANTITY];
    initEmployees(employee,EMPLOYEE_QUANTITY);
    mainMenu(employee, EMPLOYEE_QUANTITY);
    return 0;
}


