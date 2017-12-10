/**
  * @file fechahistorica.h
  * @brief Fichero cabecera de la clase FechaHistorica
  *
  */

#ifndef _FECHAHISTORICA_
#define _FECHAHISTORICA_

#include <utility>
#include <set>
#include <string>

/**
  *  @brief Clase FechaHistorica
  *
  * Un objeto @e fecha de la clase @c FechaHistorica es el conjunto formado
  * por un año y una serie de acontecimientos ocurridos en dicho año.
  * Dichos acontecimientos se guardan en un @c Set de strings
  * Los años negativos se consideran a.C.
  *
  * @author Patricia Cordoba Hidalgo
  * @author David Cabezas Berrido
  * @date Diciembre 2017
  */

class FechaHistorica{

private:
/**
  * @page repConjunto Representativo de la clase FechaHistorica
  *
  */
  std::pair<int, std::set<std::string> > pareja; /**< pair que almacena el año y el conjunto de eventos ocurridos en éste*/

public:

  /**
    * @brief iterador que recorre los acontecimientos de una @c FechaHistorica
    */
 typedef typename std::set<std::string>::iterator iterator;

 /**
   * @brief iterador que recorre los acontecimientos de una @c FechaHistorica de
   * manera que no altera su contenido
   */
 typedef typename std::set<std::string>::const_iterator const_iterator;

 /**
   * @return devuelve un iterador al principio del objeto
   */
 iterator begin();

 /**
   * @return devuelve un iterador al principio del objeto sin alterar el
   * contenido de éste
   */
 const_iterator begin() const;

 /**
   * @return devuelve un iterador al final del objeto
   */
 iterator end();

 /**
   * @return devuelve un iterador al final del objeto sin alterar el
   * contenido de éste
   */
 const_iterator end() const;

/**
  * @brief Constructor por defecto de la clase. Crea la @c FechaHistorica con
  * @c Set vacio y cuyo año es cero
  */
  FechaHistorica();

/**
  * @brief Constructor de la clase
  * @param n año de la @c FechaHistorica a construir
  * @return Crea una @c FechaHistorica cuyo año es n
  */
  FechaHistorica(int n);

/**
  * @brief Constructor copia de la clase.
  * @param original @c FechaHistorica a copiar
  */
  FechaHistorica(const FechaHistorica &original);

/**
  * @brief Vacía el @c Set
  */
  void destruir();

/**
  * @brief Sobrecarga del operador =
  * @param original @c FechaHistorica que se asigna al objeto implicito
  */
  FechaHistorica& operator=(const FechaHistorica &original);

/**
  * @brief nhechos
  * @return Devuelve el número de eventos guardados el @c Set
  */
  int nhechos() const;

/**
  * @brief Año
  * @return Devuelve el año de la @c FechaHistorica
  */
  int& year();

/**
  * @brief Año
  * @return Devuelve el año de la @c FechaHistorica en modo constante
  */
  const int year() const;

/**
  * @brief Añade un evento al @c Set
  * @param h string con el evento a añadir
  */
  void add(std::string h);

  /**
    * @brief Comprueba si el @c Set de eventos está vacío
    * @return true si está vacío, false en caso contrario
    */
  bool empty();

/**
  * @brief Sobrecarga del operador +=
  * @param nuevo FechaHistorica cuyos hechos quieres añadir al objeto implicito
  * siempre que no se encuentren ya en éste
  * @pre El anio de ambos objetos debe coincidir
  */
  FechaHistorica& operator+=(const FechaHistorica &nuevo);
};

/**
  * @brief Sobrecarga del operador <<
  * @param flujo Flujo de salida
  * @param fecha @c FechaHistorica que se quiere escribir
  */
  std::ostream& operator<<(std::ostream &flujo, const FechaHistorica &fecha);

/**
  * @brief Sobrecarga del operador >>
  * @param flujo Flujo de entrada
  * @param fecha @c FechaHistorica que se quiere leer
  */
  std::istream& operator>>(std::istream &flujo, FechaHistorica &fecha);

#endif
