#include "ArrayEmployees.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

int initEmployees(Employee empleados[],int tam)
{
    int retorno=-1;
    int i;
    if(empleados!=NULL && tam>0)
    {

        for(i=0; i<tam; i++)
        {
            empleados[i].isEmpty=LIBRE;
        }
        retorno=0;

    }
    return retorno;
}


int cargarEmpleado(Employee empleados[],int tam)
{
    int retorno;
    int index;
    index=buscarLibre(empleados,tam);
    if(index!=-1)
    {
        retorno=addEmployees(empleados,tam,&empleados[index].id,empleados[index].name,empleados[index].lastName,&empleados[index].salary,&empleados[index].sector);
        empleados[index].isEmpty=OCUPADO;
    }
    else
    {
        retorno=1;
    }
    return retorno;
}

int addEmployees(Employee empleados[],int tam,int *id,char name[],char apellido[],float *salario,int *sector)
{
    //funcion para id automatico;

    int retorno;
    if(tam>0 && empleados!=NULL && ((buscarLibre(empleados,tam))!=-1))
    {
        do
        {
            *id=autoId(empleados,tam);
            while((getStringLetras(name,"Ingrese nombre: ","Error",1,51))==-1);
            while((getStringLetras(apellido,"Ingrese apellido: ","Error",1,51))==-1);
            while((getFloatValid(salario,"Ingrese salario: ","Error",1,100000))==-1);
            while((getIntValid(sector,"Ingrese sector: [1][2][3]\n","Error",1,3))==-1);
            retorno=0;
        }
        while((confirm())==0);
    }
    else
    {
        retorno = -1;
    }

    return retorno;

}


int buscarLibre(Employee empleados[],int tam)
{
    int retorno=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty==LIBRE)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int autoId(Employee lista[],int tam)
{
    int retorno;
    int idMayor;
    idMayor=buscarIdMayor(lista,tam);
    if(idMayor!=-1)
    {
        retorno=idMayor+1;
    }
    else
    {
        retorno=1;
    }

    return retorno;
}

int buscarIdMayor(Employee lista[],int tam)
{
    int retorno=-1;
    int i;
    int flag=0;
    int mayor;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            if(lista[i].id>mayor || flag==0)
            {
                mayor=lista[i].id;
                flag=1;
            }
        }
    }
    if(flag!=0)
    {
        retorno=mayor;
    }
    return retorno;
}

int findEmployeeById(Employee empleados[],int tam,int id)
{
    int retorno=-1;
    int i;
    if(empleados!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(empleados[i].id==id && empleados[i].isEmpty==OCUPADO)
            {
                retorno=i;

                break;
            }

        }
    }
    return retorno;
}


int removeEmployee(Employee empleados[],int tam,int id)
{
    int retorno=-1;
    int index;
    int respuesta;
    index=findEmployeeById(empleados,tam,id);
    if(empleados!=NULL && tam>0 && index!=-1)
    {
        mostrarUnEmpleado(empleados[index]);
        respuesta=confirm();
        if(respuesta==1)
        {
            empleados[index].isEmpty=LIBRE;
            retorno=0;
        }
        else
        {
            retorno=1;
        }

    }
    return retorno;
}
void menuListarOrdenar(Employee list[],int tam)
{
    int respuesta;
    int order;
    printf("0-De manera ascendente\n");
    printf("1-De manera descendente\n");
    while((getIntValid(&order,"Ingrese una opcion: ","Error",0,1))==-1);
    respuesta=sortEmployees(list,tam,order);
    switch(respuesta)
    {
    case 0:
        respuesta=printEmployees(list,tam);
        if(respuesta==-1)
        {
            printf("No hay empleados para mostrar\n");
        }
        break;
    case -1:
        printf("No hay para ordenar\n");
        break;
    }

}



int sortEmployees(Employee list[], int tam, int order)
{
    int retorno=-1;
    if(list!=NULL && tam>0)
    {

        if(order==0)
        {
            retorno=ordernarAscendentePorNombreYsector(list,tam);

        }
        else if(order==1)
        {
            retorno=ordernarDescendentePorNombreYsector(list,tam);

        }
    }
    return retorno;
}

int ordernarAscendentePorNombreYsector(Employee lista[],int tam)
{
    int retorno=-1;
    int i;
    int j;
    Employee auxEmpleado;
    for(i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {

            for(j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty==OCUPADO)
                {

                    if(stricmp(lista[i].lastName,lista[j].lastName)>0)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;

                    }

                    else
                    {
                        if(stricmp(lista[i].lastName,lista[j].lastName)==0)
                        {
                            if(lista[i].sector>lista[j].sector)
                            {
                                auxEmpleado = lista[i];
                                lista[i] = lista[j];
                                lista[j] = auxEmpleado;

                            }
                        }
                    }
                    retorno=0;

                }
            }

        }

    }
    return retorno;

}

