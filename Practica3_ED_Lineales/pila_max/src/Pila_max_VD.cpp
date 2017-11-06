#include <iostream>
#include <cassert>
#include "pila.h"

using namespace std;

PilaMax::PilaMax(const PilaMax &otra):elementos(otra.elementos){}

PilaMax& PilaMax::operator= (const PilaMax& otra){
  elementos=otra.elementos;
}

bool PilaMax::vacia() const{
  return elementos.empty();
}

Pareja& PilaMax:: tope(){
  return elementos[elementos.used()-1];
}

const Pareja& tope() const{
  return elementos[elementos.used()-1];
}

void PilaMax:: poner(const int &n){

  int mayor = n > maximo()?n:maximo();

  Pareja p={n,mayor};

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
