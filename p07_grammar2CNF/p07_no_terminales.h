#include <iostream>
#include <fstream>
#include <set>
#pragma once

using namespace std;

class NoTerminales {
  public:
  NoTerminales(); // Constructor por defecto
  NoTerminales(ifstream&); // Constructor de la clase
  friend ostream& operator<<(ostream& os, NoTerminales& term); // Sobrecarga del operador de salida
  private:
  set<char> terminales_; // Atributo privado de la clase
};