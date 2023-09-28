#include "p02_lenguaje.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_lenguaje.cc
// Descripción: Implementación de la clase lenguaje

Lenguaje::Lenguaje(set<string>& mi_lenguaje) { // Constructor de la clase lenguaje
  lenguaje_ = mi_lenguaje;
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& leng) {
  os << "{";
  for(set<string>::iterator it = leng.lenguaje_.begin(); it != leng.lenguaje_.end(); it++) { // Recorremos el lenguaje
    if(next(it) == leng.lenguaje_.end()) {
      os << *it;
      break;
    }
    os << *it << ", "; // Imprimimos los elementos del lenguaje
  }
  os << "}";
  return os;
}