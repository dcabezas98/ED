#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Error: debe introducir el nombre de un fichero con cronología. "<< endl;
      return 0;
   }

   ifstream f(argv[1]);

   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Cronologia c;

   f >> c;

   c.recuento();
}
