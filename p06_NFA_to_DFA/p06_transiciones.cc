#include "p06_transiciones.h"

Transiciones::Transiciones() {} // Constructor por defecto

/**
 * @brief Constructor de la clase transiciones
 * @param caracter Indica el caracter necesario para moverse entre los estados
 * @param estado_actual Indica el estado actual
 * @param aceptacion Indica si el estado es de aceptación
*/
Transiciones::Transiciones(char caracter, int estado_siguiente, bool aceptacion) {
  aceptacion_.push_back(aceptacion);
  transiciones_.insert(pair<char, int>(caracter, estado_siguiente));
}
/**
 * @brief Sobrecarga del operador de salida de la clase transiciones
*/

ostream& operator<<(ostream os, const Transiciones& transiciones) {
  os << "Transiciones:" << endl;
  for (const auto& pair : transiciones.transiciones_) {
  os << "  " << pair.first << " -> " << pair.second << endl;
  }

  os << "Estados de aceptación:" << endl;
  for (const bool esAceptado : transiciones.aceptacion_) {
    os << "  " << (esAceptado ? "Sí" : "No") << endl;
  }
  return os;
}