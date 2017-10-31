/**
  * @file vectordinamico.h
  * @brief Fichero cabecera del TDA VectorDinamico
  * 
  */

#ifndef _VECTORDINAMICO_
#define _VECTORDINAMICO_

/**
  * @brief TDA VectorDinamico
  * 
  * La clase @c VectorDinamico representa una estructura de datos con @e templates,
  * esto permite montar sobre ella otro TDA y evitar redundancia de código.
  * Esta estructura permite acceder a la posiciones en un tiempo reducido,
  * sacrificando eficiencia a la hora de insertar. Permite redimensionar el
  * vector a medida que se añaden o eliminan datos. Consta de un vector de
  * datos y dos enteros que indican el número de posiciones reservadas y utilizadas.
  *
  * @author Patricia Córdoba Hidalgo
  * @author David Cabezas Berrido
  * @date Octubre 2017
  */
 
template <class T>
class VectorDinamico{

 private:
/**
  * @page repConjunto Representativo del TDA
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante de la representación es: 
  * 0 <= utilizados <= reservados
  */
  
  int utilizados;  /**< posiciones utilizadas */
  int reservados;  /**< posiciones reservadas */
  T *datos;  /**< datos */

 public:

/**
  * @brief Constructor por defecto de la clase. Crea un vector vacío
  */
  VectorDinamico();

/**
  * @brief Constructor. Reserva @e n elementos
  * @param n número de elementos a reservar
  * @pre n >= 0
  */
  VectorDinamico(int n);

/**
  * @brief Operador de asignación de la clase
  * @param original @c VectorDinamico a copiar
  * @return el propio objeto, @b *this
  */
  VectorDinamico& operator=(const VectorDinamico &original);

/**
  * @brief Constructor de copias de la clase
  * @param original @c VectorDinamico a copiar
  */
  VectorDinamico(const VectorDinamico &original);

/**
  * @brief Destructor de la clase. Llama al método destruir
  *
  */
  ~VectorDinamico();

/**
  * @brief Libera la memoria dinámica reservada y pone a 0 todos los datos
  *
  */  
  void destruir();

/**
  * @brief Devuelve el número de datos reservados
  *
  */  
  int reserved() const;

/**
  * @brief Devuelve el número de datos utilizados
  *
  */  
  int used() const;
  
/**
  * @brief Devuelve la referenca al número de datos reservados
  *
  */  
  int& used();

 /**
  * @brief Devuelve la referenca al dato de la posición @e i
  * @param i posición a modificar
  * @pre utilizados > i >= 0
  */   
  T& operator[](int i);

/**
  * @brief Devuelve el dato de la posición @e i
  * @param i posición a consultar
  * @pre utilizados > i >= 0
  */   
  const T& operator[](int i) const;

/**
  * @brief Inserta el dato @e elemento en la posición @e i
  * @param i posición en la que se inserta el dato
  * @param elemento a insertar
  */     
  void insertar(int i, T elemento);

/**
  * @brief Añade el dato @e elemento al final del vector
  * @param elemento a insertar
  */     
  void aniade(T elemento);

/**
  * @brief Elimina el elemento de la posición @e i
  * @param i posición del elemento a borrar
  * @pre utilizados > i >= 0
  */     
  void elimina(int i);

/**
  * @brief Reserva @e n elementos (si @e n < @e utilizados, se eliminan el resto de elementos)
  * @param n número de elementos a reservar
  * @pre n >= 0
  */     
  void resize(int n);

/**
  * @brief Dice si el vector está vacío
  * @return @b true si está vacío, @b false si no lo está
  */     
  bool empty();
  
};

#include "../src/vectordinamico.cpp"

#endif
  
  
