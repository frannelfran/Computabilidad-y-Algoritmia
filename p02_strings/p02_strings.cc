#include "p02_strings.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_cadena.cc
// Decripción: Implementación de la clase cadena

Cadena::Cadena(const string mi_cadena) { // Constructor de la clase
  for (const char letra : mi_cadena) {
    cadena_.push_back(letra);
    alfabeto_.insert(letra);
  }
}

void Cadena::alfabeto() {
  cout << "{";
  for(set<char>::iterator it = alfabeto_.begin(); it != alfabeto_.end(); ++it) {
    if (next(it) == alfabeto_.end()) {
      cout << *it;
      break;
    }
    cout << *it << ", ";
  }
  cout << "}" << endl;
}