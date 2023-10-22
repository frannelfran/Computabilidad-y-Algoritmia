#include <iostream>
#include <map>
#include <vector>
#pragma once

using namespace std;

class Transiciones {
  public:
  Transiciones (); // Cosntructor por defecto
  Transiciones (char, int, bool); // Constructor de la clase Transiciones
  friend ostream& operator<<(ostream os, const Transiciones& transiciones); 
  private:
  multimap <char, int> transiciones_; // Atributo privado
  vector<bool> aceptacion_; // Almacena si el estado es de aceptación
};
