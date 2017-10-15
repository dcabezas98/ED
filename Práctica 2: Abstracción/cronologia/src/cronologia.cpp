#include <iostream>
#include "cronologia.h"

using namespace std;

Cronologia::Cronologia():fechas(){}

Cronologia::Cronologia(const Cronologia &original){

  fechas.resize(original.fechas.utilizados());

  for(int i = 0; i < original.fechas.utilizados(); i++)
    fechas[i] = original.fechas[i];
}

Cronologia& Cronologia::operator=(const Cronologia &original){

  if(&original != this) {

    fechas.resize(original.fechas.utilizados());

    for(int i = 0; i < original.fechas.utilizados(); i++)
      fechas[i] = original.fechas[i];
  }

  return *this;
}

void Cronologia::add(const FechaHistorica &fecha){

  int i = 0;
  
  while(i < fechas.utilizados && fecha.anio() > fechas[i].anio()){
    i++;
  }

  if(fechas[i].anio() == fecha.anio()){
    fechas[i] += fecha;
  }
  else if(fecha.anio() < fechas[i].anio()){
    fechas.insertar(i,fecha);
  }
  else
    fechas.aniade(fecha);
}

Cronologia& Cronologia::operator+=(const Cronologia &crono){

  for(int i = 0; i < crono.fechas.utilizados(); i++)
    add(crono.fechas[i]);
}

friend ostream& operator<<(ostream &flujo, const Cronologia &crono){

  for(int i = 0; i < fechas.utilizados(); i++){
    flujo << fechas[i] << "\n";
  }
}

friend istream& operator>>(istream &flujo, Cronologia &crono){

  FechaHistorica aux;
  
  while(flujo >> aux){

    add(aux);
  }
}



