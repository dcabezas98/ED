#ifndef _FECHAHISTORICA_
#define _FECHAHISTORICA_

#include "vectordinamico.h"

class FechaHistorica{

 private:

  int anio;
  VectorDinamico<std::string> hechos;

 public:

  FechaHistorica();

  FechaHistorica(int n);

  FechaHistorica(const FechaHistorica &original); 

  FechaHistorica& operator=(const FechaHistorica &original);

  int nhechos();

  int anio();

  void aniade(string h);

  FechaHistorica& operator+=(const FechaHistorica &nuevo);

  friend ostream& operator<<(ostream &flujo, const FechaHistorica &fecha);

  friend istream& operator>>(istream flujo, FechaHistorica &fecha);
};

#endif
