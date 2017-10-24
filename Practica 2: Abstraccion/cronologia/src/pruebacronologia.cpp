#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Cronologia mi_cronologia;
   f>>mi_cronologia; //Cargamos en memoria la cronología.
   
   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener los eventos acaecidos en un año dado

   int y, pos;
   cout << "Introduzca el año que quiere consultar" << endl;
   cin >> y;

   pos = mi_cronologia.searchYear(y);

   if (pos != -1){
     cout << "Los acontecimientos ocurridos en el año " << y <<" son:\n";

     for (int i=0; i< mi_cronologia[pos].nhechos(); i++){
       cout << mi_cronologia[pos][i] << endl;
     }
	    
   }else{
     cout << "El año introducido no está en la cronología.\n";
   }
   
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   
   int anioDesde, anioHasta;

   cout << "Introduzca el año donde empieza la subcronología: ";
   cin >> anioDesde;
   cout << "Introduzca el año donde termina la subcronología: ";
   cin >> anioHasta;

   Cronologia subcronoA;
   subcronoA= mi_cronologia.subcronologia(anioDesde, anioHasta);

   cout << "La subcronologia que comienza en : " << anioDesde << " y termina en " << anioHasta << " es: \n" << subcronoA << endl;
   

   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"

   string busca;
o
   cout << "Inserte cadena a buscar: ";
   cin >> busca;

   cout << "Subcronología que la contiene:\n" << mi_cronologia.subcronologia(busca) << endl;
     
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)

   Cronologia aUnir;
   string nombre;

   cout << "Ruta de la cronología a unir: ";
   cin >> nombre;

   ifstream f1 (nombre);
   if (!f1){
    cout<<"No puedo abrir el fichero "<< nombre <<endl;
    return 0;
   }

   f1 >> aUnir;

   cout << "Cronología resultante de unir la anterior cronología a la nueva:" << endl;

   aUnir += mi_cronologia;

   cout << aUnir << endl;
}
