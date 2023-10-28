#include <iostream>
#include <fstream>
#include <set>
#pragma once

using namespace std;

class Terminales {
  public:
  Terminales(); // Constructor por defecto
  Terminales(ifstream&); // Constructor de la clase
  friend ostream& operator<<(ostream& os, Terminales& term); // Sobrecarga del operador de salida
  private:
  set<char> terminales_; // Atributo privado de la clase
};