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
  void ModificarProducciones(); // Modificar las producciones (1er paso del algoritmo)
  void AgregarProduccion(char, const string&); // Agregar producciones
  friend ostream& operator<<(ostream& os, Producciones& prod); // Sobrecarga del operador de salida
  private:
  Alfabeto alfabeto_;
  NoTerminales no_terminales_;
  map<char, set<string>> producciones_;
};