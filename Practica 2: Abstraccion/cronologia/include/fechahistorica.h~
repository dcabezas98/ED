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

  int nhechos() const;

  int& year();
  
  const int year() const;

  void aniade(string h);

  string& operator[](int i);
  
  const string& operator[](int i) const;

  FechaHistorica& operator+=(const FechaHistorica &nuevo);
};

  ostream& operator<<(ostream &flujo, const FechaHistorica &fecha);

  istream& operator>>(istream &flujo, FechaHistorica &fecha);

#endif
