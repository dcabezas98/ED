#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int TAM = 510;

int main(int nArgs, char *args[]) {
 
  if(nArgs != 2)
    return 1;

  int n = atoi(args[1]);

  if(n > TAM)
    return 1;
  
  int m1[TAM][TAM];
  int m2[TAM][TAM];
  int m3[TAM][TAM];

  int i,j,k;

  srand(time(0));
  
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) {
      m1[i][j] = rand() % 10000;
      m2[i][j] = rand() % 10000; 
    }

  clock_t tini;
  tini = clock();

  //Multiplicacion
  int suma;
  
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) {
      suma = 0;

      for(k = 0; k < n; k++)
	suma += m1[i][k]*m2[k][j];
      
      m3[i][j] = suma;
    }

  clock_t tfin;
  tfin = clock();

  cout << n << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
}

  

    


    
