#include <stdio.h>

/** \brief almacena los datos ingresados
 *
 * \param float es el primer numero (A) ingresado
 * \param float es el segundo numero (B) ingresado
 * \return como es un void, no devuelve nada
 *
 */
void calcular (float numUno, float numDos, int operacion);


/** \brief la funci�n recibe dos valores previamente almacenados en el espacio de memoria y los suma
 *
 * \param float corresponde al primer numero ingresado
 * \param float corresponde al segundo numero ingresado
 * \return float devuelve el resultado de la adici�n
 *
 */
float sumar (float numUno, float numDos);


/** \brief la funci�n recibe dos valores previamente almacenados en las posiciones de memoria y los resta
 *
 * \param float corresponde al primer numero ingresado
 * \param float corresponde al segundo numero ingresado
 * \return float devuelve el resultado de la sustracci�n
 *
 */
float restar (float numUno, float numDos);


/** \brief la funci�n recibe dos valores previamente almacenados en las posiciones de memoria y los divide
 *
 * \param float corresponde al primer numero ingresado
 * \param float corresponde al segundo numero ingresado
 * \return float devuelve el resultado de la divisi�n
 *
 */
float dividir (float numUno, float numDos);


/** \brief la funci�n recibe dos valores previamente almacenados en las posiciones de memoria y los multiplica
 *
 * \param float corresponde al primer numero ingresado
 * \param float corresponde al segundo numero ingresado
 * \return float devuelve el resultado de la multiplicaci�n
 *
 */
float multiplicar (float numUno, float numDos);


/** \brief la funci�n recibe un valor previamente almacenados en una posici�n de memoria y lo factorea
 *
 * \param float corresponde al primer numero ingresado
 * \return float devuelve el resultado del factoreo del primer numero
 *
 */
float factorialUno (float numUno);


/** \brief la funci�n recibe un valor previamente almacenados en una posici�n de memoria y lo factorea
 *
 * \param float corresponde al segundo numero ingresado
 * \return float devuelve el resultado del factoreo del segundo numero
 *
 */
float factorialDos (float numDos);


/** \brief se encarga de solicitar y almacenar el ingreso del primer numero, el segundo y qu� operaci�n se desea realizar
 *
 * \return int devuelve los datos obtenidos que luego se utilizaran en las otras funciones de la calculadora
 *
 */
int pedirDato();

