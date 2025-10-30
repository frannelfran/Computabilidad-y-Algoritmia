#include "gramatica.h"

/**
 * @overload Sobrecarga del operador de salida para mostrar la gramática
 * @param os Flujo de salida
 * @param gramatica Gramática a mostrar
 * @return Flujo de salida con la gramática formateada
 */
ostream& operator<<(ostream& os, const Gramatica& gramatica) {
  os << gramatica.alfabeto_ << endl;
  os << "V -> ";
  for (const auto& simbolo : gramatica.simbolosNoTerminales_) {
    os << simbolo << " ";
  }
  os << endl;
  os << "P -> " << endl;
  for (const auto& produccion : gramatica.producciones_) {
    os << produccion << endl;
  }
  return os;
}