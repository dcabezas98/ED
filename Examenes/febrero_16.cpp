/**********************************************************************************
  1. Construye una clase agenda que de soporte al manejo de información del tipo
  persona: <nombre, num_telefono, direccion>. Los nombre son todos distintos y se
  tiene que poder buscar de forma eficiente tanto por nombre como por número de
  teléfono o dirección. Además de en tiempo también debe ser eficiente en espacio.
  Implementa las funciones: persona buscar_nombre(string nom), persona
  buscar_telefono(string num), void insertar(persona p).
***********************************************************************************/

#include <unordered_map>

class agenda{

  unordered_map<string, persona*> nombres;
  unordered_map<string, persona*> nums_telefono;
  unordered_map<string, persona*> direcciones;

public:
  
  persona buscar_nombre(string nom){

    unordered_map<string, persona*>::iterator it;
      
    if((it = nombres.find(nom)) != nombres.end())
      return *(*it).second;
  }

  persona buscar_telefono(string num){

    unordered_map<string, persona*>::iterator it;
    
    if((it = nums_telefono.find(num)) != nums_telefono.end())
      return *(*it).second;
  }

  void insertar(persona p){
    
    persona *ptr = &p;
    
    nombres.insert({p.nombre, ptr});
    nums_telefono.insert({p.num_telefono, ptr});
    direcciones.insert({p.direccion, ptr});
  }
};

/**********************************************************************************
  2. Implementa una función bool sumaIgual(const list<list<int> > &L) 
  que devuelve true si todas las sumas por filas y
  por columnas da el mismo resultado (se asume que todas las listas
  tienen igual longitud). 

  Por ejemplo, en la siguiente lista si se suma cada fila y cada columna 
  siempre se obtiene 3 

                      L=< <0,1,1,1>,
                          <2,1,0,0>, 
                          <1,0,2,0>, 
                          <0,1,0,2> >
***********************************************************************************/

bool sumaIgual(const list<list<int> > &L){

  int *sum_columna = new int[L.size()];
  int i;
  
  for(i = 0; i < L.size(); i++)
    sum_columnas[i] = 0;
  
  list<list<int>>::iterator it1 = L.begin();
  list<int>::iterator it2;

  int objetivo, suma;

  for(i = 0, it2 = (*it1).begin(), suma = 0; it2 != (*it1).end(); it2++, i++){
    
    suma += *it2;
    sum_columna[i] += *it2;
  }

  objetivo = suma;

  bool stop = false;

  for(it1 = L.begin; it1 != L.end() && !stop; it++){
    for(i = 0, it2 = (*it1).begin(), suma = 0; it2 != (*it1).end() && !stop; it2++, i++){

      suma += *it2;
      sum_columna[i] += *it2;
    }

    if(suma != objetivo)
      stop = true;
  }

  if(stop)
    return false;

  for(i = 0; i < L.size(); i++){

    if(sum_columna[i] != objetivo)
      return false;
  }

  return true;
}

/**********************************************************************************
  3. Una secuencia guiada sobre un árbol binario de enteros comienza por
  la raíz para a continuación, en cada paso, seleccionar el nodo con etiqueta más
  pequeña de entre los nodos disponibles en ese momento que no hayan sido listados.
  Se entiende por nodo disponible aquel cuyo padre ya ha sido procesado (excluyendo
  la raíz).
  
  a) ¿Qué estructura auxiliar utilizarías para almacenar el conjunto de nodos
  disponibles? Razona tu respuesta.
  
  b) Implementar una función que permita obtener una secuencia guiada de un árbol
  binario.
***********************************************************************************/

/*
  Supongo que no se repiten las etiquetas.

  a) Eligiría la cola con prioridad.
     Acceso a mínimo en tiempo constante.
     Inserción y borrado en tiempo logarítmico. 
*/

/*
  b)
*/

class Comp_node{
  
public:
  
  bool operator() (const bintree<int>::node& lhs, const bintree<int>::node& rhs) const{
    
    return (*lhs > *rhs);
  }
};

void secuencia guiada(bintree<int> arbol, vector<int> &rec){

  bintree<int>::node nodo = arbol.root();

  priority_queue<bintree<int>::node, Comp_node> cola;

  cola.push(nodo);

  for(int i = 0; i < arbol.size; i++){

    nodo = cola.front();
    cola.pop();

    if(!nodo.left().null())
      cola.push(nodo.left());

    if(!nodo.right().null())
      cola.push(nodo.right());

    rec.push_back(*nodo);
  }
}

/**********************************************************************************
  4. Tenemos un contenedor de pares de elementos, {clave, vector<int>} definida como:

    template <typename T>
    class contenedor{
    private:
      unordered_map<T, vector<int> > datos;
      .............
      .............
    }

  Implementa un iterador que itere sobre los elementos que cumplan la propiedad de
  que la suma de los elementos del vector<int> sea un número impar. Han de
  implementarse (aparte de las de la clase iteradora) las funciones begin() y end().
***********************************************************************************/

template<typename T>
class contenedor{
  
private:

  unordered_map<T, vector<int>> datos;

public:

  class iterator_impar{
  public:

    iterator_impar() :it();
    iterator_impar(const iterator_impar &c) :it(c.it);
    iterator_impar(unordered_map<T, vector<int>>::iterator p) :it(p); // Para begin
    
    iterator_impar & operator++(){
      
      it++;
      bool found=false;

      while(!found && it != datos.end()){
	if(impar((*it).second))
	  found = true;
	else
	  it++;
      }

      return *this;
    }
    
    iterator_impar & operator=(const iterator_impar & c){
      it=c.it;
    }
    
    bool operator==(const iterator_impar & c){
      it==c.it;
    }
    
    bool operator!=(const iterator_impar & c){
      it!=c.it;
    }

    pair<T, vector<int>> & operator*(){
      return *it;
    }

  private:

    unordered_map<T, vector<int>>::iterator it;
    friend class contenedor;
    
    bool impar(const vector<int> &v){

      int suma = 0;
      for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
	suma+= *it;
      
      return suma%2;
    }
  };

  iterator_impar begin(){
    
    iterator p(datos.begin());
    if(!impar(*p.second)){
      p++;
    }

    return p;
  }
  
  iterator_impar end(){
    iterator_impar p(datos.end());
    return p;
  }
};
