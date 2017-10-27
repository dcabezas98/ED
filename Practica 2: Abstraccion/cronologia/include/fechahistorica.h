/**
  * @file fechahistorica.h
  * @brief Fichero cabecera de la clase FechaHistorica
  *
  */

#ifndef _FECHAHISTORICA_
#define _FECHAHISTORICA_

#include "vectordinamico.h"

/**
  *  @brief Clase FechaHistorica
  *
  * Un objeto @e fecha de la clase @c FechaHistorica es el conjunto formado
  * por un año y una serie de acontecimientos ocurridos en dicho año.  * Dichos acontecimientos se guardan en un @c VectorDinamico de strings
  * Los años negativos se consideran a.C.
  *
  * @author Patricia Cordoba Hidalgo
  * @author David Cabezas Berrido
  * @dato Octubre 2017
  */


class FechaHistorica{

 private:
/**
  * @page repConjunto Representativo de la clase FechaHistorica
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @ e fecha de la clase @c FechaHistorica representa al valor
  *
  * rep.anio#rep.hechos
  */
  int anio;
  VectorDinamico<std::string> hechos;

 public:

/**
  * @brief Constructor por defecto de la clase. Crea la @c FechaHistorica con
  * VectorDinamico vacio y cuyo año es cero
  */
  FechaHistorica();

/**
  * @brief Constructor de la clase
  * @param n año de la @c FechaHistorica a contruir
  * @return Crea una @c FechaHistorica cuyo año es n 
  */
  FechaHistorica(int n);

/**
  * @brief Constructor copia de la clase.
  * @param original.anio año de la @c FechaHistorica a corntruir
  * @param original.hechos eventos ocurridos en dicho año
  */
  FechaHistorica(const FechaHistorica &original);

/**
  * @brief Libera la memoria del @c VectorDinamico hechos vacío
  */
  void destruir();

/**
  * @brief Sobrecarga del operador =
  * @param original @cFechaHistorica que se asigna al objeto implicito
  */
  FechaHistorica& operator=(const FechaHistorica &original);

/**
  * @brief nhechos
  * @return Devuelve el numero de eventos guardados el @c VectorDinamico nhechos 
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
  * @brief Añade un evento al final del @c VectorDinamico hechos
  * @param h string con el evento a añadir
  */
  void aniade(string h);

/**
  * @brief Sobrecarga del operador []
  * @param i posición del vector a modificar
  * @return string guardado en la posición i
  */
  string& operator[](int i);

/**
  * @brief Sobrecarga del operador []
  * @param i posición del vector a consultar
  * @return string guardado en la posición i
  * @pre i debe estar entre 0 y nhechos
  */
  const string& operator[](int i) const;

/**
  * @brief Busca si un string está contenido en alguno del @c VectorDinamico 
  * hechos de @c FechaHistorica
  * @param s string que se quiere buscar en @c FechaHistorica
  * @return @b true si el string se encuentra en hechos o @b false si no
  * @pre i debe estar entre 0 y nhechos
  */
  bool contiene(string s) const;
  
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
  * @param fecha @c FechaHistorica que se quiere imprimir en pantalla
  */
  ostream& operator<<(ostream &flujo, const FechaHistorica &fecha);

/**
  * @brief Sobrecarga del operador >>
  * @param flujo Flujo de entrada
  * @param fecha @c FechaHistorica que se quiere leer
  */
  istream& operator>>(istream &flujo, FechaHistorica &fecha);

#endif
