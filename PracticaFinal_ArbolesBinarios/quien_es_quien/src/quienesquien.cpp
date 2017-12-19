#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

QuienEsQuien::QuienEsQuien(): personajes(), atributos(),
 															tablero(), arbol(), jugada_actual(){}
}

QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien):personajes(quienEsQuien.personaje),
                                                             atributos(quienEsQuien.atributos),
                                                             tablero(quienEsQuien.tablero),
                                                             arbol(quienEsQuien.arbol),
                                                             jugada_actual(quienEsQuien.jugada_actual){}

QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	personajes = quienEsQuien.personajes;
	atributos = quienEsQuien.atributos;
	tablero = quienEsQuien.tablero;
	arbol = quienEsQuien.arbol;
	jugada_actual = quienEsQuien.jugada_actual;
	return *this;
}

QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	personajes.clear();
	atributos.clear();
	tablero.clear();
	arbol.clear();
	jugada_actual.remove();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}
}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  *
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();

  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");

    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}

    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;

	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));

	    		assert(valor == "0" || valor == "1");

	    		bool valor_atributo = valor == "1";

	    		atributos_personaje.push_back(valor_atributo);

	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			  }

			  string nombre_personaje = linea;

	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}

	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un número a un vector de bool que corresponde
  *        con su representación en binario con un numero de digitos
  *        fijo.
  *
  * @param n Número a convertir en binario.
  * @param digitos Número de dígitos de la representación binaria.
  *
  * @return Vector de booleanos con la representación en binario de @e n
  *      con el número de elementos especificado por @e digitos.
  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

bintree<Pregunta> QuienEsQuien::crear_arbol(list<int> &pers, list<int> &atrib){

    /*Si sólo queda un personaje, se coloca el nombre del personaje */
    if(pers.size() == 1){
      Pregunta pregunta(personajes[pers.front()],1);
      bintree<Pregunta> arbol(pregunta);

      return arbol;
    }

    list<int> si; // Posiciones de los personajes que tienen el primer atributo de la lista
    list<int> no; // Posiciones de los personajes que no tienen el primer atributo de la lista
    list<int>:: iterator it_p;

    //Relleno las listas de personajes que tienen o no el atributo con mayor entropía
    for(it_p = pers.begin(), it_p != pers.end(), it_p++){ //Recorro la columna de personajes del atributo
      if(tablero[*it_p][atrib.front()]) //Si el personaje tiene el atributo
        si.push_back(*it_p); //Lo añado a la lista de los que lo tienen
      else //Si no tiene el atributo
        no.push_back(*it_p); //Lo añado a la lista de los que no lo tienen
    }

    /* Asigno la pregunta sobre el primer atributo*/
    Pregunta pregunta(atributos[atrib.front()], pers.size());

    bintree<Pregunta> arbol(pregunta); // La pongo en la raíz

    atrib.pop_front();

    /* A la izquierda, busco la siguiente pregunta para los que tienen este atributo */
    arbol.insert_left(arbol.root(),crear_arbol(si, atrib));
    /* A la derecha, busco la siguiente pregunta para los que no lo tienen */
    arbol.insert_right(arbol.root(),crear_arbol(no, atrib));

    return arbol;
}

