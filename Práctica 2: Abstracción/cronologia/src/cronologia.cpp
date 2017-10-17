#include <iostream>
#include <sstream>
#include <string>
#include "cronologia.h"
#include "fechahistorica.h"
#include "vectordinamico.h"

using namespace std;

Cronologia::Cronologia():fechas(){}

Cronologia::Cronologia(const Cronologia &original){

  fechas.resize(original.fechas.used());

  for(int i = 0; i < original.fechas.used(); i++)
    fechas[i] = original.fechas[i];
}

Cronologia& Cronologia::operator=(const Cronologia &original){

  if(&original != this) {

    fechas.resize(original.fechas.used());

    for(int i = 0; i < original.fechas.used(); i++)
      fechas[i] = original.fechas[i];
  }
  
  return *this;
}

void Cronologia::add(const FechaHistorica &fecha){

	/*if(fechas.empty())
    fechas.aniade(fecha);

    else{*/
	  
	  int i = 0;
	  cout << "UtilizadosS" <<fechas.used() << endl;
	  while(i < fechas.used()){
		  if(fechas[i].year() < fecha.year()){
			  cout << "i vale " << i << endl;
			  i++;
		  }
	  }

	  if(fechas[i].year() == fecha.year()){
		  cout << "igualdad " << endl;
		  fechas[i] += fecha;
	  }
	  else if(fecha.year() < fechas[i].year()){
		  cout << "inserta" << endl;
		  fechas.insertar(i,fecha);
	  }
	  else{
		  fechas.aniade(fecha);
		  cout << "al final" << endl;
	  }
		  //}
}

int Cronologia::used() const{
	return fechas.used();
}

Cronologia& Cronologia::operator+=(const Cronologia &crono){

  for(int i = 0; i < crono.fechas.used(); i++)
    add(crono[i]);

  return *this;
}

FechaHistorica& Cronologia::operator[](int i){
	return fechas[i];
}

const FechaHistorica& Cronologia::operator[](int i) const{
	return fechas[i];
}

ostream& operator<<(ostream &flujo, const Cronologia &crono){

  for(int i = 0; i < crono.used(); i++){
    flujo << crono[i] << "\n";
  }

  return flujo;
}

istream& operator>>(istream &flujo, Cronologia &crono){

  FechaHistorica aux;

  string s;
  
  while(!flujo.eof()){
	  
    getline(flujo, s, '\n');
    istringstream ss(s);
    ss >> aux;
    crono.add(aux);
  }
  return flujo;
}



