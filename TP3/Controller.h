
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


int controller_addEmployee(LinkedList* pArrayListEmployee);


int controller_editEmployee(LinkedList* pArrayListEmployee);

int controller_removeEmployee(LinkedList* pArrayListEmployee);


int controller_ListEmployee(LinkedList* pArrayListEmployee);


int controller_sortEmployee(LinkedList* pArrayListEmployee);


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief genera un id a partir del siguiente mayor id
 *
 * \param pArrayListEmployee LinkedList*
 * \param inicio int
 * \return int retorna el inicio recibido como id o el siguiente del mayor id
 *
 */
int autoId(LinkedList* pArrayListEmployee,int inicio);

/** \brief busca el mayor id
 *
 * \param pArrayListEmployee LinkedList*
 * \return -1 si no encontro o el numero mayor si se encontro
 *
 */
int buscarIdMayor(LinkedList* pArrayListEmployee);

/** \brief busca un empleado por id
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int int el numero si lo encontro  o -1 si no lo encontro
 *
 */
int BuscarEmpleadoPorId(LinkedList* pArrayListEmployee,int id);

/** \brief menu para modificar un empleado segun el dato
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int 0 si no se modifico o 1 si se modifico
 *
 */
int menuModificarEmpleado(LinkedList* pArrayListEmployee,int index);

