#include "p06_conjunto_estados.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 26/10/2023
// Archivo: p06_conjunto_estados.cc
// Descripción: Implementación de la clase ConjuntoDeEstados

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
 * @brief Función para obtener las transiciones desde un estado con un símbolo
 * @param estado Estado al que le quieres mirar las transiciones
 * @param simbolo Simbolo necesario para poder hacer las transiciones de ese estado
 * @return Transiciones del estado
*/

set<int> ConjuntoDeEstados::obtenerTransiciones(set<int> estado, char simbolo) {
  set<int> estadosAlcanzables;
  // Recorre cada estado del conjunto y obtén las transiciones para cada uno
  for(int estadoIndividual : estado) {
    if(conjunto_de_estados_.count(estadoIndividual) > 0) {
      const vector<pair<char, int>>& transiciones = conjunto_de_estados_[estadoIndividual];
      for (const pair<char, int>& transicion : transiciones) {
        if (transicion.first == simbolo) {
          estadosAlcanzables.insert(transicion.second);
        }
      }
    }
  }
  return estadosAlcanzables;
}

void ConjuntoDeEstados::agregarTransiciones(set<int> estadosOrigen, int estadoDestino, char simbolo) {
  for (int estadoOrigen : estadosOrigen) {
    if (conjunto_de_estados_.find(estadoOrigen) != conjunto_de_estados_.end()) {
      conjunto_de_estados_[estadoOrigen].push_back({simbolo, estadoDestino});
    }
    else {
      vector<pair<char, int>> transiciones = {{simbolo, estadoDestino}};
      conjunto_de_estados_[estadoOrigen] = transiciones;
    }
  }
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