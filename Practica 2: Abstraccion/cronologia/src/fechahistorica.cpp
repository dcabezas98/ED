#include <iostream>
#include <string>
#include "fechahistorica.h"
#include "vectordinamico.h"

using namespace std;

FechaHistorica::FechaHistorica() {
  anio=0; 
}

FechaHistorica::FechaHistorica(int n){
  anio=n;
}

FechaHistorica::FechaHistorica(const FechaHistorica &original) {
  hechos=original.hechos;
  anio=original.anio;
}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &original){

	if(&original != this){

		anio = original.anio;

		hechos = original.hechos;
	}
	return *this;
}

int FechaHistorica::nhechos() const {
  return hechos.used();
}

const int FechaHistorica::year() const {
  return anio;
}

int& FechaHistorica::year(){
	return anio;
}

void FechaHistorica::aniade(string h) {
  hechos.aniade(h);
}

string& FechaHistorica::operator[](int i){
	return hechos[i];
}

const string& FechaHistorica::operator[](int i) const{
	return hechos[i];
}

FechaHistorica& FechaHistorica::operator+=(const FechaHistorica &nuevo){

	if(&nuevo != this) {
		assert(anio == nuevo.anio);

		bool encontrado = false;
  
		for(int i=0; i<nuevo.nhechos(); i++){
			for(int j=0; j<nhechos() && !encontrado; j++) {
				if(nuevo.hechos[i]==hechos[j])
					encontrado = true;
			}
    
			if(!encontrado)
				hechos.aniade(nuevo.hechos[i]);
		}
	}
	return *this;
}

ostream& operator<<(ostream &flujo, const FechaHistorica &fecha){
  flujo<<fecha.year();

  for (int i=0; i<fecha.nhechos(); i++){
    flujo<<"#";
    flujo<<fecha[i];
  }

  flujo<<"\n";

  return flujo;
}

/*
istream& operator>>(istream flujo, FechaHistorica &fecha){

  string s;
  char c;

  flujo >> c;

  while(c != '#')
    s = s + c;

  fecha.year() = stoi(s);
  
  flujo.get(c);

  while(c != "\n"){
    while(c != '#'){
      
      s = s + c;
      flujo.get(c);
    }

    aniade(s);
    s = '';
    flujo.get(c);
  }
  return flujo;
}
*/

istream& operator>>(istream &flujo, FechaHistorica &fecha){

	string s;

	getline(flujo, s, '#');

	fecha.year() = stoi(s);

	while(!flujo.eof()){
		getline(flujo, s, '#');
		fecha.aniade(s);
	}
	return flujo;
}

