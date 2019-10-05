#define LIBRE 0
#define OCUPADO 1

/** \brief Solicita un texto al usuario y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \param input[] char Donde se cargara el texto ingresado
 * \return void
 */
void getString(char message[],char input[]);

/** \brief Solicita al usuario un numero y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \return int Devuelve el numero entero ingresado
 */
int getInt(char message[]);

/** \brief Solicita al usuario un numero flotante y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \return float Devuelve el numero flotante ingresado
 */
float getFloat(char message[]);

/** \brief Solicita al un caracter y lo devuelve
 * \param message[] char El mensaje a ser mostrado
 * \return char Devuelve el caracter ingresado
 */
char getChar(char message[]);

/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar);

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 0 si es n�merico y -1 si no lo es
 */
int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 0 si es n�merico y -1 si no lo es
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo ' ' y letras y -1 si no lo es
 */
int esSoloLetras(char str[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde numero minimo
 * \param hiLimit hasta numero maximo
 * \return devuelve 0 si es numerico y -1 si el numero no es valido
 */
int getIntValid(int* input,char message[],char eMessage[],int lowLimit,int hiLimit);

/** \brief
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde numero minimo
 * \param hiLimit hasta numero maximo
 * \return devuelve 0 si es flotante y -1 si no lo es
 */
int getFloatValid(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/** \brief
 * \brief Solicita un caracter al usuario y lo valida
 * \param *input donde se cargara el caracter
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde caracter minimo
 * \param hiLimit hasta caracter maximo
 * \return devuelve 0 si es un caracter y -1 si si no lo es
 */
int getCharValid(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

/** \brief
 * \brief Solicita un texto entero al usuario y lo valida
 * \param *input donde se cargara el texto
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde texto minimo
 * \param hiLimit hasta numero texto
 * \return devuelve 0 si es un texto y -1 si no lo es
 */
int getStringLetras(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief
 * \brief Solicita un texto con espacio al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde texto minimo
 * \param hiLimit hasta texto maximo
 * \return devuelve 0 si es texto y -1 si no lo es
 */
int getStringLetrasEspacio(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief
 * \brief Solicita una cadema de numeros enteros al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde numero minimo
 * \param hiLimit hasta numero maximo
 * \return devuelve 0 si es numerico y -1 si no es valido
 */
int getStringNumeros(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief
 * \brief Solicita una cadena de numeros flotantes al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde numero minimo
 * \param hiLimit hasta numero maximo
 * \return devuelve 0 si es numero flotante y -1 si no lo es
 */
int getStringFlotantes(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief Solicita al usuario ingresar una confirmacion S o N
 *
 * \return int devuelve 0 si es N y 1 si es S
 *
 */
int confirm();

/**
 * \brief Verifica si el valor recibido contiene solo letras con espacio
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo ' ' y letras y -1 si no lo es
 */
int esSoloLetrasEspacio(char str[]);



































