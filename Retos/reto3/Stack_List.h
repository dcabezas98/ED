/*
  Clase Pila implementada a partir de las funciones de la clase List de
  la stl.

  David Cabezas Berrido
  Patricia Córdoba Hidalgo
*/

#ifndef __Stack_List__
#define __Stack_List__

#include <list>

template <class T>
class Stack{

  private:

  std::list<T> datos;

  public:

  Stack();

  Stack(const Stack&);

  Stack& operator=(const Stack&);

  bool empty() const;

  T& top();

  const T& top() const;

  void push(const T&);

  void pop();

  int size() const;
};

#include "Stack_List.cpp"

#endif
