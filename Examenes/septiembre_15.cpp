/*********************************************************
  2. Se pretende almacenar k pilas en un único vector.
  Implementa las funciones push y pop que insertan/borra
  un determinado entero en una de las pilas
**********************************************************/

template<class T>
class pilak{
private:
  vector<T> datos;
  vector<int> base;
  vector<int> tope;

  //Precondición: Hay sitio en la pila k
  void move(int k){
    if(tope[k]==base[(k+1)%base.size()]){
      move((k+1)%base.size());
    }

    for(int i=tope[k]; i!=base[k]; i=(i+datos.size()-1)%datos.size())
      datos[i]=datos[(i+pila.size()-1)%datos.size()];

    tope[k]++;
    base[k]++;
  }
  
public:
  void pop(int k){
    if(tope[k]!=base[k])
      tope[k]=(tope[k]+datos.size()-1)%datos.size();
  }
  
  void push(int k, T dato){
    if(nelem()!=datos.size()){
      if(tope[k]==base[(k+1)%base.size()]){
	move((k+1)%base.size());
      }
      datos[tope[k]]=dato;
      tope[k]=(tope[k]+1)%datos.size();
    }
  }
  
  int nelem(){
    int suma=0;
    for(int i=0; i<base.size(); i++)
      suma+=nelem(i);
    
    return suma;
  }
  
  int nelem(int k){
    return tope[k]-base[k];
  }
  
};

/*****************************************************************
  3. Dada una lista de enteros con elementos repetidos, diseña 
  (usando el TDA list) una función que construya a partir de 
  ella una lista ordenada de listas, de forma que en la lista 
  resultado los elementos iguales se agrupen en la misma sublista. 
  La lista original no se ve modificada. Por ejemplo:

  entrada={1,3,4,5,6,3,2,1,4,5,5,1,1,7}  
  salida={{1,1,1},{2},{3,3},{4,4},{5,5,5},{6},{7}}
******************************************************************/

list<list<int>> agrupa (const list<int> &in){
  
  list<list<int>> out;
  map<int, int> aux;
  list<int>::iterator it;
  map<int, int>::iterator itm;
  
  for(it=in.begin(); it!=in.end(); it++){
    if(aux.count(*it)==0){
      aux[*it]=1;
    } else {
      aux[*it]++;
    }
  }

  list<int> aux1;
  for(itm=aux.begin(); itm!=aux.end(); itm++){
    aux1.clear();
    for(int i=0; i<(*itm).second; i++){
      aux1.push_front((*itm).first);
    }

    out.push_back(aux1);
  }

  return out;
}

/*********************************************************************
  4.-Sea T un árbol binario con n nodos cuyas etiquetas (de tipo string)
  son todas diferentes. Se define un k-nodo como un nodo v que cumple la 
  condición de que el número de descendientes en el subárbol izquierdo de
  v difiere del número de descendientes del subárbol derecho al menos en 
  k elementos. Usando el TDA bintree, diseña una función que tenga como 
  entrada un árbol binario de string y como salida el listado de las 
  etiquetas de los 5-nodos que posee.

list<string> cinconodos(bintree<string> & ab)
**********************************************************************/


// Precondición: árbol no vacío
list<string> cinconodos(bintree<string> &ab){

  list<string> lista;
  cinconodos(ab, lista);

  return lista;
}

int cinconodos(bintree<string> &ab, list<string> &l){

  int sumaizq=0, sumadcha=0;
  bintree<string> aux;

  if(!ab.root().left().null()){
    aux.assign_subtree(ab, ab.root().left());
    sumaizq=cinconodos(aux, l);
  }
  
  if(!ab.root().right().null()){
    aux.assign_subtree(ab, ab.root().right());
    sumadcha=cinconodos(aux, l);
  }  

  if(abs(sumaizq-sumadcha)>=5)
    l.push_back(*ab.root());

  return sumaizq+sumadcha+1;
}

/**************************************************************************
  5.-Implementa un iterador que itere sobre las claves que sean números pares
  en una clase Diccionario definida como:

  class Diccionario{
  private:
    map<int, list<string> > datos;
    .............
    .............
  }

  Han de implementarse (aparte de las de la clase iterador) las funciones
  begin() y end().
***************************************************************************/

class Diccionario{
  
private:
  map<int, list<string> > datos;

public:
  
  class iterator{  
  private:
    map<int, list<string>>::iterator it;
    friend class Diccionario;
    
  public:
    iterator():it(){}
    iterator(const iterator &c):it(c.it){}
    iterator(const map<int, list<string>::iterator p):it(p){}
    
    iterator& operator=(const iterator &c){
      if(&c!=this)
	it=c.it;
      return *this;
    }
    
    pair<int, list<string>> & operator*(){
      return *it;
    }
    
    iterator& operator++(){
      
      do{
	it++;
      } while(it!=datos.end() && (*it).first%2);
      
      return *this;
    }
    
    bool operator==(const iterator &c){
      return (*it).first==(*c.it).first;
    }
    
    bool operator!=(const iterator &c){
      return (*it).first!=(*c.it).first;
    }
  };

  iterator begin(){
    iterator p(datos.begin());
    if((*p).first%2)
      p++;
    return p;
  }
  
  iterator end(){
    iterator p(datos.end());
    return p;
  }
};
