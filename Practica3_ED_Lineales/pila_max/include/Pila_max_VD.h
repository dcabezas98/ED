/**
 * @file pila.h
 * @brief Fichero cabecera del TDA Pila
 *
 * Gestiona una secuencia de elementos con facilidades para la inserción y
 * borrado de elementos en un extremo
 *
 */

#ifndef __PilaMax_VD__
#define __PilaMax_VD__

#include <cassert>
#include <iostream>
#include <vectordinamico.h>

/**
 *  @brief T.D.A. Pila
 *
 *
 * Una instancia @e v del tipo de datos abstracto Pila sobre el tipo @c T es
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In,
 * First Out). En una pila, las operaciones de inserción y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila de longitud
 * @e n la denotamos

 * - [a1,a2,a3,..,an>

 * donde @e ai es el elemento de la posición i-ésima.

 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es decir,
 * a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre éste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila está vacía.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el número de
 * elementos de la Pila.
 *
 * @author J.Fdez-Valdivia.
 * @date Octubre 2011
 */

struct Pareja{
  int valor=0;
  int max=0;
};

ostream& operator << (ostream &flujo, const Pareja &p);

class PilaMax{
 private:

  VectorDinamico<Pareja> elementos;

 public:
  // ---------------  Constructores ----------------
  /**
   * @brief Constructor por defecto
   */
 PilaMax():elementos(){}
  /**
   * @brief Constructor de copias
   * @param otra La pila de la que se hará la copia.
   */
  PilaMax(const PilaMax & otra);

  // --------------- Otras funciones ---------------
  /**
   * @brief Operador de asignación
   * @param otra La pila que se va a asignar.
   */
  PilaMax& operator= (const PilaMax& otra);

  /**
   * @brief Comprueba si la pila está vacía
   */
  bool vacia() const;
  /**
   * @brief Devuelve el elemento del tope de la pila
   */
  Pareja& tope ();
  /**
   * @brief Devuelve el elemento del tope de una pila constante
   */
  const Pareja& tope () const;
  /**
   * @brief Añade un elemento "encima" del tope de la pila
   * @param elem Elemento que se va a añadir.
   */
  void poner(const int &n);
  /**
   * @brief Quita el elemento del tope de la pila
   */
  void quitar();

  /**
   * @brief Devuelve el número de elementos de la pila
   */
  int nelementos() const;

  int maximo() const;
};

#endif // __PilaMax_VD__
