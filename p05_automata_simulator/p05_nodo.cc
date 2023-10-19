#include "p05_nodo.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 17/10/2023
// Archivo p05_estado.h
// Descripción: Implementación de la clase nodo

Nodo::Nodo() {} // Constructor por defecto

Nodo::Nodo(char caracter, int siguiente, int aceptance) { // Constructor de la clase Nodo
  aceptacion_ = aceptance;
  transiciones_.insert(pair<char, int>(caracter, siguiente));
}

bool Nodo::aceptacion() { // Ver si el nodo es de aceptación
  if(aceptacion_ == true) {
    return aceptacion_;
  }
  return false;
}

const multimap<char, int>& Nodo::obtenerTransiciones() const { // Obtener las transiciones
  return transiciones_;
}

std::ostream& operator<<(std::ostream& os, const Nodo& nodo) {
  os << "Aceptacion: " << nodo.aceptacion_ << "\n";
  for (const auto& pair : nodo.transiciones_) {
    os << "Clave: " << pair.first << ", Valor: " << pair.second << "\n";
  }
  return os;
}