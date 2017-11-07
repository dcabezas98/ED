#include <iostream>
#include "Pila_max.h"

using namespace std;

int main(){
  PilaMax p;
  int i;
  for ( i=10; i>=0 ; i--){
    p.poner(i);
  }
    p.poner(100);

  while (!p.vacia() ){

    Pareja x = p.tope();
    cout << x <<endl;
    p.quitar();
    cout <<"hola" << p.vacia()<< endl;
  }
    return 0;
}
