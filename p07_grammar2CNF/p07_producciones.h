#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "p07_alfabeto.h"
#include "p07_terminales.h"
#pragma once

using namespace std;

class Producciones {
  public:
  Producciones(); // Constructor por defecto
  Producciones(ifstream&, Alfabeto, Terminales); // Constructor de la clase
  friend ostream& operator<<(ostream& os, Producciones& prod); // Sobrecarga del operador de salida
  private:
  Alfabeto alfabeto_;
  Terminales terminales_;
  map<char, vector<string>> producciones_;
};