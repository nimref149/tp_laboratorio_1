#include <stdio.h>
#include "calculos.h"

int ingresarNumero(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    return numero;
}







int suma(int x,int y)
{
int resultado=x+y;
return resultado;
}





int resta(int x,int y){
int resultado=x-y;
return resultado;}






int multiplicacion(int x,int y)
{

    int resultado=x*y;
    return resultado;
}





int factorial(int x)
{
int resultado;
    if(x==1||x==0)
    {
        resultado=1;
    }
    else
    {
        resultado=x*factorial(x-1);
    }
    return resultado;
}





float division(int x,int y)
{
    float resultado=(float)x/y;
    return resultado;
}




void comprobarFactorial(int numero,int factorial)
{
    if(numero<0)
    {
        printf("No existe el factorial de %d ",numero);
    }
    else if(numero>12)
    {
        printf("No es posible escribir ya que el numero es muy grande\n");
    }
    else
    {
        printf("El factorial del numero %d es %d \n",numero,factorial);
    }
}



