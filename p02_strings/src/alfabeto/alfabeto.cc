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