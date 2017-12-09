#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=4 && argc!=5){
      cout<<"Error: debe dar al menos el nombre de un fichero con cronología y los límites inferior y superior del intervalo. "<<endl;
      cout<<"[Opcional]: un nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }

   ifstream f(argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Cronologia c1, c2;

   f >> c1;

   c2 = c1.subcronologia(atoi(argv[2]), atoi(argv[3]));

   if(argc == 4)
     cout << c2;

   else{

     ofstream fout(argv[4]);

     if (!fout){
      cout<<"No puedo crear el fichero "<<argv[4]<<endl;
      return 0;
     }

     fout << c2;
  }
}