int ordernarDescendentePorNombreYsector(Employee lista[],int tam)
{
    int retorno=-1;
    int i;
    int j;
    Employee auxEmpleado;
    for(i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            for(j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty==OCUPADO)
                {
                    if(stricmp(lista[i].lastName,lista[j].lastName)<0)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;

                    }

                    else
                    {
                        if(stricmp(lista[i].lastName,lista[j].lastName)==0)
                        {
                            if(lista[i].sector<lista[j].sector)
                            {
                                auxEmpleado = lista[i];
                                lista[i] = lista[j];
                                lista[j] = auxEmpleado;

                            }
                        }
                    }
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}


int printEmployees(Employee list[],int tam)
{
    int retorno=-1;
    int i;
    int hayAlguno;
    hayAlguno=autoId(list,tam);
    if(hayAlguno!=1)
    {
        printf(" id |     nombre    |   apellido    | salario         |     sector       |\n");

        for(i=0; i<tam; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {

                mostrarUnEmpleado(list[i]);

            }
        }
        retorno=0;
    }


    return retorno;
}

void mostrarUnEmpleado(Employee lista)
{

    printf(" %d  |  %-10s   |  %-10s   |   %-10.02f    |      %-10d  |\n",lista.id,lista.name,lista.lastName,lista.salary,lista.sector);

}

int eliminarEmpleadoPorId(Employee lista[],int tam)
{
    int retorno=-1;
    int id;
    retorno=printEmployees(lista,tam);
    if(retorno!=-1)
    {
        while((getIntValid(&id,"Ingrese id de usuario a eliminar: ","Error ",1,10000)==-1));
        retorno=removeEmployee(lista,tam,id);
    }
    return retorno;
}

int modificarEmpleado(Employee lista[],int tam)
{
    int retorno=-1;
    int index;
    int opcion;
    int validar;
    validar=printEmployees(lista,tam);
    while((getIntValid(&index,"Ingrese id de usuario a modificar: ","Error",1,10000))==-1);
    index=findEmployeeById(lista,tam,index);
    if(index!=-1&&validar!=-1)
    {
        mostrarUnEmpleado(lista[index]);
        while((getIntValid(&opcion,"Que desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n","Error",1,4))==-1);
        switch(opcion)
        {
        case 1:
            while((getStringLetras(lista[index].name,"Ingrese nuevo nombre: ","Error",1,51))==-1||confirm()!=1);
            retorno=0;
            break;
        case 2:
            while((getStringLetras(lista[index].lastName,"Ingrese nuevo apellido: ","Error",1,51))==-1||confirm()!=1);
            retorno=0;
            break;
        case 3:
            while((getFloatValid(&lista[index].salary,"Ingrese nuevo salario: ","Error",1,10000))==-1||confirm()!=1);
            retorno=0;
            break;
        case 4:
            while((getIntValid(&lista[index].sector,"Ingrese nuevo Sector [1][2][3] :","Error",1,3))==-1||confirm()!=1);
            retorno=0;
            break;
        }
    }
    return retorno;
}

float salarioTotal(Employee empleados[],int tam)
{
    float acumulador=0;
    int retorno=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty==OCUPADO)
        {
            acumulador=acumulador+empleados[i].salary;
        }

    }
    if(acumulador!=0)
    {
        printf("El salario total es %.2f\n",acumulador);
        retorno=acumulador;
    }
    return retorno;

}


float salarioPromedio(Employee empleados[],int tam)
{
    int contador=0;
    float salarioTotall=0;
    int retorno=-1;
    float promedio;
    int i;
    for(i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty==OCUPADO)
        {
            contador++;
        }
    }
    salarioTotall=salarioTotal(empleados,tam);
    if(salarioTotall!=-1&&contador!=0)
    {
        promedio=salarioTotall/contador;
        printf("El salario promedio es %.2f\n",promedio);
        retorno=promedio;
    }
    return retorno;

}



int cuantosSuperanPromedio(Employee empleados[],int tam)
{
    int retorno=0;
    float promedio;
    int superanPromedio=0;
    int i;
    promedio=salarioPromedio(empleados,tam);
    if(promedio!=-1)
    {
        for(i=0; i<tam; i++)
        {
            if(empleados[i].salary>promedio&&empleados[i].isEmpty==OCUPADO)
            {
                superanPromedio++;
            }

        }
        printf("La cantidad de empleados que superan el promedio es: %d\n",superanPromedio);

    }
    else
    {
        retorno=-1;
    }

    return retorno;
}





