using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Numero
    {
        #region ATRIBUTOS
        /// <summary>
        /// Atributo con el cual se realizaran las operaciones 
        /// </summary>
        private double numero;
        #endregion

        #region PROPIEDADES
        /// <summary>
        /// Propiedad set que le asigna un valor al atributo numero de la clase Numero
        /// </summary>
        public string SetNumero
        {
            set
            {
                this.numero = ValidarNumero(value);
            }
        }
        #endregion

        #region CONSTRUCTORES
        /// <summary>
        /// Constructor de la clase Numero que va a inicializar al atributo numero en 0
        /// </summary>
        public Numero()
        {
            this.numero = 0;
        }
        /// <summary>
        /// Sobrecarga del consutrctor de la clase Numero que inicializa a un objeto de tipo Numero con el valor pasado como argumento double
        /// </summary>
        /// <param name="numero"></param>//valor con que se inicializara el atributo
        public Numero(double numero) : this(Convert.ToString(numero))
        { }
        /// <summary>
        /// Sobrecarga de constructor de la clase Numero que inicializa a un objeto de tipo Numero con el valor pasado como argumento string
        /// </summary>
        /// <param name="strNumero"></param>
        public Numero(string strNumero)
        {
            this.SetNumero = strNumero;
        }
        #endregion

        #region METODOS
        /// <summary>
        /// Valida que el numero pasado como argumento string se pueda convertir como double
        /// </summary>
        /// <param name="strNumero"></param>
        /// <returns></returns>//retorna el numero convertido en double caso contrario retornara 0
        private double ValidarNumero(string strNumero)
        {
            double aux;
            double numRetorno = 0;
            if (double.TryParse(strNumero, out aux)) {

                numRetorno = aux;
            }
            return numRetorno;
        }
        /// <summary>
        /// Convierte un numero en binario a decimal verificando
        /// </summary>
        /// <param name="binario"></param>//el numero en binario formato string
        /// <returns></returns>//retorna el valor en decimal si se pudo convertir, caso contrario retornara "valor invalido"
        public static string BinarioDecimal(string binario)
        {
            string invalid = "valor invalido";
            int flag = -1;
            double numero = 0;
            int exponent = 0;//
            int i;
            //101
            bool esBinario = true;
            foreach (char n in binario)
            {
                if (n != '1' && n != '0')
                {
                    esBinario = false;
                    break;
                }
            }

            for (i = (binario.Length) - 1; i >= 0; i--)//101
            {

               // if (binario[i] == '1' || binario[i] == '0') { 
               
                    if (binario[i] == '1')
                    {

                        if (i == (binario.Length) - 1)
                        {
                            numero += 1;

                        }
                        else
                        {
                            numero += Math.Pow(2, exponent);
                        }
                    }
                    exponent++;
                    flag = 1;
              //}

            }

            if(flag==1 && esBinario==true) {
                return Convert.ToString(numero);
            } else {
                return invalid;
            }
           
        }
        /// <summary>
        /// Sobrecarga del metodo DecimalBinario que convierte un numero decimal que fue pasado con formato string a binario 
        /// </summary>
        /// <param name="numero"></param>
        /// <returns></returns>retorna el numero convertido a binario, caso contrario retorna "valor invalido"
        public static string DecimalBinario(string numero)
        {
        double auxNum;
        string invalid="valor invalido";

            if (double.TryParse(numero, out auxNum))
            {
                return DecimalBinario(auxNum);
            }
            else 
        {
            return invalid;
        }
        }
        /// <summary>
        /// Sobrecarga del metodo DecimalBinario que convierte el argumento pasasdo en binario
        /// </summary>
        /// <param name="numero"></param>
        /// <returns></returns>//retorna el numero convertido a binario
        public static string DecimalBinario(double numero)
        {
            string binario = "";

            if (numero == 0)
            {
                binario = "0";
            }
            else if(numero<0)
            {
                numero = (double)numero * (-1);
            }
            while (numero > 0)
            {
                if (numero % 2 == 0)
                {
                    binario = "0" + binario;
                }
                else
                {
                    binario = "1" + binario;
                }
                numero = (int)numero / 2;

            }
            return binario;
        }

        #endregion

        #region OPERADORES  
        /// <summary>
        /// Sobrecarga operador - que resta dos objetos de tipo Numero 
        /// </summary>
        /// <param name="n1"></param>
        /// <param name="n2"></param>
        /// <returns></returns>retorna el resultado de la resta
        public static double operator - (Numero n1, Numero n2)
        {
            double resta;
            resta = n1.numero - n2.numero;

            return resta;
        }
        /// <summary>
        /// Sobrecarga del objeto + que suma dos objetos de tipo Numero
        /// </summary>
        /// <param name="n1"></param>
        /// <param name="n2"></param>
        /// <returns></returns>retorna el resultado de la suma
        public static double operator + (Numero n1, Numero n2)
        {
            double suma;
            suma = n1.numero + n2.numero;

            return suma;
        }
        /// <summary>
        /// Sobrecarga del metodo * que multiplica dos objetos tipo Numero
        /// </summary>
        /// <param name="n1"></param>
        /// <param name="n2"></param>
        /// <returns></returns>retorna el producto de la multiplicacion
        public static double operator * (Numero n1, Numero n2)
        {
            double multiplicacion;
            multiplicacion = n1.numero * n2.numero;

            return multiplicacion;
        }
        /// <summary>
        /// Sobrecarga del metodo / que divide dos objetos tipo Numero
        /// </summary>
        /// <param name="n1"></param>
        /// <param name="n2"></param>
        /// <returns></returns>retorana el cociente de la division caso contrario retorna double.MinValue 
        public static double operator / (Numero n1, Numero n2)
        {
            double division = double.MinValue;

            if(n2.numero!=0) {

                division = n1.numero / n2.numero;
            }
            
            return division;
        }
        #endregion

    }



}
