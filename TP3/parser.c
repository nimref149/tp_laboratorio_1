#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno;

    char id[100],nombre[100], horasTrabajadas[51], sueldo[20];
    Employee* aux=NULL;;
    if(pFile!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas,sueldo);//lectura falsa
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas,sueldo);

            aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            ll_add(pArrayListEmployee,aux);

            //printf("\n%d\n",ll_len(pArrayListEmployee));


        }
        retorno=1;
    }else
    {
        retorno=0;
    }
    return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno;
    Employee* aux;
    int respuesta;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        //aux = (Employee*) malloc(sizeof(Employee));
        while(!feof(pFile))
        {
            aux= employee_new();
            respuesta=fread(aux, sizeof(Employee), 1, pFile);
            if(respuesta == 1 && aux != NULL)
            {
                ll_add(pArrayListEmployee, aux);
            }
        }
        retorno=1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}



