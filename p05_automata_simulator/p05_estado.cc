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

Estado::Estado(ifstream& mi_estado) {
  string linea;
  getline(mi_estado, linea); // Leer la segunda línea del fichero
  int numero_estado = stoi(linea);
  for(int it = 0; it < numero_estado; it++) {
    estado_.insert(it); // Insertar los estados que tienen el automata
  }
}

int Estado::initial(ifstream& inicial) {
  string linea;
  getline(inicial, linea);
  int initial_state = stoi(linea); // Convierto el estado inicial en entero
  auto it = estado_.find(initial_state); // Buscar el estado en el conjunto
  if(it != estado_.end()) {
    initial_state = *it; // Asignar el estado inicial
  }
  return initial_state;
}

std::ostream& operator<<(std::ostream& os, const Estado& estado) {
  for (const auto& elemento : estado.estado_) {
    os << elemento << " ";
  }
  return os;
}