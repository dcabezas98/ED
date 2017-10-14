#ifndef _VECTORDINAMICO_
#define _VECTORDINAMICO_

#include "vectordinamico.cpp"

template <class T>

class VectorDinamico{

 private:
  
  int utilizados;
  int reservados;
  T *datos;

  void resize(int n);

 public:

  VectorDinamico();
  
  VectorDinamico(int n);
  
  VectorDinamico(const VectorDinamico &original);
  
  VectorDinamico& operator=(const VectorDinamico &original);
  
  ~VectorDinamico();
  
  int reservados();

  int utilizados();

  T& operator[](int i);

  const T& operator[](int i) const;
    
  void insertar(int i, T elemento);

  void aniade(T elemento);

  void elimina(int i);
  
};

#endif
  
  
