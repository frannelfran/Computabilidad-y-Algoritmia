// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 23/10/2025
// Archivo: alfabeto.cc
// Descripción: Implementación de la clase Alfabeto

#include "alfabeto.h"

/**
 * @overload Sobrecarga del operador de salida pàra mostrar el alfabeto
 */
ostream& operator<<(ostream& os, const Alfabeto& alfabeto) {
  os << "Σ -> {";
  for (auto it = alfabeto.simbolos_.begin(); it != alfabeto.simbolos_.end(); ++it) {
    os << *it;
    if (next(it) != alfabeto.simbolos_.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}