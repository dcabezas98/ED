#include <iostream>
#include <cassert>
#include "Pila_max_Cola.h"

using namespace std;

PilaMax::PilaMax(const PilaMax &otra):elementos(otra.elementos){}

PilaMax& PilaMax::operator= (const PilaMax& otra){
  elementos=otra.elementos;
}

bool PilaMax::vacia() const{
  return elementos.vacia();
}

Pareja& PilaMax:: tope(){
  return elementos;
}

const Pareja& tope() const{
  return elementos.frente();
}

void PilaMax:: poner(const int &n){

  int mayor = n > maximo()?n:maximo();

  Pareja p={n,mayor};

  
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
