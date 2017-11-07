#include <iostream>
#include <climits>
#include <cassert>
#include "Pila_max_VD.h"

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
  return elementos.empty();
}

Pareja& PilaMax:: tope(){
  return elementos[elementos.used()-1];
}

const Pareja& PilaMax:: tope() const{
  return elementos[elementos.used()-1];
}

void PilaMax:: poner(const int &n){

  int mayor = n > maximo()?n:maximo();

  Pareja p;
  p.valor = n;
  p.max = mayor;

  elementos.aniade(p);
}

void PilaMax:: quitar(){
  elementos.elimina(elementos.used()-1);
}

int PilaMax:: nelementos() const{
  return elementos.used();
}

int PilaMax:: maximo() const{

  if(elementos.empty()) return INT_MIN;
    return tope().max;
}
