#include <iostream>
#include <fstream>
#include "p06_alfabeto.h"
#include "p06_conjunto_estados.h"
#pragma once

using namespace std;

class Automata{
  public:
  Automata(); // Constructor por defecto
  Automata(Alfabeto, ConjuntoDeEstados); // Constructor de la clase automata
  bool EsAceptada(const string&) const;
  friend ostream& operator<<(ostream& os, Automata& autom); // Sobrecarga del operador de salida
  private:
  Alfabeto alfabeto_;
  ConjuntoDeEstados conjunto_;
};