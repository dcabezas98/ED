#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <map>
#include "cronologia.h"
#include "fechahistorica.h"

using namespace std;

Cronologia::iterator Cronologia::begin(){
  return fechas.begin();
}

Cronologia::const_iterator Cronologia::begin() const{
  return fechas.cbegin();
}

Cronologia::iterator Cronologia::end(){
  return fechas.end();
}

Cronologia::const_iterator Cronologia::end() const{
  return fechas.cend();
}

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

  if(!esta(fecha.year()))
    fechas.insert(pair<int, FechaHistorica>(fecha.year(), fecha));

  else
    fechas.find(fecha.year())->second += (fecha);
}

int Cronologia::size() const{
  return fechas.size();
}

Cronologia& Cronologia::operator+=(const Cronologia &crono){

  for(auto it = crono.fechas.cbegin(); it != crono.fechas.cend(); it++){
    add(it->second);
  }

  return *this;
}

bool Cronologia::esta(int a) const {
  return fechas.find(a) != fechas.end();
}

FechaHistorica Cronologia::getFecha(int a) const {

  assert(this->esta(a));

  FechaHistorica f = fechas.find(a)->second;

  return f;
}

Cronologia Cronologia::subcronologia(int a1, int a2) const{
  Cronologia crono;

  for(int i= a1; i<=a2; i++){
    if(fechas.find(i) != fechas.end()){
      crono.add(fechas.find(i)->second);
    }
  }
  return crono;
}

Cronologia Cronologia::subcronologia(string s) const{

  Cronologia crono;
  FechaHistorica fecha;

  for(auto itc=fechas.begin(); itc != fechas.end(); itc++){
    for(auto itf=itc->second.begin(); itf != itc->second.end(); itf++){
      if((*itf).find(s) != string::npos){
        fecha.add(*itf);
      }
    }
    if(!fecha.empty()){
      fecha.year()=itc->second.year();
      crono.add(fecha);
      fecha.destruir();
    }
  }
  return crono;
}

void Cronologia::recuento() const{

  int yearnum = 0, eventnum = 0, maxevent = 0, yearmax = -1;

  for(auto itc = fechas.begin(); itc != fechas.end(); itc++){

    yearnum++; // No se repiten años
    eventnum += itc->second.nhechos();

    if(itc->second.nhechos() > maxevent){
      maxevent = itc->second.nhechos();
      yearmax = itc->second.year();
    }
  }

  cout << "Esta cronología tiene:\n";
  cout << yearnum << " años\n";
  cout << eventnum << " eventos\n";
  cout << maxevent << " eventos en el año con más eventos: " << yearmax << "\n";
  cout << "Un promedio de " << (float) eventnum/yearnum << " eventos por año\n";
}

ostream& operator<<(ostream &flujo, const Cronologia &crono){

  for(auto it = crono.begin(); it != crono.end(); it ++){
    flujo << it->second << "\n";
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
