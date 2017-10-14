#include <iostream>
#include "fechahistorica.h"
#include "vectordinamico.h"

using namespace std;

FechaHistorica::FechaHistorica() {
  anio=0; 
}

FechaHistorica::FechaHistorica(int n){
  anio=n;
}

FechaHistorica::FechaHistorica(const FechaHistorica &original):hechos(original.hechos) {
  anio=original.anio;
}

FechaHistorica&& FechaHistorica::operator=(const FechaHistorica &original){
  anio = original.anio;

  hechos = original.hechos;
}

int FechaHistorica::nhechos() {
  return hechos.utilizados();
}

int FechaHistorica::anio() {
  return anio;
}

void FechaHistorica::aniade(string h) {
  hechos.aniade(h);
}

FechaHistorica& FechaHistorica::operator+=(const FechaHistorica &nuevo){
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

friend ostream& operator<<(ostream &flujo, const FechaHistorica &fecha){
  flujo<<anio;

  for (int i=0; i<nhechos(); i++){
    flujo<<"#";
    flujo<<hechos[i];
  }

  flujo<<"\n";
}

friend istream& operator>>(istream flujo, FechaHistorica &fecha){

  string s;
  char c;

  flujo >> c;
  
  while(c != '#'){

    s = s + c;
  }

  anio = stoi(s);

  s = '';
  flujo.get(c);

  while(c != '\n'){
    while(c != '#'){
      
      s = s + c;
      flujo.get(c);
    }

    aniade(s);
    s = '';
    flujo.get(c);
  }
}

