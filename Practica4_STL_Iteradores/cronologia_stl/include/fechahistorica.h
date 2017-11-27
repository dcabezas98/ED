/**
  * @file fechahistorica.h
  * @brief Fichero cabecera de la clase FechaHistorica
  *
  */

#ifndef _FECHAHISTORICA_
#define _FECHAHISTORICA_

/**
  *  @brief Clase FechaHistorica
  *
  * Un objeto @e fecha de la clase @c FechaHistorica es el conjunto formado
  * por un año y una serie de acontecimientos ocurridos en dicho año.  * Dichos acontecimientos se guardan en un @c Vector***@hsdofmsdaifhPELIGRO***Dinamico de strings
  * Los años negativos se consideran a.C.
  *
  * @author Patricia Cordoba Hidalgo
  * @author David Cabezas Berrido
  * @date Octubre 2017
  */

class FechaHistorica{

private:
/**
  * @page repConjunto Representativo de la clase FechaHistorica
  *
  */
  std::pair<int, std::set<std::string> > pareja;

public:

 typedef typename set<string>::iterator iterator;

 typedef typename set<string>::const_iterator const_iterator;

 iterator begin();

 const_iterator begin() const;

 iterator end();

 const_iterator end() const;

/**
  * @brief Constructor por defecto de la clase. Crea la @c FechaHistorica con
  * @c VectorDinamico vacio y cuyo año es cero
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
  * @brief Libera la memoria del @c VectorDinamico hechos
  */
  void destruir();

/**
  * @brief Sobrecarga del operador =
  * @param original @c FechaHistorica que se asigna al objeto implicito
  */
  FechaHistorica& operator=(const FechaHistorica &original);

/**
  * @brief nhechos
  * @return Devuelve el número de eventos guardados el @c VectorDinamico nhechos
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
  * @brief Busca si un string está contenido en alguno del @c VectorDinamico
  * hechos de @c FechaHistorica
  * @param s string que se quiere buscar en @c FechaHistorica
  * @return @b true si el string se encuentra en hechos o @b false si no
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
  * @param fecha @c FechaHistorica que se quiere escribir
  */
  ostream& operator<<(ostream &flujo, const FechaHistorica &fecha);

/**
  * @brief Sobrecarga del operador >>
  * @param flujo Flujo de entrada
  * @param fecha @c FechaHistorica que se quiere leer
  */
  istream& operator>>(istream &flujo, FechaHistorica &fecha);

#endif
