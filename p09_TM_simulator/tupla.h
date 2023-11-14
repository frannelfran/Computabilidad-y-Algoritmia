#include <iostream>
#include <fstream>
#include <map>
#include <tuple>
#include "estados.h"
#pragma once

using namespace std;

class Tupla {
  public:
  Tupla();
  Tupla(ifstream&); // Constructor de la clase
  friend ostream& operator<<(ostream& os, Tupla& tupla); // Sobrecarga del operador de salida
  private:
  multimap<int, tuple<char, char, char, int>> tupla_;
};