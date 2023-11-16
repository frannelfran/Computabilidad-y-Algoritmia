#include "cinta.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 15/11/2023
// Archivo:cinta.cc
// Descripción: Implementación de la clase Cinta

Cinta::Cinta() {} // Constructor por defecto

/**
 * @brief Constructor de la clase Cinta
 * @param file Fichero que contiene las tuplas de la cinta
 * @return Objeto de la clase Cinta
*/

Cinta::Cinta(ifstream& file) {
  int num_tupla, estado_actual, estado_siguiente;
  char simbolo, cambio, direccion;
  file >> num_tupla;
  while (num_tupla != 0) {
    file >> estado_actual; // Leo el estado actual
    file >> simbolo; // Leo el símbolo
    file >> cambio; // Leo la letra por la que hay que cambiar el símbolo
    file >> direccion; // Leo la dirección
    file >> estado_siguiente; // Leo el estado siguiente
    cinta_.insert({estado_actual, make_tuple(simbolo, cambio, direccion, estado_siguiente)}); // Creo la cinta
    alfabeto_.insert(simbolo); // Creo el alfabeto de la cinta
    num_tupla--;
  }
}

/**
 * @brief Función para determinar si los símbolos de la cadena pertencen al alfabeto de la cinta
 * @param cadena Cadena a comprobar
 * @return 1 en caso de verdadero y 0 en caso contrario
*/

bool Cinta::Pertenece(string & cadena) {
  for (char simbolo : cadena) {
    if (!cinta_.count(simbolo)) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Función par obtener la cinta y poder trabajar con ella
 * @return cinta de la máquina
*/

multimap<int, tuple<char, char, char, int>> Cinta::GetCinta() {
  return cinta_;
}

/**
 * @overload Operador <<
*/

ostream& operator<<(ostream& os, Cinta& cint) {
  os << "Alfabeto de la cinta: {";
  for (auto it = cint.alfabeto_.begin(); it != cint.alfabeto_.end(); it++) {
    os << *it;
    if (next(it) != cint.alfabeto_.end()) {
      os << ",";
    }
  }
  os << "}" << endl;
  for (auto it2 = cint.cinta_.begin(); it2 != cint.cinta_.end(); it2++) {
    os << "Estado " << it2->first << " -> ";
    os << get<0>(it2->second);
    os << get<1>(it2->second);
    os << get<2>(it2->second);
    os << " -> " << get<3>(it2->second);
    os << "\n";
  }
  return os;
}