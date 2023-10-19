#include "p05_alfabeto.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 15/10/2023
// Archivo alfabeto.cc
// Descripción: Implementación de la clase alfabeto

Alfabeto::Alfabeto() {} // Constructor predeterminado de la clase alfabeto

Alfabeto::Alfabeto(string linea) { // Constructor de la clase alfabeto
  for(const char simbolo : linea) { // Ir insertando los símbolos del alfabeto
    if(!isspace(simbolo)) { // Si no tiene espacio, insertar el símbolo
      alfabeto_.insert(simbolo);
    }
  }
}

bool Alfabeto::contiene_alfabeto(char simbolo) { // Verificar que el símbolo está contenido en el alfabeto
  return alfabeto_.find(simbolo) != alfabeto_.end();
}

ostream& operator<<(ostream& os, const Alfabeto& alf) { // Sobrecarga del operador de salida "<<"
  os << "{";
  for(set<char>::iterator it = alf.alfabeto_.begin(); it != alf.alfabeto_.end(); ++it) { // Recorremos el alfabeto
    if (next(it) == alf.alfabeto_.end()) {
      os << *it;
      break;
    }
    os << *it << ", ";
  }
  os << "}";
  return os;
}
