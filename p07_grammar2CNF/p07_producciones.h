#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "p07_alfabeto.h"
#include "p07_no_terminales.h"
#pragma once

using namespace std;

class Producciones {
  public:
  Producciones(); // Constructor por defecto
  Producciones(ifstream&, Alfabeto, NoTerminales); // Constructor de la clase
  friend ostream& operator<<(ostream& os, Producciones& prod); // Sobrecarga del operador de salida
  private:
  Alfabeto alfabeto_;
  NoTerminales no_terminales_;
  map<char, vector<string>> producciones_;
};