#include <iostream>
#include <sstream>
#include <string>
#include "cronologia.h"
#include "fechahistorica.h"
#include "vectordinamico.h"

using namespace std;

Cronologia::Cronologia():fechas(){}

Cronologia::Cronologia(const Cronologia &original){

  fechas.resize(original.fechas.reserved());

  fechas.used() = original.fechas.used(); 
  
  for(int i = 0; i < original.fechas.used(); i++){
    fechas[i] = original.fechas[i];
  }
}

void Cronologia::destruir(){
  fechas.destruir();
}  

Cronologia& Cronologia::operator=(const Cronologia &original){

  if(&original != this) {

    destruir();

    fechas.resize(original.fechas.reserved());

    fechas.used() = original.fechas.used();

    for(int i = 0; i < original.fechas.used(); i++)
      fechas[i] = original.fechas[i];
  }
  
  return *this;
}

void Cronologia::add(const FechaHistorica &fecha){

	  
  int i = 0;
 
  while(i < fechas.used() && fecha.year() > fechas[i].year()){
    i++;
  }

  if( i == fechas.used()){
    fechas.aniade(fecha);
  }
	  
  else if(fechas[i].year() == fecha.year()){
    fechas[i] += fecha;
  }
	  
  else {
    fechas.insertar(i,fecha);
  }		  
}

int Cronologia::used() const{
  return fechas.used();
}

Cronologia& Cronologia::operator+=(const Cronologia &crono){

  for(int i = 0; i < crono.fechas.used(); i++){
    add(crono[i]);
  }

  /*  cout << endl << fechas[0].year() << endl << endl;
  cout << endl << fechas[0][0] << endl << endl;
  cout << endl << fechas[0][1] << endl << endl;
  cout << endl << fechas[0][2] << endl << endl;
  */
  cout << endl << fechas[0] << endl  << endl;
  return *this;
}

FechaHistorica& Cronologia::operator[](int i){
  return fechas[i];
}

const FechaHistorica& Cronologia::operator[](int i) const{
  return fechas[i];
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
