#include <iostream>
#include <list>

using namespace std;

template <class T>
Stack<T>:: Stack(): datos(){}

template <class T>
Stack<T>:: Stack(const Stack &original): datos(original.datos){}

template <class T>
Stack<T>& Stack<T>:: operator=(const Stack& original){
  datos=original.datos;
}

template <class T>
bool Stack<T>:: empty() const{
  return datos.empty();
}

template <class T>
T& Stack<T>:: top(){
  return datos.back();
}

template <class T>
const T& Stack<T>:: top () const{
  return datos.back();
}

template <class T>
void Stack<T>:: push(const T& n){
  datos.push_back(n);
}

template <class T>
void Stack<T>:: pop(){
  datos.pop_back();
}

template <class T>
int Stack<T>:: size() const{
  return datos.size;
}
