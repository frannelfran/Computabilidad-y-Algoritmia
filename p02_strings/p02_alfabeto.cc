#include "p02_alfabeto.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_alfabeto.cc
// Descripción: Implementación de la clase alfabeto

Alfabeto::Alfabeto(set<char>& mi_cadena) { // Constructor de la clase
  alfabeto_ = mi_cadena; // Crea el alfabeto
}

ostream& operator<<(ostream& os, const Alfabeto& alf) { // Sobrecarga del operador de salida "<<"
  os << "{";
  for(set<char>::iterator it = alf.alfabeto_.begin(); it != alf.alfabeto_.end(); ++it) { // Recorremos el alfabeto
    if (next(it) == alf.alfabeto_.end()) {
      os << *it;
      break;
    }
    os << *it << ", ";
  }
  os << "}" << endl;
}