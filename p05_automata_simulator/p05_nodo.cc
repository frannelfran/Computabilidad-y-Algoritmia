#include "p05_nodo.h"

Nodo::Nodo() {} // Constructor por defecto

Nodo::Nodo(char caracter, int siguiente, int aceptance) { // Constructor de la clase Nodo
  aceptacion_ = aceptance;
  transiciones_.insert(pair<char, int>(caracter, siguiente));
}

std::ostream& operator<<(std::ostream& os, const Nodo& nodo) {
  os << "Aceptacion: " << nodo.aceptacion_ << "\n";
  os << "Transiciones:\n";
  for (const auto& pair : nodo.transiciones_) {
    os << "Clave: " << pair.first << ", Valor: " << pair.second << "\n";
  }
  return os;
}