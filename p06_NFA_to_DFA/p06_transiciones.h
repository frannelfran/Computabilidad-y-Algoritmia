#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#pragma once

using namespace std;

class Transiciones {
  public:
  Transiciones(); // Cosntructor por defecto
  Transiciones(ifstream&); // Constructor de la clase Transiciones
  friend std::ostream& operator<<(ostream& os, const Transiciones& transiciones); 
  private:
  multimap <char, int> transiciones_; // Atributo privado
  vector<bool> aceptacion_; // Almacena si el estado es de aceptación
};