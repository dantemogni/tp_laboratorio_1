
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee*,int);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);
*/
int addEmployee(eEmployee*, int, int, char[],char[],float,int);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee*, int,int);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee*, int, int);

/**\brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee*, int);

void printEmploye(eEmployee);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee*, int, int);

void mainMenu(eEmployee*, int);

/**\brief Obtains the first free space of the array
 *
 * \param list of the employees
 * \return returns the first free index available
 */
int searchFreeEmployees(eEmployee*, int);


/** \brief Allows data entry for the list of employees
 *
 * \param calls the array of employees
 * \param sets the length of the arrays
 * \return void
 *
 */
 void enterEmployee(eEmployee*, int len, int*);


/** \brief Sets a menu for changing employee's data
 *
 * \return int Returns an option selected by the user
 *
 */
int changeMenu();


/** \brief ALlows the modification of data
 *
 * \param eEmployee* calls the array of employees
 * \param int sets the length of the list
 * \return void
 *
 */
void changeEmployee(eEmployee*, int);


/** \brief ALlows deleting data of the list
 *
 * \param eEmployee* calls the array of employees
 * \param int sets the length of the list
 * \return void
 *
 */
void deleteEmployee(eEmployee*, int);
