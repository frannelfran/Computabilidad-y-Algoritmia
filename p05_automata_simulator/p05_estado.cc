#include "p05_estado.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 16/10/2023
// Archivo p05_estado.h
// Descripción: Implementación de la clase estado

ConjuntoDeEstado::ConjuntoDeEstado() {} // Constructor por defecto de la clase ConjuntoDeEstados

ConjuntoDeEstado::ConjuntoDeEstado(string num_estados) {
  char numero_estado = num_estados[0];
  for(char it = '0'; it < numero_estado; it++) {
    estado_.insert(it); // Insertar los estados que tienen el automata
  }
}

void ConjuntoDeEstado::initial(string inicial) { // Declarar el estado inicial
  char initial_state = inicial[0]; // Convierto el estado inicial a char
  auto it = estado_.find(initial_state); // Buscar el estado en el conjunto
  if(it != estado_.end()) {
    initial_ = initial_state; // Asignar el estado inicial
  }
}

std::ostream& operator<<(std::ostream& os, const ConjuntoDeEstado& estado) {
  for (const auto& elemento : estado.estado_) {
    os << elemento << " ";
  }
  return os;
}