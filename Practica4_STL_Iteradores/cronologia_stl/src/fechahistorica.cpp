#include <iostream>
#include <pair>
#include <set>
#include <string>
#include "fechahistorica.h"

using namespace std;

iterator FechaHistorica::begin(){
  return pareja.second.begin();
}

const_iterator FechaHistorica::begin() const{
  return pareja.second.cbegin();
}

iterator FechaHistorica::end(){
  return pareja.second.end();
}

const_iterator FechaHistorica::end() const{
  return pareja.second.cend();
}

FechaHistorica::FechaHistorica() {
  pareja.first = 0;
}

FechaHistorica::FechaHistorica(int n){
  pareja.first = n;
}

FechaHistorica::FechaHistorica(const FechaHistorica &original) {
  pareja.first = original.pareja.first;
  pareja.second = original.pareja.second;
}

void FechaHistorica::destruir(){
  pareja.second.clear();
}

bool FechaHistorica::empty(){
  return pareja.second.empty();
}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &original){

  if(&original != this){
    pareja.first = original.pareja.first;
    pareja.second = original.pareja.second;
  }
  return *this;
}

int FechaHistorica::nhechos() const {
  return pareja.second.size();
}

const int FechaHistorica::year() const {
  return pareja.first;
}

int& FechaHistorica::year(){
  return pareja.first;
}

void FechaHistorica::add(string h) {
  pareja.second.insert(h);
}

FechaHistorica& FechaHistorica::operator+=(const FechaHistorica &nuevo){

  if(&nuevo != this) {
    assert(anio == nuevo.anio);

    for(auto it = nuevo.pareja.second.cbegin(); it != nuevo.pareja.second.cend(); it++)
      pareja.second.insert(*it);
  }
  return *this;
}

ostream& operator<<(ostream &flujo, const FechaHistorica &fecha){

  flujo << fecha.pareja.first;
  for (auto it = fecha.pareja.second.cbegin(); it != nuevo.pareja.second.cend(); it++)
    flujo << "#" << *it;

  return flujo;
}

istream& operator>>(istream &flujo, FechaHistorica &fecha){

  fecha.destruir();

  string s;

  getline(flujo, s, '#');

  fecha.year() = stoi(s);

  while(flujo.good()){
    s = "";
    getline(flujo, s, '#');
    fecha.aniade(s);
  }

  return flujo;
}
