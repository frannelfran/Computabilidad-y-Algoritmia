#include "alfabeto.h"

/**
 * @brief Constructor de la clase Alfabeto
 * @param alfabeto Cadena de caracteres que representa el alfabeto
 */
Alfabeto::Alfabeto(const string& alfabeto) {
  for (const char& caracter : alfabeto) {
    simbolos.insert(caracter);
  }
}

/**
 * @overload Sobrecarga del operador de salida
 */
ostream& operator<<(ostream& os, const Alfabeto& alfabeto) {
  os << "{";
  for (auto it = alfabeto.simbolos.begin(); it != alfabeto.simbolos.end(); ++it) {
    os << *it;
    if (next(it) != alfabeto.simbolos.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}