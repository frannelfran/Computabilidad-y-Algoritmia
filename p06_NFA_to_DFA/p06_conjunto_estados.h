#include <iostream>
#include <fstream>
#include <map>
#include "p06_transiciones.h"
#pragma once

using namespace std;

class ConjuntoDeEstados {
  public:
  ConjuntoDeEstados(); // Constructor por defecto
  ConjuntoDeEstados(int, Transiciones); // Constructor de la clase estado
  friend ostream& operator<<(ostream& os, ConjuntoDeEstados& conjunto);
  private:
  map<int, Transiciones> conjunto_de_estados_; // Atributo privado de la clase
};