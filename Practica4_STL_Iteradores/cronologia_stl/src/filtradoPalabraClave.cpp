#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char * argv[]){

  string clave;
  string salida;
  bool pantalla = false;

  if (argc!=2 && argc!=3 && argc!=4){
      cout<<"Error: debe dar al menos el nombre de un fichero con cronología. "<<endl;
      cout<<"[Opcional]: Palabra clave a buscar."<<endl;
      cout<<"[Opcional]: un nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }

   ifstream f(argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   if(argc == 3){
     if(strstr(argv[2],".txt") != 0){
       salida = string(argv[2]);

       cout << "Inserte cadena a buscar:";
       cin >> clave;
     }

     else{
       clave = argv[2];
       pantalla = true;
     }
   }

   else if(argc == 2){

     pantalla = true;
     cout << "Inserte cadena a buscar:";
     cin >> clave;
   }
   else {
     salida = argv[3];
     clave = argv[2];
   }

   Cronologia c1, c2;

   f >> c1;

   c2 = c1.subcronologia(clave);

   if(pantalla)
     cout << c2;

   else{
     ofstream fout(salida);
     if (!fout){
      cout<<"No puedo crear el fichero "<<salida<<endl;
      return 0;
     }

     fout << c2;
  }
}