bintree<Pregunta> QuienEsQuien::crear_arbol_mejorado(list<int> &pers, list<int> &atrib){

  /*Si sólo queda un personaje, se coloca el nombre del personaje */
  if(pers.size() == 1){
    Pregunta pregunta(personajes[pers.front()],1);
    bintree<Pregunta> arbol(pregunta);

    return arbol;
  }

  /* Seleccionar pregunta con mayor entropía entre los atributos y personajes
     dados como argumento, consultando el tablero de juego */
  float objetivo = pers.size()/2;             // Buscamos el atributo que divida en grupos más similares
  int suma, mas_cercano = INT_MAX;            // Número de personajes con el atributo y distancia del mejor atributo al objetivo
  list<int>::iterator it_atrib_max_entrop;  // Iterador al atributo con más entropía
  bool continua = true;                       // Para evitar ciclos innecesarios

	list<int>::iterator it_p, it_a;

	for(it_a = atrib.begin(); it_a != atrib.end() && continua; it_a++){
		for(it_p = pers.begin(), suma = 0 && continua; it_p != pers.end(); it_p++)
      suma += tablero[*it_p][*it_a];

    if((int)abs(suma - objetivo) == 0){ // Es el mejor atributo
      it_atrib_max_entrop = it_a;
      continua = false;
    }
    else if((int)abs(suma - objerivo) < mas_cercano){
      mas_cercano = (int)abs(suma - objetivo);
      it_atrib_max_entrop = it_a;
    }
  }

  /*Conocido el atributo con mayor entropía, separamos la lista de personajes dada en dos listas*/
  list<int> si; // Posiciones de los personajes que lo tienen
  list<int> no; // Posiciones de los personajes que no lo tienen

  //Relleno las listas de personajes que tienen o no el atributo con mayor entropía
  for(it_p = pers.begin(), it_p != pers.end(), it_p++){ //Recorro la columna de personajes del atributo
    if(tablero[*it_p][*it_atrib_max_entrop]) //Si el personaje tiene el atributo
      si.push_back(*it_p); //Lo añado a la lista de los que lo tienen
    else //Si no tiene el atributo
      no.push_back(*it_p); //Lo añado a la lista de los que no lo tienen
  }

  /* Asigno la pregunta sobre el atributo con más entropía */
  Pregunta pregunta(atributos[*it_atrib_max_entrop], pers.size());

  bintree<Pregunta> arbol(pregunta); // La pongo en la raíz

  atrib.erase(it_atrib_max_entrop); // La próxima vez eligiré el atributo con más entropía entre el resto

  /* A la izquierda, busco la mejor pregunta para los que tienen este atributo */
  arbol.insert_left(arbol.root(),crear_arbol_mejorado(si, atrib));
  /* A la derecha, busco la mejor pregunta para los que no lo tienen */
  arbol.insert_right(arbol.root(),crear_arbol_mejorado(no, atrib));

  return arbol;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
  jugada_actual=arbol.root();
  bool answer;

  while((*jugada_actual).es_pregunta()){
    cout << *jugada_actual;
    cin >> answer;

    if(answer)
      jugada_actual = jugada_actual.left();
    else
      jugada_actual = jugada_actual.right();
  }

  cout<< *jugada_actual;
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	set<string> personajes_levantados;

  bintree<Pregunta> rama;
  rama.assign_subtree(arbol, jugada_actual);

  bintree<Pregunta>::const_preorder_iterator it;

  for(it = rama.begin_preorder(); it = rama.end_preorder(), it++){
    if((*it).es_personaje())
      personajes_levantados.insert((*it).obtener_personaje());
  }

	return personajes_levantados;
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a,
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes(){

	bintree<Pregunta>::preorder_iterator it;
  bintree<Pregunta>:: node *p;
  enum lado {dcha, izq};
  bintree<Pregunta> rama;

  lado l;

  for(it = arbol.begin_preorder(); it != arbol.end_preorder(); it++){
    if(p!=NULL){
      if(lado==dcha){
        arbol.prune_right((*p), rama);
        arbol.insert_left((*p).parent(), rama);
      } else{
        arbol.prune_left((*p), rama);
        arbol.inset_right((*p).parent(), rama);
      }
      p=NULL;
    }

    if((*it).right().null() && !(*it).left().null()){
      p = it;
      l = lado.izq;
    } else if (!(*it).right().null() && (*it).left().null()){
      p = it;
      l = lado.dcha;
    }
  }
}

int QuienEsQuien::profundidad(bintree<Pregunta>::node nodo){
  bintree<Pregunta>::node *p = &nodo;
  int prof = 0;

  while(!(*p).parent().null()){
    p = &(*p).parent();
    prof++;
  }

  return prof;
}

float QuienEsQuien::profundidad_promedio_hojas(){
  int suma=0;
  bintree<Pregunta>::const_preorder_iterator it;

  for(it = arbol.begin_preorder(); it = arbol.end_preorder(), it++){
    if((*(*it)).es_personaje()){
      suma += profundidad(*it);
    }
  }
	return (float)suma/personajes.size();
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petición para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atributo_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}

int QuienEsQuien::size_personajes() const{
  return personajes.size();
}

int QuienEsQuien::size_atributos() const{
  return atributos.size();
}

void QuienEsQuien::preguntas_formuladas(bintree<Pregunta>::node jugada){

  bintree<Pregunta>::node p = jugada;

  cout << "El personaje oculto tiene las siguientes características:\n";

  while(!p.parent().null()){

    cout << (*p.parent()).obtener_pregunta() << ": ";

    if(p == p.parent().left())
      cout << "Sí\n";

    else
      cout << "No\n";
  }

  cout << "pero aún no sé cuál es.\n";
}

void QuienEsQuien::elimina_personaje(string nombre){

  bintree<Pregunta>::postorder_iterator it;
  bintree<Pregunta>::node *p;
  bool encontrado = false;

  for(it = arbol.begin_postorder(); it != arbol.end_postorder() && !encontrado; it++){
    if((*(*it)).es_personaje() && (*(*it)).obtener_personaje() == nombre){
      encontrado = true;
      p = it;
    }
  }

  if(encontrado){
    p->remove();
    eliminar_nodos_redundantes();
  }
}
