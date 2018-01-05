/**************************************************************************
  2. Una lista L se dice que está ordenada de forma
  ascendente por índices (orden indexado) si la secuencia
  {L(indices(0)),L(indices(1)),...L(indices(indices.size()-1))}. (siendo
  L(i) el elemento en la posición i-ésima), es una secuencia ordenada de
  forma ascendente.  Necesariamente indices debe ser una lista de
  enteros que indica una secuencia de índices en L.  Implementa una
  función booleana que reciba L (L puede ser de cualquier tipo de dato) y
  un índice I y devuelva true si L está ordenada de forma ascendente con
  respecto al índice.  

  Ejemplo: Para L= {2.2, 7.1, 3.4, 9.0, 6.2, 5.1} e
  I={0, 2, 5, 4, 1, 3}, la función devolvería true.
**************************************************************************/

/*
  next(iterator, n);

  Devuelve un iterador que apunta n posiciones por encima de iterator.
  De tal manera que

  *next(L.begin(), n) devuelve el n-ésimo elemento de la lista L
*/

#include <iterator>  // Necesario para next
using namespace std; // Necesario para next

template <class T>
bool ordenada_ascendente_indices(list<T> L, list<int> I){

  bool ordenada = true;
  list<int>::iterator it = I.begin();

  int anterior = *next(L.begin(), *it);

  for(it++; it != I.end() && ordenada; it++){ // Recorro I desde la posición 1

    if(next(L.begin(), *it) > anterior)
      ordenada = false;

    else
      anterior = *next(L.begin(), *it);
  }

  return ordenada;
}

/**************************************************************************
  3. Implementa una función booleana que devuelva true si
  un árbol binario de enteros ab2 coincide con un subárbol de otro ab1
  (deben coincidir también los valores de las etiquetas). 

  bool es_subarbol(const bintree<int> & ab1, const bintree<int> & ab2)
**************************************************************************/

/*
  Supongo programadas todas las funciones de la clase bintree de la
  práctica final.
*/

bool es_subarbol(const bintree<int> & ab1, const bintree<int> & ab2){

  bool is_subtree = false;

  if(ab2 == ab1) // Compruebo si son iguales
    is_subtree = true;

  else{

    bintree<int> aux;

    if(!ab1.root().left().null()){ // Si hay subárbol a la izquierda de la raíz

      aux.assign_subtree(ab1, ab1.root().left());

      if(is_subtree(aux, ab2)) // Compruebo si es subárbol del subárbol a la izquierda de la raíz de ab1
	is_subtree = true;
    }

    if(!is_subree && !ab1.root().left().null()){ // Si hay subárbol a la derecha de la raíz

      aux.assign_subtree(ab1, ab1.root().right());

      if(is_subtree(aux, ab2)) // Compruebo si es subárbol del subárbol a la izquierda de la raíz de ab1
	is_subtree = true;
    }
  }

  return is_subtree;
}

/**************************************************************************
  4. Implementa un TDA cola usando dos pilas.
**************************************************************************/

/*
  El TDA pila cuenta con la siguiente funcionalidad:

    empty
    size
    top
    push
    pop

  El TDA cola debe contar con la siguiente funcionalidad:

    empty
    size
    front
    back
    push
    pop
*/

template <class T>
class queue{

  stack<T> entrada; // Su tope es el último de la cola
  stack<T> salida;  // Su tope es el frente de la cola

  /* Vuelca la pila de entrada en la de salida, la de salida debe estar vacía */
  void dump(){

    T elemento;

    while(!entrada.empty()){

      elemento = entrada.top();
      entrada.pop();

      salida.push(elemento);
    }
  }

public:

  bool empty(){
    
    return entrada.empty() && salida.empty();
  }

  int size(){

    return entrada.size() + salida.size();
  }

  T& front(){
    
    assert(!empty());
    
    if(salida.empty())
      dump();

    return salida.top();
  }

  const T& front() const{
    
    assert(!empty());
    
    if(salida.empty())
      dump();

    return salida.top();
  }

  T& back(){

    assert(!empty());

    if(entrada.empty()){ // Si la pila de entrada está vacía

      T elemento;

      while(!salida.empty()){ // Vuelco la de salida en la de entrada
	
	elemento = salida.top();
	salida.pop();

	entrada.push(elemento);
      }
    }

    return entrada.top(); // Último de la fila
  }

  const T& back() const{

    assert(!empty());

    if(entrada.empty()){ // Si la pila de entrada está vacía

      T elemento;

      while(!salida.empty()){ // Vuelco la de salida en la de entrada
	
	elemento = salida.top();
	salida.pop();

	entrada.push(elemento);
      }
    }

    return entrada.top(); // Último de la fila
  }

  void push(const T & elemento){

    entrada.push(elemento);
  }

  void pop(){

    assert(!empty());

    if(salida.empty())
      dump();

    salida.pop();
  }  
};

/**************************************************************************
  5. Se dispone de un TDA indice donde para cada palabra se almacenan
  los números de página en los que aparece en un libro. Se desea
  recorrer el índice considerando únicamente las ocurrencias en páginas
  impares de las palabras del contenedor. Para implementar el índice se
  ha seleccionado la siguiente estructura: 

  class indices{ 
    private:
      map<string, set<int> > datos;
    .............  
    .............  
  } 

  Se pide implementar el TDA indice::iterator deseado, de forma que el
  operator* devuelva tanto la palabra como el número de página (que ha
  de ser necesariamente impar).  Además de los métodos de la clase
  iterador, se deben implementar las funciones begin() y end().
**************************************************************************/


