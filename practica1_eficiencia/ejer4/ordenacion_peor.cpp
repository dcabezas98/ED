#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void ordenar(int *v, int n) {
  for (int i=0; i<n-1; i++)
    for (int j=0; j<n-i-1; j++)
      if (v[j]>v[j+1]) {
	int aux = v[j];
	v[j] = v[j+1];
	v[j+1] = aux;
      }
}

void sintaxis() {
  cerr << "Sintaxis:" << endl;
  cerr << " TAM: Tamaño del vector (>0)" << endl;
  cerr << "Genera un vector de TAM números aleatorios" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {

  if (argc!=2)
    sintaxis();
 
  int tam=atoi(argv[1]);
  
  if (tam<=0)
    sintaxis();
  
  int *v=new int[tam];

  for (int i=0; i<tam; i++)
      v[i] = tam-i;
      
  clock_t tini;
  tini=clock();

  ordenar(v,tam); 

  clock_t tfin;
  tfin=clock();

  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

  delete [] v;
}
