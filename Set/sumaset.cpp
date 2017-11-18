/*
  David Cabezas Berrido
  Suma de dos conjuntos de enteros

  Defiinimos la suma entre dos conjuntos de una forma peculiar.
  Sean A, B conjuntos

  A + B = (A u B)\(A n B)

  Donde "u" denota unión y "n" intersección. "\" se refiere al complementario.
  Es decir, X\Y es el conjunto formado por los elementos de X que no pertenecen
  a Y.

  Definimos la suma de esta forma porque le da a los conjuntos estructura de
  grupo, con el vacío como elemento neutro y el propio conjunto como el inverso.
*/

#include <set>
#include <iostream>
#include <fstream>

using namespace std;

void ayuda(){
  cout << "Uso:\n ./sumaset <conjunto A> <conjunto B> <salida>" << endl;
}

int main(int argc, const char *argv[]){

  if(argc != 4){
    cerr << "Deben introducirse 3 argumentos" << endl;
    ayuda();
    exit(-1);
  }

  ifstream f1, f2;

  f1.open(argv[1]);

  if(!f1){
    cerr << "Error de apertura del fichero " << argv[1] << endl;
    ayuda();
    exit(-1);
  }

  f2.open(argv[2]);

  if(!f2){
    cerr << "Error en la apertura del fichero " << argv[2] << endl;
    f1.close();
    ayuda();
    exit(-1);
  }

  set<int> conjuntoA, conjuntoB;

  int n;

  f1 >> n;

  if(!f1){
    cerr << "Error en la lectura del fichero " << argv[1] << endl;
    f1.close();
    f2.close();
    ayuda();
    exit(-1);
  }

  while(f1.good()){
    conjuntoA.insert(n);
    f1 >> n;
  }

  f1.close();

  f2 >> n;

  if(!f2){
    cerr << "Error en la lectura del fichero " << argv[2] << endl;
    f2.close();
    ayuda();
    exit(-1);
  }

  while(f2.good()){
    conjuntoB.insert(n);
    f2 >> n;
  }

  f2.close();

  set<int> conjuntoC;

  set<int>::iterator i1 = conjuntoA.begin();
  set<int>::iterator i2 = conjuntoB.begin();

  while(i1 != conjuntoA.end() && i2 != conjuntoB.end()){

    if(*i1 < *i2){
      conjuntoC.insert(*i1);
      i1++;
    }
    else if(*i1 > *i2){
      conjuntoC.insert(*i2);
      i2++;
    }
    else{
      i1++;
      i2++;
    }
  }

  while(i1 != conjuntoA.end()){
    conjuntoC.insert(*i1);
    i1++;
  }

  while(i2 != conjuntoB.end()){
    conjuntoC.insert(*i2);
    i2++;
  }

  ofstream f3(argv[3]);

  if(!f3){
    cerr << "Error en la apertura del fichero " << argv[3] << endl;
    ayuda();
    exit(-1);
  }

  for(set<int>::iterator i3 = conjuntoC.begin(); i3 != conjuntoC.end(); i3++){
    f3 << *i3 << " ";
  }

  if(!f3){
    cerr << "Error en la escritura del fichero " << argv[3] << endl;
    f3.close();
    ayuda();
    exit(-1);
  }

  f3.close();
}
