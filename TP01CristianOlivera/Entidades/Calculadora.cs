using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public static class Calculadora
    {
        #region METODOS
        /// <summary>
        /// Realiza una operacion entre dos objetos tipo Numero de acuerdo al operador ingresado como argumento
        /// </summary>
        /// <param name="num1"></param>
        /// <param name="num2"></param>
        /// <param name="operador"></param>
        /// <returns></returns>retorna el resultado de la operacion
        public static double Operar(Numero num1, Numero num2, string operador) 
        {
            double resultado=0;

            switch(ValidarOperador(operador)) 
            {
                case "-":
                    resultado = num1 - num2;
                    break;
                case "+":
                    resultado = num1 + num2;
                    break;
                case "*":
                    resultado = num1 * num2;
                    break;
                case "/":
                    resultado = num1 / num2;
                    break;
                default:
                    break;
            }
            return resultado;
        }
        /// <summary>
        /// Valida si el operador ingresado como argumento es correcto(+-/*)
        /// </summary>
        /// <param name="operador"></param>
        /// <returns></returns>Si es correcto retorna el operador,caso contrario retorna "+"
        private static string ValidarOperador(string operador) 
        {
            string retorno = "+";
            
            if (operador == "-" || operador == "+" || operador== "*" || operador == "/")
            {
                retorno = operador;
            }
       
            return retorno;
        }
        #endregion

    }
}
