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

Alfabeto::Alfabeto(ifstream& file) { // Constructor de la clase alfabeto
  string mi_alfabeto;
  getline(file, mi_alfabeto);
  for(const char simbolo : mi_alfabeto) { // Ir insertando los símbolos del alfabeto
    if(!isspace(simbolo)) { // Si no tiene espacio, insertar el símbolo
      alfabeto_.insert(simbolo);
    }
  }
}

bool Alfabeto::contiene_alfabeto(char simbolo) { // Verificar que el símbolo está contenido en el alfabeto
  return alfabeto_.find(simbolo) != alfabeto_.end();
}

std::ostream& operator<<(std::ostream& os, const Alfabeto& alf) {
  os << "Alfabeto: { ";
  for (char c : alf.alfabeto_) {
    os << c << ' ';
  }
  os << "}\n";
  return os;
}
