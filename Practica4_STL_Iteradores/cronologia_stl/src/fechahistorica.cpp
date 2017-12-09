#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <cassert>
#include "fechahistorica.h"

using namespace std;

FechaHistorica::iterator FechaHistorica::begin(){
  return pareja.second.begin();
}

FechaHistorica::const_iterator FechaHistorica::begin() const{
  return pareja.second.cbegin();
}

FechaHistorica::iterator FechaHistorica::end(){
  return pareja.second.end();
}

FechaHistorica::const_iterator FechaHistorica::end() const{
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
    assert(pareja.first == nuevo.pareja.first);

    for(auto it = nuevo.pareja.second.cbegin(); it != nuevo.pareja.second.cend(); it++)
      pareja.second.insert(*it);
  }
  return *this;
}

ostream& operator<<(ostream &flujo, const FechaHistorica &fecha){

  flujo << fecha.year();
  for (auto it = fecha.begin(); it != fecha.end(); it++)
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
    fecha.add(s);
  }

  return flujo;
}
