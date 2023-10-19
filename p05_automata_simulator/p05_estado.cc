#include "p05_estado.h"
#include "p05_nodo.h"

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

ConjuntoDeEstado::ConjuntoDeEstado(ifstream& file) {
  int estado, num_estado, transiciones, inicial, siguiente, aceptacion;
  char caracter;
  file >> num_estado; // Leemos el número de estados
  file >> inicial; // Leemos el nodo inicial
  for(int it = 0; it < num_estado; it++) {
    file >> estado; // Leemos el estado
    file >> aceptacion; // Leemos si es de aceptacion
    file >> transiciones; // Leemos el número de transiciones
    for(int it2 = 0; it2 < transiciones; it2++) {
      file >> caracter;
      file >> siguiente;
      Nodo nodo(caracter, siguiente, aceptacion);
      estados_.insert(pair<int, Nodo>(estado, nodo));
    }
  }
}

void ConjuntoDeEstado::initial(int estado, Nodo transiciones) { // Poner el nodo inicial en el conjunto
  estados_.insert(pair<int, Nodo>(estado, transiciones));
}

Nodo& ConjuntoDeEstado::obtener_estado(int identificador) {
  auto it = estados_.find(identificador);
  if (it != estados_.end()) {
    return it->second;
  }
  else {
    // Devuelve un estado por defecto, en este caso, retornaremos un estado vacío.
    static Nodo estadoVacio;
    return estadoVacio;
  }
}

bool ConjuntoDeEstado::contiene_estado(int estado) { // Saber si el estado esta en el conjunto
  return estados_.find(estado) != estados_.end();
}

bool ConjuntoDeEstado::contieneTransicion(int estadoActual, char simbolo, int& siguiente) const {
  auto it = estados_.find(estadoActual);
  if (it != estados_.end()) {
    const multimap<char, int>& transiciones = it->second.obtenerTransiciones();
    auto itTransicion = transiciones.find(simbolo);
    if (itTransicion != transiciones.end()) {
      siguiente = itTransicion->second;
      return true;
    }
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const ConjuntoDeEstado& estado) {
  os << "Conjunto de Estado:\n";
  for (const auto& par : estado.estados_) {
    os << "Identificador: " << par.first << ", Nodo: " << par.second << "\n";
  }
  return os;
}