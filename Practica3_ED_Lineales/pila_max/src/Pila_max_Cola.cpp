#include <iostream>
#include <cassert>
#include <climits>
#include "Pila_max_Cola.h"

using namespace std;

ostream& operator <<(ostream &flujo, const Pareja &p){
  flujo << p.valor << " | " << p.max << "\n";
  return flujo;
}

PilaMax::PilaMax(const PilaMax &otra):elementos(otra.elementos){}

PilaMax& PilaMax::operator= (const PilaMax& otra){
  if(&otra != this)
    elementos=otra.elementos;
  return *this;
}

bool PilaMax::vacia() const{
  return elementos.vacia();
}

Pareja& PilaMax:: tope(){
  return elementos.frente();
}

const Pareja& PilaMax:: tope() const{
  return elementos.frente();
}

void PilaMax:: poner(const int &n){

  int mayor = n > maximo()?n:maximo();

  Pareja p;
  p.valor = n;
  p.max = mayor;

  PilaMax aux(*this);
  elementos.poner(p);

  int num=elementos.num_elementos()-1;

  for(int i=0; i<num; i++){
    elementos.quitar();
  }

  for(int i=0; i<num; i++){
    elementos.poner(aux.tope());
    aux.quitar();
  }
}

void PilaMax:: quitar(){
  elementos.quitar();
}

int PilaMax:: nelementos() const{
  return elementos.num_elementos();
}

int PilaMax:: maximo() const{

  if(elementos.vacia()) return INT_MIN;
    return tope().max;
}
