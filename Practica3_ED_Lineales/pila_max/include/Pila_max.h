/**
  * @file Pila_max.h
  * @brief Fichero para compilar la PilaMax o con vectores dinamicos o con colas.
  *
  */

  /**
    * @author Patricia Córdoba Hidalgo
    * @author David Cabezas Berrido
    * @date Octubre 2017
    */
#define CUAL_COMPILA 2
#if CUAL_COMPILA == 1
#include "Pila_max_VD.h"
#else
#include "Pila_max_Cola.h"
#endif
