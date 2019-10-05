#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief Indica que todas las posiciones en el array estan libres,
 *         esta funcion pone el flag (isEmpty) en LIBRE en todas las
 *         posiciones del array.
 * \param lista Employee[] referencia al array de empleados
 * \param len int tamaño del array
 * \return int retorna (-1) si da error [Tamanio invalido o estructura NULL] - (0) si esta bien
 */
int initEmployees(Employee[],int);

/** \brief Busca un lugar libre en un array de empleados
 *
 * \param Employee[]
 * \param int
 * \return int si se encontro retorna el indice del lugar libre o -1 si no hay mas lugar
 *
 */
int buscarLibre(Employee[],int);

/** \brief busca un empleado recibiendo como parametro su id y retorna su posicion en el array
 *
 * \param list Employee[]
 * \param len int
 * \param id int
 * \return int retorna el indice de la posicion en el array del empleado o (-1) si [Tamanio invalido o estructura NULL  o empleado no encontrado]
 *
 */
int findEmployeeById(Employee[],int,int);

/** \brief Busca el id mayor en un array
 *
 * \param lista[] Employee
 * \param tam int
 * \return int si se encontro retorna el id mayor encontrado - Si no se encontro retorna -1
 *
 */
int buscarIdMayor(Employee lista[],int tam);

/** \brief Genera un id automatico en base a los id de los empleados
 *
 * \param empleados[] Employee
 * \param tam int
 * \return int retorna el id generado o retorna un 1
 *
 */
int autoId(Employee empleados[],int tam);

/** \brief Permite cargar un empleado en el array de empleados
 *
 * \param Employee[]
 * \param int
 * \return int retorna un 0 si se ha cargado con exito o retorna un -1 si no se ha podido cargar [estructura nula] o un 1 si esta lleno  el array
 *
 */
int cargarEmpleado(Employee[],int);

/** \brief Agrega en una existente lista de empleados los valores recibidos como parametros en la primer posicion libre
 * \param lista Employee[]
 * \param len int
 * \param id int*
 * \param name char[]
 * \param lastName char[]
 * \param salary float*
 * \param sector int*
 * \return int retorna (-1) si da error [Tamanio invalido o estructura NULL o no hay espacio libre] - (0) si esta bien
 */
int addEmployees(Employee[],int,int*,char[],char[],float*,int*);

/** \brief Modifica los datos de un empleado y da la opcion de elegir que dato modificar
 *
 * \param Employee[]
 * \param int
 * \return int retorna 0 si se ha modifica con exito o -1 si hubo un error
 *
 */
int modificarEmpleado(Employee[],int);

/** \brief Elimina un empleado por id (pone isEmpty en LIBRE)
 * \param listEmployee[]
 * \param len int
 * \param id int
 * \return int retorna(-1) si es error[Tamanio invalido o estructura NULL o si no encontro al empleado]
 */
int removeEmployee(Employee[],int,int);

/** \brief permite ingresar un id de empleado para eliminar
 * \param lista[] Employee
 * \param tam int
 * \return int devuelve 0 si se elimino el empleado  o -1 si no se ha encontrado el empleado o 1 si el usuario cancelo
 */
int eliminarEmpleadoPorId(Employee lista[],int tam);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente (0) o descendente (1)
 * \param list Employee[]
 * \param len int
 * \param order int [1] indica descendente - [0] indica ascendente
 * \return int retorna (-1) si error [Invalido tamanio o estructura NULL ]  . (0) si esta bien
 */
int sortEmployees(Employee[],int,int);

/** \brief Imprime el contenido del array de empleados de forma encolumnada
 * \param list Employee[]
 * \param lenght int
 * \return int retorna -1 si no hay para mostrar - 0 si se pudo
 */
int printEmployees(Employee[],int);

/** \brief muestra los datos de un solo empleado
 * \param lista Employee
 * \return void
 */
void mostrarUnEmpleado(Employee lista);

/** \brief muestra un menu para saber de que manera se desea ordenar los empleados
 * \param Employee[]
 * \param int
 * \return void
 */
void menuListarOrdenar(Employee[],int);

/** \brief ordena los el array de empleados por nombre y sector de manera descendente
 *
 * \param lista[] Employee
 * \param tam int
 * \return int retorna 0 si se pudo ordenar o -1 si no hay nada que ordenar
 *
 */
int ordernarDescendentePorNombreYsector(Employee lista[],int tam);

/** \brief ordena los el array de empleados por nombre y sector de manera ascendente
 *
 * \param lista[] Employee
 * \param tam int
 * \return int retorna 0 si se pudo ordenar -1 si no hay nada que ordenar
 *
 */
int ordernarAscendentePorNombreYsector(Employee lista[],int tam);

/** \brief Calcula cuantos empleados superan el promedio de sueldo y los imprime en pantalla
 *
 * \param Employee[]
 * \param int
 * \return int retorna 0 si se pudo realisar la operacion o -1 si no se ha podido realisar
 */
int cuantosSuperanPromedio(Employee[],int);

/** \brief Calcula el salario promedio de los empleados , retorna el resultado y los imprime en pantalla
 *
 * \param Employee[]
 * \param int
 * \return float retorna el salario promedio o -1 si ha habido un error
 *
 */
float salarioPromedio(Employee[],int);

/** \brief Calcula el salario total de los empleados, retorna el resultado y los imprime en pantalla
 *
 * \param Employee[]
 * \param int
 * \return float retorna el salario total o -1 si no se hiso la operacion
 *
 */
float salarioTotal(Employee[],int);








