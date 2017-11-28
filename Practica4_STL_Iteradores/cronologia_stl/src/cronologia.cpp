#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "cronologia.h"
#include "fechahistorica.h"

using namespace std;

iterator Cronologia::begin(){
  return fechas.begin();
}

const_iterator Cronologia::begin() const{
  return fechas.cbegin();
}

iterator Cronologia::end(){
  return fechas.end();
}

const_iterator Cronologia::end() const{
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
  Cronologia crono;

  for(int i= a1; i<=a2; i++){
    if(fechas.find(i) != fechas.end()){
      crono.add(fechas[i]);
    }
  }
  return crono;
}

Cronologia Cronologia::subcronologia(string s) const{

  Cronologia crono;
  FechaHistorica fecha;

  for(auto itc=fechas.begin(); itc != fechas.end(); itc++){
    for(auto itf=(*itc).begin(); itf != (*itc).end(); itf++){
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

ostream& operator<<(ostream &flujo, const Cronologia &crono){

  for(int i = 0; i < crono.used(); i++){
    flujo << crono[i] << "\n";
  }

  return flujo;
}

void ImprimeCronologia (const Cronologia &c, ostream &os){
   Cronologia::const_iterator it;
   for (it=c.begin(); it!=c.end();++it){
       os<<(*it).first<<"#";          //año esta en el key del map
       EventoHistorico::const_iterator it_ev;
       for (it_ev=(*it).second.begin(); it_ev!=(*it).second.end();++it_ev)
        os<<(*it_ev)<<"#";
   }
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
