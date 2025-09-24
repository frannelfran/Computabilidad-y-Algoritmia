// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Lenguajes
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 24/09/2025
// Archivo: lenguaje.cc
// Descripción: Implementación de la clase Lenguaje

#include "lenguaje.h"

/**
 * @overload Sobrecarga del operador de salida
 */
ostream& operator<<(ostream& os, const Lenguaje& lenguaje) {
  if (lenguaje.cadenas_.empty()) {
    os << "{}";
    return os;
  } else {
    os << "{";
    for (auto it = lenguaje.cadenas_.begin(); it != lenguaje.cadenas_.end(); ++it) {
      os << *it;
      if (next(it) != lenguaje.cadenas_.end()) {
        os << ", ";
      }
    }
    os << "}";
    return os;
  }
}