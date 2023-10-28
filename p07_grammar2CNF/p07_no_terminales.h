#include <iostream>
#include <fstream>
#include <set>
#pragma once

using namespace std;

class NoTerminales {
  public:
  NoTerminales(); // Constructor por defecto
  NoTerminales(ifstream&); // Constructor de la clase
  void Insertar(string); // Insertar no terminales
  void find(string); // Buscar un símbolo no terminal
  friend ostream& operator<<(ostream& os, NoTerminales& term); // Sobrecarga del operador de salida
  private:
  set<string> no_terminales_; // Atributo privado de la clase
};