#include <iostream>
#include <list>

using namespace std;

template <class T>
Stack:: Stack(): datos(){}

template <class T>
Stack:: Stack(const Stack &original): datos(original.datos){}

template <class T>
Stack& Stack:: operatos=(const Stack& original){
  datos=original.datos;
}

template <class T>
bool Stack:: empty() const{
  return datos.empty();
}

template <class T>
T& Stack:: top(){
  return list.back();
}

template <class T>
const T& Stack:: top () const{
  return list.back();
}

template <class T>
void Stack:: push(const T& n){
  datos.push_back(n);
}

template <class T>
void Stack:: pop(){
  datos.pop_back(n);
}

template <class T>
int Stack:: size() const{
  return datos.size;
}
