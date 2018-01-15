/**********************************************************
Dado un árbol binario de enteros, obtener todos los caminos
que contengan un valor concreto. (Los caminos han de llegar 
esta una hoja)
**********************************************************/

// Unión de conjuntos
template<class T>
multiset<T> union(multiset<T> s1, multiset<T> s2){

  multiset<T>::iterator it;
  multiset<T> res(s2);

  for(it = s1.begin(); it != s1.end(); it++)
    res.insert(*it);

  return res;
}

/*
Devuelve un multiset con las listas de etiquetas de los nodos
que forman los caminos desde un nodo dado a cada hoja.
*/
void caminos(bintree<int>::node n, multiset<list<int>> &paths){

  if(n.right().null() && n.left().null()){
    list<int> path;
    path.push_back(*n);
    paths.insert(path);
  }

  else{
  
    multiset<list<int>> aux1;
    multiset<list<int>> aux2;

    if(!n.left().null())
      caminos(n.left(), aux1);

    if(!n.right().null())
      caminos(n.right(), aux2);

    paths = union(aux1, aux2);

    multiset<list<int>>::iterator it;
    
    for(it = paths.begin(); it != paths.end(); it++)
      (*it).push_front(*n);
  }
}

/*
Obtenemos todos los caminos que parten de la raíz
y nos quedamos con los que contienen la etiqueta dada.
*/
multiset<list<int>> caminos(bintree<int> a, int valor){

  multiset<list<int>> paths;

  caminos(a.root(), paths);

  multiset<list<int>>::iterator it;

  for(it = paths.begin(); it != paths.end(); it++){
    if((*it).find(valor) == (*it).end())
      paths.erase(it);
  }

  return paths;
}


