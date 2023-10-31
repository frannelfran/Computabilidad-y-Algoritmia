#include "p07_alfabeto.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramáticas en Forma Normal de Chomsky
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 31/10/2023
// Archivo: p07_producciones.cc
// Descripción: Implementación de la clase Alfabeto

Alfabeto::Alfabeto() {} // Constructor por defecto

/**
 * @brief Constructor de la clase Alfabeto
 * @param file Fichero para leer los simbolos del alfabeto
 * @return Objeto de la clase alfabeto
*/

Alfabeto::Alfabeto(ifstream& file) {
  int num_simbolos;
  char simbolo;
  file >> num_simbolos; // Compruebo el número de símbolos
  while (num_simbolos != 0) {
    file >> simbolo;
    alfabeto_.insert(simbolo); // Inserto los símbolos del alfabeto
    num_simbolos--;
  }
}

/**
 * @brief Sobrecarga del operador de salida
*/

ostream& operator<<(ostream& os, Alfabeto& alf) {
  os << "Alfabeto: {";
  for (auto it = alf.alfabeto_.begin(); it != alf.alfabeto_.end(); it++) {
    os << *it;
    if(next(it) != alf.alfabeto_.end()) {
      os << ",";
    }
  }
  os << "}" << endl;
  return os;
}