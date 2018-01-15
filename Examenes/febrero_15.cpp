/*************************************************************************
  2. Dada una lista que contiene pilas con enteros y que se encuentra
  ordenada de menor a mayor por el tope de cada pila, implementar una 
  función borrar, que elimina el tope de cada pila en la lista, con 
  valores iguales al dado como parámetro. La cabecera de la función sería:

  void Borrar(list<stack<int> > & L, int elemento)
**************************************************************************/

void Borrar(list<stack<int>> & L, int elemento){
  
  list<stack<int>>::iterator it;
  list<stack<int>>::iterator it2;
  bool found;
  stack<int> aux;
  
  for(it=L.begin(); it!=L.end(); it++){
    if((*it).top()==elemento){
      (*it).pop();

      if(!(*it).empty()){
	aux=(*it);
	L.erase(it);

	if(aux.top()>=L.back().top()){
	  L.push_back(aux);
	} else{

	  found=false;
	  
	  it2=L.begin();

	  while(!found){
	    if((*it2).top()<aux.top())
	      it2++;
	    else
	      found=true;
	  }
	  insert(it2, aux);
	}
      } else{
	erase(it);
      }
    }
  }  
}

/**********************************************************************
  3. Implementar una función que muestre las etiquetas de los nodos de un
  árbol binario de enteros que estén entre dos niveles dados n1 y n2
  (0<=n1<n2) ambos inclusive.
*********************************************************************/

void mostrar_nodos(int n1, int n2, bintree<int>::node nodo, int prof){

  if(prof>=n1 && prof<=n2)
    cout<< *nodo <<endl;

  if(prof<n2){
    if(!nodo.left().null())
      mostrar_nodos(n1, n2, nodo.left(), prof+1);
    
    if(!nodo.right().null())
      mostrar_nodos(n1, n2, nodo.right(), prof+1);
  }
}

void mostrar_nodos(int n1, int n2, bintree<int> a){
  mostrar_nodos(n1,n2,a.root(),0);  
}

/*************************************************************************
  4. Se dice que un árbol binario de enteros es inferior a otro si (teniendo
  la misma estructura de ramificación), los elementos del primero, en los
  nodos coincidentes en posición, son menores que los del segundo. Diseñar 
  una función booleana que dados dos árboles binarios, devuelva true si el
  primero es inferior al segundo.

  bool es_inferior(bintree<int> & ab1, bintree<int> & ab2)
*************************************************************************/

bool inferior(bintree<int>::node n1, bintree<int>::node n2){

  if(!n1.right().null() && n2.right().null())
    return false;

  if(n1.right().null() && !n2.right().null())
    return false;

  if(!n1.left().null() && n2.left().null())
    return false;

  if(n1.left().null() && !n2.left().null())
    return false;

  if(*n1 >= *n2)
    return false;

  if(!n1.left().null() && !n2.left().null()){
    if(!inferior(n1.left(), n2.left()))
      return false;
  }

  if(!n1.right().null() && !n2.right().null()){
    if(!inferior(n1.right(), n2.right()))
      return false;
  }

  return true;
}

bool es_inferior(bintree<int> & ab1, bintree<int> & ab2){
  return inferior(ab1.root(), ab2.root());
}

/*************************************************************************
  5. Implementar un iterador que itere sobre las claves que sean números
  primos en una clase Diccionario definida como:

  class Diccionario{
  private:
    map<int, list<string> > datos;
    .............
    .............
  }

  Han de implementarse (aparte de las de la clase iterador) las funciones
  begin() y end().

  Se supone implementada una función bool primo (int x) que devuelve true
  si el entero x es primo.
*************************************************************************/

class Diccionario{
private:

  map<int, list<string>> datos;

public:

  class iterador_primo{

  private:

    map<int, list<string>> it;

  public:
 
    iterador_primo():it(){}
    iterador_primo(const iterador_primo & c):it(c.it){}
    iterador_primo(const map<int, list<string>>::iterator & p):it(p){}
    
    iterador_primo & operator=(const iterador_primo & c){
      it = c.it;
    }

    bool operator==(const iterador_primo & otro){
      return it == c.it;
    }

    bool operator!=(const iterador_primo & otro){
      return it != c.it;
    }

    iterador_primo & operator++(){

      do{
	it++;
      }while(it != datos.end() && !primo(*it));

      return *this;
    }

    pair<int, list<string>> & operator*(){
      return *it;
    }
  };

  iterador_primo begin(){

    iterador_primo it(datos.begin());

    if(!primo((*it).first))
      it++;

    return it;
  }

  iterador_primo end(){

    iterador_primo it(datos.end());

    return it;
  }
};
