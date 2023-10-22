#include "p06_conjunto_estados.h"

ConjuntoDeEstados::ConjuntoDeEstados() {} // Constructor por defecto de la clase

/**
 * @brief Constructor de la clase transiciones
 * @param num_estados Indica el número de estados
 * @param estado_inicial Indica el estado inicial
 * @param estados Va indicando los estados
 * @param transiciones Número de transiciones de cada estado
 * @param siguiente Estado siguiente
 * @return Devuelve un objeto de la clase transiciones
*/
ConjuntoDeEstados::ConjuntoDeEstados(ifstream& file) {
  int num_estados, estado_inicial, estados, transiciones, siguiente;
  bool aceptacion;
  file >> num_estados; // Número de estados
  file >> estado_inicial; // Estado inicial
  while(num_estados != 0) {
    file >> estados; // Estado del conjunto
    if(estados == estado_inicial) { // Declarar el estado inicial
      setEstadoInicial(estados);
    }
    file >> aceptacion; // Verificar que es de aceptación
    aceptacion_.push_back(aceptacion);
    file >> transiciones; // Cuantas transiciones tiene cada estado
    while(transiciones != 0) {
      char simbolo;
      file >> simbolo;
      file >> siguiente;
      conjunto_de_estados_[estados].push_back({simbolo, siguiente});
      transiciones--;
    }
    num_estados--;
  }
}

/**
 * @brief Procedimiento que declara el estado inicial del conjunto
 * @param estado_inicial Variable que contiene el estado inicial del conjunto
*/

void ConjuntoDeEstados::setEstadoInicial(int estado_inicial) {
  initial_ = estado_inicial;
}

/**
 * @brief Sobrecarga del operador << para la clase ConjuntoDeEstados
*/
ostream& operator<<(ostream& os, ConjuntoDeEstados& conjunto) {
  os << "Conjunto de estados" << endl;
  for (auto& estado : conjunto.conjunto_de_estados_) {
    os << "Estado: " << estado.first << "\n";
    for (auto& transicion : estado.second) {
      os << "  Entrada: " << transicion.first << " -> Siguiente Estado: " << transicion.second << "\n";
    }
  }

  os << "Estados de Aceptación: ";
  for (size_t i = 0; i < conjunto.aceptacion_.size(); ++i) {
    if (conjunto.aceptacion_[i]) {
      os << i << " ";
    }
  }
  os << "\n";

  return os;
}