# Memoria: Solución para crear árbol (y su mejora)
### Autores: Patricia Córdoba Hidalgo y David Cabezas Berrido

## Creación del árbol de preguntas:

Hemos creado una función *elige_preguntas* que admite como argumentos
un árbol por referencia y dos listas de índices: una con los índices
de los personajes que aún quedan levantados y otra con los índices de
los atributos que quedan por preguntar.

La función se encarga de colocar en la raíz del árbol **a** el primer
atributo disponible del vector de atributos. Tras esto, crea dos
listas, en una guarda los índices de los personajes que poseen ese
atributo, y en otra, los índices de los que no. A continuación,
elimina el índice del atributo elegido. 

La función crea otros dos árboles, **izda** y **dcha**, y se llama
recursivamente para crear las respectivas ramas con los personajes de
la lista correspondiente. Finalmente, inserta dichos árboles como
hijos del árbol **a**.

La recursividad termina cuando se llama a la función con una lista de
un sólo personaje, en cuyo caso, se limitará a colocar en la raíz del
árbol dado el nombre del personaje restante.

La función *crear_arbol* llama a la función *elige_preguntas*, dando
como argumento: dos listas con todos los índices de los atributos y
personajes del tablero y un árbol, el cual es devuelto por la función.

\newpage

```cpp
void QuienEsQuien::elige_preguntas(bintree<Pregunta> &a, list<int> pers, list<int> atrib){

  /*Si sólo queda un personaje, se coloca el nombre del personaje */
  if(pers.size() == 1){
    Pregunta pregunta(personajes[pers.front()],1);
    bintree<Pregunta> tree(pregunta);
    a = tree;
  }

  else{

    list<int> si; // Posiciones de los personajes que tienen el primer atributo de la lista
    list<int> no; // Posiciones de los personajes que no tienen el primer atributo de la lista
    list<int>:: iterator it_p;

    //Relleno las listas de personajes que tienen o no el atributo con mayor entropía
    for(it_p = pers.begin(); it_p != pers.end(); it_p++){ //Recorro la columna de personajes del atributo

      if(tablero[*it_p][atrib.front()]) //Si el personaje tiene el atributo
        si.push_back(*it_p);

      else //Si no tiene el atributo
        no.push_back(*it_p); //Lo añado a la lista de los que no lo tienen
    }

    /* Asigno la pregunta sobre el primer atributo*/
    Pregunta pregunta(atributos[atrib.front()], pers.size());
    bintree<Pregunta> tree(pregunta);
    a = tree;
    bintree<Pregunta> izda, dcha;

    atrib.pop_front();

    if(si.size() > 0)
      elige_preguntas(izda, si, atrib);

    if(no.size() > 0)
      elige_preguntas(dcha, no, atrib);

    a.insert_left(a.root(), izda);
    a.insert_right(a.root(), dcha);
  }
}
```

```cpp
bintree<Pregunta> QuienEsQuien::crear_arbol(){

  bintree<Pregunta> tree;

	list<int> pers;
	list<int> atrib;

	int i;

	for(i = 0; i < personajes.size(); i++)
		pers.push_back(i);

	for(i = 0; i < atributos.size(); i++)
		atrib.push_back(i);

  elige_preguntas(tree, pers, atrib);

  return tree;
}
```
\newpage

## Mejora:

Hemos creado la función *elige_preguntas_mejorado* similar a
*elige_preguntas*, pero con la salvedad de que en lugar de elegir el
primer atributo disponible, elige de entre los atributos disponibles
el que divida a la lista de personajes dada como argumento en dos
listas del tamaño más parecido posible. Este sería el atributo con
mayor entropía. De esta forma conseguimos reducir la profundidad media
de las hojas del árbol, y con ello el promedio de preguntas necesarias
para adivinar el personaje.

La función *crear_arbol_mejorado* es igual que la función
*crear_arbol*, salvo por que llama a *elige_preguntas_mejorado*.


```cpp
void QuienEsQuien::elige_preguntas_mejorado(bintree<Pregunta> &a, list<int> pers, list<int> atrib){

  /*Si sólo queda un personaje, se coloca el nombre del personaje */
  if(pers.size() == 1){
    Pregunta pregunta(personajes[pers.front()],1);
    bintree<Pregunta> tree(pregunta);
    a = tree;
  }

  else{

    /* Seleccionar pregunta con mayor entropía entre los atributos y personajes
       dados como argumento, consultando el tablero de juego */
    float objetivo = (float) pers.size()/2;             // Buscamos el atributo que divida en grupos más similares
    int suma, mas_cercano = INT_MAX;            // Número de personajes con el atributo y distancia del mejor atributo al objetivo
    list<int>::iterator it_atrib_max_entrop;    // Iterador al atributo con más entropía
    bool continua = true;                       // Para evitar ciclos innecesarios

  	list<int>::iterator it_p, it_a;

  	for(it_a = atrib.begin(); it_a != atrib.end() && continua; it_a++){
  		for(it_p = pers.begin(), suma = 0; it_p != pers.end(); it_p++)
        suma += tablero[*it_p][*it_a];

      if((int)abs(suma - objetivo) == 0){ // Es el mejor atributo
        it_atrib_max_entrop = it_a;
        continua = false;
      }
      else if((int)abs(suma - objetivo) < mas_cercano){
        mas_cercano = (int)abs(suma - objetivo);
        it_atrib_max_entrop = it_a;
      }
    }

    /*Conocido el atributo con mayor entropía, separamos la lista de personajes dada en dos listas*/
    list<int> si; // Posiciones de los personajes que lo tienen
    list<int> no; // Posiciones de los personajes que no lo tienen

    //Relleno las listas de personajes que tienen o no el atributo con mayor entropía
    for(it_p = pers.begin(); it_p != pers.end(); it_p++){ //Recorro la columna de personajes del atributo
      if(tablero[*it_p][*it_atrib_max_entrop]) //Si el personaje tiene el atributo
        si.push_back(*it_p); //Lo añado a la lista de los que lo tienen
      else //Si no tiene el atributo
        no.push_back(*it_p); //Lo añado a la lista de los que no lo tienen
    }

    /* Asigno la pregunta sobre el primer atributo*/
    Pregunta pregunta(atributos[*it_atrib_max_entrop], pers.size());
    bintree<Pregunta> tree(pregunta);
    a = tree;

    bintree<Pregunta> izda, dcha;

    atrib.erase(it_atrib_max_entrop);

    elige_preguntas_mejorado(izda, si, atrib);
    elige_preguntas_mejorado(dcha, no, atrib);

    a.insert_left(a.root(), izda);
    a.insert_right(a.root(), dcha);
  }
}
```

```cpp
bintree<Pregunta> QuienEsQuien::crear_arbol_mejorado(){

  bintree<Pregunta> tree;

	list<int> pers;
	list<int> atrib;

	int i;

	for(i = 0; i < personajes.size(); i++)
		pers.push_back(i);

	for(i = 0; i < atributos.size(); i++)
		atrib.push_back(i);

  elige_preguntas_mejorado(tree, pers, atrib);

  return tree;
}
```
