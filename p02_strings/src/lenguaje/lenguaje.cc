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