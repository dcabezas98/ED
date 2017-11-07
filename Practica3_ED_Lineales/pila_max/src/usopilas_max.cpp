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
    p.poner(25);
    p.poner(75);
    p.poner(1000);
    p.poner(500);

  while (!p.vacia() ){

    Pareja x = p.tope();
    cout << x <<endl;
    p.quitar();
  }
    return 0;
}
