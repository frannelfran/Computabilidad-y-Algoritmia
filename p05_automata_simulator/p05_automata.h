#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 16/10/2023
// Archivo p05_automata.h
// Descripción: Declaración de la clase autómata

class Automata {
  public:
  Automata(ifstream&); // constructor de la clase

  private: // Atributos privados de la clase
  multimap<char, vector<string>> automata_;
};