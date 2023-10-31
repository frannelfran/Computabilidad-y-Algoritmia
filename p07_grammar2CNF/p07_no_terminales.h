#include <iostream>
#include <fstream>
#include <set>
#include <cctype>
#pragma once

using namespace std;

class NoTerminales {
  public:
  NoTerminales(); // Constructor por defecto
  NoTerminales(ifstream&); // Constructor de la clase
  void Insertar(char); // Insertar no terminales
  char ObtenerNoTerminal(); // Obtener un no_terminal
  friend ostream& operator<<(ostream& os, NoTerminales& term); // Sobrecarga del operador de salida
  private:
  set<char> no_terminales_; // Atributo privado de la clase
};