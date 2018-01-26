// David Cabezas Berrido
// Doble Grado en Ingeniería Informática y Matemáticas

#include <iostream>
#include <set>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/*
  Intersección de tres subconjuntos.
 */

template <class T>
void interseccion(const set<T> &s1, const set<int> &s2, const set<T> &s3, set<T> &res){

  res.clear();
  typename set<T>::iterator it;

  for(it = s1.begin(); it != s1.end(); it++){
    if(s2.count(*it) && s3.count(*it))
      res.insert(*it);
  }
}

/*
  Dados tres conjuntos, devuelve un conjunto fomado por los elementos
  que solamente están en uno de los tres.
 */

template <class T>
void union_diferencial(const set<T> &s1, const set<int> &s2, const set<T> &s3, set<T> &res){

  res.clear();
  typename set<T>::iterator it;

  for(it = s1.begin(); it != s1.end(); it++){
    if(!s2.count(*it) && !s3.count(*it))
      res.insert(*it);
  }

  for(it = s2.begin(); it != s2.end(); it++){
    if(!s1.count(*it) && !s3.count(*it))
      res.insert(*it);
  }

  for(it = s3.begin(); it != s3.end(); it++){
    if(!s1.count(*it) && !s2.count(*it))
      res.insert(*it);
  }
}

int main(){
 
  set<int> s1, s2, s3, intersect, uniDif;

  s1.insert(1);
  s1.insert(2);
  s1.insert(4);
  s1.insert(5);
  s1.insert(8);
  
  s2.insert(4);
  s2.insert(5);
  s2.insert(6);
  s2.insert(9);

  s3.insert(3);
  s3.insert(4);
  s3.insert(7);
  s3.insert(8);
  s3.insert(9);

  interseccion(s1, s2, s3, intersect);

  union_diferencial(s1, s2, s3, uniDif);

  cout << "Conjunto intersección: ";
  cout << intersect << endl;

  cout << "Conjunto unión diferencial: ";
  cout << uniDif << endl;
} 
