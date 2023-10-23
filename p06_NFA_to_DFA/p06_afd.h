#include <iostream>
#include <set>
#include <map>
#include <queue>
#include "p06_alfabeto.h"
#include "p06_conjunto_estados.h"
#pragma once

using namespace std;

class AFD {
  public:
  AFD(); // Constructor por defecto
  AFD(Alfabeto, ConjuntoDeEstados); // Constructor de la clase AFD
  void ConstruirSubconjuntos(); // Construir los subconjuntos
  friend ostream& operator<<(ostream& os, AFD& afd); // Sobrecarga del operadro de salida
  private:
  Alfabeto alfabeto_;
  ConjuntoDeEstados conjunto_;
  set<set<int>> estados_afd_;
  map<pair<set<int>, char>, set<int>> transiciones_afd_;
  set<set<int>> estados_aceptacion_afd_;
  set<int> estado_inicial_afd_;
};