/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include <map>
#include "fechahistorica.h"

/**
  *  @brief T.D.A Cronologia
  *
  * Un objeto @e crono del tipo de dato abstracto @c Cronologia está formado por
  * una serie de años con acontecimientos ocurridos en cada uno de estos.
  * Dichos datos se guardan en un @c map que relaciona los años con los objetos
  * de la clase @c FechaHistorica
  *
  * Ejemplos de uso:
  * @include pruebacronologia.cpp
  * @include estadisticaEventos.cpp
  * @include filtradoIntervalo.cpp
  * @include filtradoPalabraClave.cpp
  * @include unionCronologias.cpp
  *
  * @author Patricia Cordoba Hidalgo
  * @author David Cabezas Berrido
  * @date Diciembre 2017
  */
class Cronologia{

private:
/**
  * @page repConjunto Representativo de la clase Cronologia
  *
  */
  std::map<int, FechaHistorica> fechas; /**< map que relaciona cada año con una FechaHistorica*/

public:

  /**
    * @brief Iterador para recorrer una @e FechaHistorica
    *
    */
  typedef typename std::map<int, FechaHistorica>::iterator iterator;

  /**
    * @brief Iterador constante para recorrer una @e FechaHistorica
    *
    */
  typedef typename std::map<int, FechaHistorica>::const_iterator const_iterator;

  /**
    * @brief Método begin para el iterador
    * @return iterator a la primera pareja <año, FechaHistorica>
    *
    */
  iterator begin();

  /**
    * @brief Método begin para el iterador constante
    * @return const_iterator a la primera pareja <año, FechaHistorica>
    *
    */
  const_iterator begin() const;

  /**
    * @brief Método end para el iterador
    * @return iterator al final del map
    *
    */
  iterator end();

  /**
    * @brief Método end para el iterador constante
    * @return const_iterator al final del map
    *
    */
  const_iterator end() const;

/**
  * @brief Constructor por defecto de la clase. Crea la @c Cronologia con
  * @c map vacío
  */
  Cronologia();

/**
  * @brief Constructor copia de la clase.
  * @param original @c Cronologia a copiar
  */
  Cronologia(const Cronologia &original);

/**
  * @brief La cronologia queda vacía
  */
  void destruir();

/**
  * @brief Sobrecarga del operador =
  * @param original @c Cronologia que se asigna al objeto implicito
  */
  Cronologia& operator=(const Cronologia &original);

/**
  * @brief Tamaño del @c map fechas
  * @return Devuelve el número de elementos guardados en el @c map @c fechas.
  */
  int size() const;

/**
  * @brief Añade la @c FechaHistorica @e fecha a la cronología
  * @param fecha @c FechaHistorica a añadir
  */
  void add(const FechaHistorica &fecha);

/**
  * @brief Sobrecarga del operador +=
  * @param crono Cronologia cuyas fechas quieres añadir al objeto implicito
  * siempre que no se encuentren ya en éste. Si se encuentra la fecha, añade los
  * eventos que falten en dicho año.
  */
  Cronologia& operator+=(const Cronologia &crono);

/**
  * @brief Crea una subcronología con las fechas entre los años a1 y a2
  * @param a1 año donde comienza la @c Cronologia
  * @param a2 año donde finaliza la @c Cronologia
  * @return Subcronologia resultante
  * @pre a1 <= a2
  */
  Cronologia subcronologia(int a1, int a2) const;

/**
  * @brief Crea una subcronología con los acontecimientos que contengan el string s.
  * @param s string a buscar
  * @return Subcronologia con los acontecimientos que contienen el string s.
  */
  Cronologia subcronologia(std::string s) const;

  /**
    * @brief Devuelve la @c FechaHistorica correspondiente al año a
    * @param a año
    * @return @c FechaHistorica con el año dado como parámetro
    * @pre El año a está en la @c Cronologia
    */
  FechaHistorica getFecha(int a) const;

  /**
    * @brief Imprime estadísticas sobre la @c Cronologia: número años, número de eventos,
    * máximo de eventos en un año y promedio de eventos por año
    *
    */
  void recuento() const;

  /**
    * @brief Averigua si un año está en la @c Cronología
    * @param a año a consultar
    * @return 1 si a pertenece a la @c Cronología y 0 en caso contrario
    */
  bool esta(int a) const;
};

/**
  * @brief Sobrecarga del operador <<
  * @param flujo Flujo de salida
  * @param crono @c Cronologia que se quiere escribir
  */
  std::ostream& operator<<(std::ostream &flujo, const Cronologia &crono);

/**
  * @brief Sobrecarga del operador >>
  * @param flujo Flujo de entrada
  * @param crono @c Cronologia que se quiere leer
  */
  std::istream& operator>>(std::istream &flujo, Cronologia &crono);

#endif
