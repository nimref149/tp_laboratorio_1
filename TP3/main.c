#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir

*****************************************************/
int main()
{
    int flag=0;
    int flag2=0;
    int opcion;
    int respuesta;
    LinkedList* listaEmpleados =ll_newLinkedList();
    do
    {
        while(getIntValid(&opcion,"***Menu***\n1-Cargar los datos de los empleados desde el archivo data.csv\n2.Cargar los datos de los empleados desde el archivo data.dat (modo binario)\n3.Alta de empleado\n4.Modificar datos de empleado\n5.Baja de empleado\n6.Listar empleados\n7.Ordenar empleados\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9.Guardar los datos de los empleados en el archivo data.csv (modo binario)\n10-Salir\n","Error",1,10)==-1)
        {
            system("pause");
            system("cls");
        }

        switch(opcion)
        {
        case 1:
            if(flag==0&&flag2==0)
            {
                respuesta=controller_loadFromText("data.csv",listaEmpleados);
                switch(respuesta)
                {
                case -2:
                    printf("Hubo un error con la lista");
                    break;
                case -1:
                    printf("No se pudo abrir el archivo\n");
                    break;
                case 0:
                    printf("ha habido un error con el archivo\n");
                    break;
                case 1:
                    printf("Se cargaron los datos correctamente\n");
                    break;
                }
                flag=1;
            }
            else
            {
                printf("Ya se cargaron los datos\n");
            }
            break;
        case 2:
            if(flag2==0&&flag==0)
            {

                respuesta=controller_loadFromBinary("data.dat",listaEmpleados);
                switch(respuesta)
                {
                case -2:
                    printf("Hubo un error con la lista");
                    break;
                case -1:
                    printf("No se pudo abrir el archivo\n");
                    break;
                case 0:
                    printf("ha habido un error con el archivo\n");
                    break;
                case 1:
                    printf("Se cargaron los datos correctamente\n");
                    break;
                }
                flag2=1;
            }
            else
            {
                printf("Ya se cargaron los datos\n");
            }
            break;
        case 3:

            respuesta=controller_addEmployee(listaEmpleados);
            switch(respuesta)
            {
            case -2:
                printf("No hay datos cargados\n");
                break;
            case -1:
                printf("Hubo un error con la lista\n");
                break;
            case 0:
                printf("Empleado no cargado\n");
                break;
            case 1:
                printf("El empleado se cargo exitosamente\n");
                break;
            }
            break;

        case 4:
            respuesta=controller_editEmployee(listaEmpleados);
            switch(respuesta)
            {
            case -3:
                printf("No se encontro al empleado\n");
                break;
            case -2:
                printf("No hay datos cargados\n");
                break;
            case -1:
                printf("Hubo un error con la lista\n");
                break;
            case 0:
                printf("Empleado no modificado\n");
                break;
            case 1:
                printf("El empleado se modifico exitosamente\n");
                break;
            }
            break;

        case 5:

            respuesta=controller_removeEmployee(listaEmpleados);
            switch(respuesta)
            {
            case -3:
                printf("No se encontro al empleado\n");
                break;
            case -2:
                printf("No hay datos cargados\n");
                break;
            case -1:
                printf("Hubo un error con la lista\n");
                break;
            case 0:
                printf("Empleado no eliminado\n");
                break;
            case 1:
                printf("El empleado se elimino exitosamente\n");
                break;
            }
            break;

        case 6:

            respuesta=controller_ListEmployee(listaEmpleados);
            switch(respuesta)
            {
            case -2:
                printf("No hay datos cargados\n");
                break;
            case -1:
                printf("Hubo un error con la lista\n");
                break;
            case 1:
                printf("Se ha listado correctamente\n");
                break;
            }
            break;

        case 7:
            respuesta=controller_sortEmployee(listaEmpleados);
            switch(respuesta)
            {
            case -2:
                printf("No hay datos cargados\n");
                break;
            case 0:
                printf("No se ha ordenado\n");
                break;
            case 1:
                printf("Se ha ordenado correctamente\n");
                break;
            case -1:
                printf("Hubo un error con la lista\n");
                break;
            }
            break;

        case 8:
            if(flag==1)
            {
                respuesta=controller_saveAsText("data.csv",listaEmpleados);
                switch(respuesta)
                {
                case -2:
                    printf("Hubo un error con la lista");
                    break;
                case -1:
                    printf("No se pudo abrir el archivo\n");
                    break;
                case 1:
                    printf("Se guardaron los datos correctamente\n");
                    break;
                }
            }
            else
            {
                printf("Solo se puede guardar en texto\n");
            }
            break;

        case 9:
            if(flag2==1)
            {
                respuesta=controller_saveAsBinary("data.dat",listaEmpleados);
                switch(respuesta)
                {
                case -2:
                    printf("Hubo un error con la lista");
                    break;
                case -1:
                    printf("No se pudo abrir el archivo\n");
                    break;
                case 1:
                    printf("Se guardaron los datos correctamente\n");
                    break;
                }
            }
            else
            {
                printf("Solo se puede guardar en binario\n");
            }
            break;
        case 10:

            printf("Saliendo de programa\n");
            break;

        }
        system("pause");
        system("cls");
    }
    while(opcion != 10);

    return 0;
}


