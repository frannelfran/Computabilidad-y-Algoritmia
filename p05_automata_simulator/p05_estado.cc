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

ConjuntoDeEstado::ConjuntoDeEstado(int estado, Nodo transiciones) {
  estados_[estado] = transiciones; // Creo el conjunto de estados
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
    // Devuelve un estado por defecto o maneja la ausencia del estado según tus necesidades.
    // En este caso, retornaremos un estado vacío.
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
  for (const auto& pair : estado.estados_) {
    os << "Estado " << pair.first << ":\n";
    os << pair.second; // Utiliza la sobrecarga del operador << de la clase Nodo
    os << "\n";
  }
  return os;
}