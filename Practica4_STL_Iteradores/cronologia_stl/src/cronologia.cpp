#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "cronologia.h"
#include "fechahistorica.h"

using namespace std;

Cronologia::Cronologia():fechas(){}

Cronologia::Cronologia(const Cronologia &original) :fechas(original.fechas){
}

void Cronologia::destruir(){
  fechas.clear();
}

Cronologia& Cronologia::operator=(const Cronologia &original){

  if(&original != this)
    fechas = original.fechas;

  return *this;
}

void Cronologia::add(const FechaHistorica &fecha){
  fechas.insert(pair<int, FechaHistorica>(fecha.year(), fecha));
}

int Cronologia::size() const{
  return fechas.size();
}

Cronologia& Cronologia::operator+=(const Cronologia &crono){

  for(auto it = crono.fechas.cbegin(); it != crono.fechas.cend(); it++){
    add(*it);
  }

  return *this;
}

Cronologia Cronologia::subcronologia(int a1, int a2) const{
}

Cronologia Cronologia::subcronologia(string s) const{

  Cronologia crono;

  for(int i = 0; i < fechas.used(); i++)
    if(fechas[i].contiene(s)) crono.add(fechas[i]);

  return crono;
}

ostream& operator<<(ostream &flujo, const Cronologia &crono){

  for(int i = 0; i < crono.used(); i++){
    flujo << crono[i] << "\n";
  }

  return flujo;
}

istream& operator>>(istream &flujo, Cronologia &crono){

  crono.destruir();

  string s;
  getline(flujo, s, '\n');

  while(flujo.eof() == 0){
    istringstream ss(s);
    FechaHistorica aux;
    ss >> aux;
    crono.add(aux);
    s = "";
    getline(flujo, s, '\n');
  }

  return flujo;
}
