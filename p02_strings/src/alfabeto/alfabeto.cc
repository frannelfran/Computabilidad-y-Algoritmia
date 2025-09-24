// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Lenguajes
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 24/09/2025
// Archivo: alfabeto.cc
// Descripción: Implementación de la clase Alfabeto

#include "alfabeto.h"

/**
 * @brief Constructor de la clase Alfabeto
 * @param alfabeto Cadena de caracteres que representa el alfabeto
 */
Alfabeto::Alfabeto(const string& alfabeto) {
  for (const char& caracter : alfabeto) {
    simbolos_.insert(caracter);
  }
}

/**
 * @overload Sobrecarga del operador de salida
 */
ostream& operator<<(ostream& os, const Alfabeto& alfabeto) {
  os << "{";
  for (auto it = alfabeto.simbolos_.begin(); it != alfabeto.simbolos_.end(); ++it) {
    os << *it;
    if (next(it) != alfabeto.simbolos_.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}