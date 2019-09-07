#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
int main()
{
    int opcion,a,b,sumar,restar,multiplicar,factorialDos,factorialUno,flag1=0,flag2=0;
    float dividir;
    char seguir = 's';
    do
    {
        printf("============================\n");
        printf("       Calculadora        \n");
        printf("============================\n");
        if(flag1==1)
            printf("1.Ingresar numero A:%d\n",a);
        else
            printf("1.Ingresar numero A: \n");

        if(flag2==1)
            printf("2.Ingresar numero B:%d\n",b);
        else
            printf("2.Ingresar numero B:\n" );

        printf("3.Calcular todas las operaciones\n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n");
        opcion=ingresarNumero("Ingrese una opcion: ");
        switch(opcion)
        {

        case 1:
            a=ingresarNumero("Ingrese numero: ");
            flag1=1;

            break;
        case 2:
            b=ingresarNumero("Ingresar numero: ");
            flag2=1;
            break;
        case 3:
            if(flag1==1&&flag2==1)
            {
                printf("Calculando los resultados : \n");
                printf("La suma (%d + %d)\n",a,b);
                printf("La resta (%d - %d)\n",a,b);
                printf("La multiplicacion (%d * %d)\n",a,b);
                printf("La division (%d / %d)\n",a,b);
                printf("El factorial(!%d)\n",a);
                printf("El factorial(!%d)\n",b);
                sumar=suma(a,b);
                restar=resta(a,b);
                multiplicar=multiplicacion(a,b);
                if(b!=0)
                {
                    dividir=division(a,b);
                }
                factorialUno=factorial(a);
                factorialDos=factorial(b);
            }
            if(flag1==0)
            {
                printf("No ingreso numero A ");
            }
            if(flag2==0)
            {
                printf("No ingreso numero B ");
            }
            break;

        case 4:
            if(flag1==1&&flag2==1)
            {
                printf("Los resultados son: \n");
                printf("El resultado de la suma de %d + %d es %d \n",a,b,sumar);
                printf("El resultado de la resta de %d - %d es %d \n",a,b,restar);
                printf("El resultado de la multiplicacion de %d * %d es %d \n",a,b,multiplicar);
                if(b==0)
                {
                    printf("No es posible dividir por 0 \n");
                }
                else
                {
                    printf("El resultado de la division de %d / %d es %.2f \n",a,b,dividir);
                }
                comprobarFactorial(a,factorialUno);
                comprobarFactorial(b,factorialDos);
            }

            if(flag1==0)
            {
                printf("No ingreso numero A ");
            }
            if(flag2==0)
            {
                printf("No ingreso numero B ");
            }
            break;
        case 5:
            printf("Saliendo de la calculadora. \n");
            seguir='n';
            break;
        default:
            printf("No ingreso una opcion valida!!\n");
            break;
        }
        system("pause");
        system("cls");

    }
    while(seguir=='s');
    return 0;
}
