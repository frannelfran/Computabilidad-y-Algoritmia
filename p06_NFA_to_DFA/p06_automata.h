#include <iostream>
#include <fstream>
#include <queue>
#include "p06_alfabeto.h"
#include "p06_conjunto_estados.h"
#pragma once

using namespace std;

class Automata{
  public:
  Automata(); // Constructor por defecto
  Automata(const Alfabeto&, const ConjuntoDeEstados&); // Constructor de la clase automata
  int obtenerNuevoEstado(); // Obtener un nuevo estado para el DFA
  Automata ConstruirSubconjuntos();
  friend ostream& operator<<(ostream& os, Automata& autom); // Sobrecarga del operador de salida
  private:
  Alfabeto alfabeto_;
  ConjuntoDeEstados conjunto_;
  int ultimoEstadoDFA;
};