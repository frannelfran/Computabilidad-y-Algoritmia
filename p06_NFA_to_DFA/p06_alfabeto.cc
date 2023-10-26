#include "p06_alfabeto.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 26/10/2023
// Archivo: p06alfabeto.cc
// Descripción: Implementación de la clase Alfabeto

Alfabeto::Alfabeto() {}

/**
 * @brief Constructor de la clase alfabeto.
 * @param file fichero donde solo se lee el alfabeto.
 * @return Objeto de la clase Alfabeto
*/

Alfabeto::Alfabeto(ifstream& file) {
  string linea;
  getline(file, linea);
  for(const char simbolo : linea) {
    if(!isspace(simbolo)) {
      alfabeto_.insert(simbolo);
    }
  }
}

/**
 * @brief Función para obetener el alfabeto
 * @return Devuele el objeto de la clase Alfabeto
*/

set<char> Alfabeto::getAlfabeto() {
  return alfabeto_;
}

/**
 *  @brief Sobrecarga del operador << de la clase Alfabeto
*/

ostream& operator<<(ostream& os, const Alfabeto& alfabeto) {
  os << "Alfabeto: ";
  os << "{";
  for(set<char>::iterator it = alfabeto.alfabeto_.begin(); it != alfabeto.alfabeto_.end(); it++) {
    os << *it;
    if (next(it) != alfabeto.alfabeto_.end()) {
      os << ",";
    }
  }
  os << "}" << endl;
  return os;
}