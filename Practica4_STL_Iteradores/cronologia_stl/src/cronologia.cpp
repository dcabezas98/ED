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

int Cronologia::searchYear(int y) const{

  int right=used(), left=0, center;
  bool found=false;
  int pos=-1;

  while(left < right && !found){
    center=(left + right)/2;

    if(y == fechas[center].year()){
      pos = center;
      found = true;
    } else if (y < fechas[center].year()){
      right = center-1;
    } else {
      left = center+1;
    }
  }

  return pos;
}

Cronologia Cronologia::subcronologia(int a1, int a2) const{
  int pos1=0, pos2=fechas.used()-1;

  while(pos1 < fechas.used() && fechas[pos1].year() < a1){
    pos1++;
  }

  while(pos2 >= 0 && fechas[pos2].year() > a2){
    pos2--;
  }

  Cronologia crono;

  int used = pos2-pos1+1;

  for(int i=0; i < used; i++){
    crono.add(fechas[pos1+i]);
  }

  return crono;
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
