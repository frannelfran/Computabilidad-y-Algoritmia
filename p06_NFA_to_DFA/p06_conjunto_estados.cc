#include "p06_conjunto_estados.h"

ConjuntoDeEstados::ConjuntoDeEstados() {} // Constructor por defecto de la clase

/**
 * @brief Constructor de la clase transiciones
 * @param file Fichero que contiene la información del autómata
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
      file >> simbolo; // Almacena el simbolo para transitar
      file >> siguiente; // Almacena el estado_siguiente
      conjunto_de_estados_[estados].push_back({simbolo, siguiente}); // Inserta los estados con sus transiciones
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
 * @brief Función para obtener el estado inicial del conjunto
 * @return Devuelve el estado inicial
*/

int ConjuntoDeEstados::getEstadoInicial() {
  return initial_;
}

/**
 * @brief Función para saber si un estado es de aceptación
 * @param estado Estado que se quiere comprobar
 * @return Devuelve 1 si es de aceptación y 0 si ocurre lo contrario
*/

bool ConjuntoDeEstados::esEstadoAceptacion(int estado) {
  // Verifica si el estado está en el vector de estados de aceptación
  for (int aceptacion : aceptacion_) {
    if (estado == aceptacion) {
      return true; // El estado es un estado de aceptación
    }
  }
  return false; // El estado no es un estado de aceptación
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