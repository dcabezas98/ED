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
     cout << "3 argumentos" << endl;
     if(strstr(argv[2],".txt") != 0){
       salida = argv[2];

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

   Cronologia c1, c2;

   f >> c1;

   c2 = c1.subcronologia(clave);

   if(pantalla)
     cout << c2;

   else{
     cout << "Entra aqui" << endl;
     ofstream fout(argv[3]);
     if (!fout){
      cout<<"No puedo crear el fichero "<<argv[3]<<endl;
      return 0;
     }
     cout << "HOLA" << endl;

     fout << c2;
  }
}
