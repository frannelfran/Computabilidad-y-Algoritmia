#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#pragma once

using namespace std;

class ConjuntoDeEstados {
  public:
  ConjuntoDeEstados(); // Constructor por defecto
  ConjuntoDeEstados(ifstream&); // Constructor de la clase estado
  friend ostream& operator<<(ostream& os, ConjuntoDeEstados& conjunto);

  private:
  multimap<int, map<char, int>> conjunto_de_estados_; // Atributo privado de la clase
  vector<bool> aceptacion_;
};