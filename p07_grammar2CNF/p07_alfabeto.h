#include <iostream>
#include <fstream>
#include <set>
#pragma once

using namespace std;

class Alfabeto {
  public:
  Alfabeto(); // Constructor por defecto
  Alfabeto(ifstream&); // Constructor de la clase
  friend ostream& operator<<(ostream& os, Alfabeto& alf); // Sobrecarga del operador de salida
  private:
  set<char> alfabeto_;
};