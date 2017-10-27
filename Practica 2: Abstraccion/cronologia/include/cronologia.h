/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include "fechahistorica.h"
#include "vectordinamico.h"

/**
  *  @brief T.D.A Cronologia 
  *
  * Un objeto @e crono del tipo de dato abstracto @c Cronologia está formado por
  * una serie de años con acontecimientos ocurridos en cada uno de estos.
  * Dichos datos se guardan en el @c VectorDinamico de @c FechaHistorica @e fechas.
  *
  * @author Patricia Cordoba Hidalgo
  * @author David Cabezas Berrido
  * @date Octubre 2017
  */

class Cronologia{

 private:
/**
  * @page repConjunto Representativo de la clase Cronologia
  *
  */
  VectorDinamico<FechaHistorica> fechas; /**< vector de fechas */
  
 public:

/**
  * @brief Constructor por defecto de la clase. Crea la @c Cronologia con
  * @c VectorDinamico vacio usando el constructor vacio de fechas.
  */
  Cronologia();

/**
  * @brief Constructor copia de la clase.
  * @param original @c Cronologia a copiar 
  */
  Cronologia(const Cronologia &original);

/**
  * @brief Libera la memoria del @c VectorDinamico fechas
  */
  void destruir();

/**
  * @brief Sobrecarga del operador =
  * @param original @c Cronologia que se asigna al objeto implicito
  */
  Cronologia& operator=(const Cronologia &original);

/**
  * @brief used nhechos
  * @return Devuelve el número de elementos guardados en el @c VectorDinamico @c fechas.
  */
  int used() const;

/**
  * @brief Añade la @c FechaHistorica @e fecha a la cronología
  * @param fecha @c FechaHistorica a añadir
  */
  void add(const FechaHistorica &fecha);

/**
  * @brief Sobrecarga del operador []
  * @param i posición del vector a modificar
  * @return FechaHistorica guardada en la posición i
  * @pre i debe estar entre 0 y nhechos
  */
  FechaHistorica& operator[](int i);

/**
  * @brief Sobrecarga del operador []
  * @param i posición del vector a consultar
  * @return FechaHistorica guardada en la posición i
  * @pre i debe estar entre 0 y nhechos
  */
  const FechaHistorica& operator[](int i) const;

/**
  * @brief Sobrecarga del operador +=
  * @param crono Cronologia cuyas fechas quieres añadir al objeto implicito
  * siempre que no se encuentren ya en éste. Si se encuentra la fecha, añade los
  * eventos que falten en dicho año.
  */
  Cronologia& operator+=(const Cronologia &crono);

/**
  * @brief Busca la posición donde se encuentra un año en el vector
  * @param y año que se quiere buscar en la  @c Cronologia
  * @return Posición donde se encuentra dicho año en la @c Cronologia
  * Si no se encuentra, devuelve la posición -1.
  */
  int searchYear(int y) const;

/**
  * @brief Crea una subcronología con las fechas entre los años a1 y a2
  * @param a1 año donde comienza la @c Cronologia
  * @param a2 año donde finaliza la @c Cronologia
  * @return Subcronologia que comienza en @e a1 y termina en @e a2.
  * @pre a1 <= a2
  */
  Cronologia subcronologia(int a1, int a2) const;

/**
  * @brief Crea una subcronología con las fechas que contengan el string s.
  * @param s string que debe contener la @c Cronologia
  * @return Subcronologia con las fechas que contienen el string s.
  */
  Cronologia subcronologia(string s) const;
};

/**
  * @brief Sobrecarga del operador <<
  * @param flujo Flujo de salida
  * @param crono @c Cronologia que se quiere escribir
  */
  ostream& operator<<(ostream &flujo, const Cronologia &crono);

/**
  * @brief Sobrecarga del operador >>
  * @param flujo Flujo de entrada
  * @param crono @c Cronologia que se quiere leer
  */
  istream& operator>>(istream &flujo, Cronologia &crono);

#endif
