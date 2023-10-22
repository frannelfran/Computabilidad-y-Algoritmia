#include "p06_transiciones.h"
#include "p06_conjunto_estados.h"

Transiciones::Transiciones() {} // Constructor por defecto

/**
 * @brief Constructor de la clase transiciones
 * @param num_estados Indica el número de estados
 * @param estado_inicial Indica el estado inicial
 * @param estados Va indicando los estados
 * @param transiciones Número de transiciones de cada estado
 * @param siguiente Estado siguiente
 * @return Devuelve un objeto de la clase transiciones
*/
Transiciones::Transiciones(ifstream& file) {
  int num_estados, estado_inicial, estados, transiciones, siguiente;
  bool aceptacion;
  file >> num_estados;
  file >> estado_inicial;
  while(num_estados != 0) {
    file >> estados; // Estado del conjunto
    file >> aceptacion; // Verificar que es de aceptación
    aceptacion_.push_back(aceptacion); // Crear el vector de aceptación
    file >> transiciones;
    while(transiciones != 0) {
      char simbolo;
      file >> simbolo;
      file >> siguiente;
      transiciones_.insert(pair<char, int>(simbolo, siguiente));
      transiciones--;
    }
    num_estados--;
  }
}
/**
 * @brief Sobrecarga del operador de salida
*/
ostream& operator<<(ostream& os, const Transiciones& transiciones) {
  os << "Transiciones:" << endl;
  for (const auto& pair : transiciones.transiciones_) {
    os << "  " << pair.first << " -> " << pair.second << endl;
  }
  os << "Asceptación ? " << endl;
  for (const bool esAceptado : transiciones.aceptacion_) {
    os << (esAceptado ? "Sí" : "No") << endl;
  }
  return os;
}