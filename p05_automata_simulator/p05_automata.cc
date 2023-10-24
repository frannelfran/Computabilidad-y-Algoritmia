#include "p05_automata.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 22/10/2023
// Archivo: p05_automata.cc
// Descripción: Implementación de la clase autómata

Automata::Automata() {} // Constructor por defecto

/**
 * @brief Constructor de la clase Automata
 * @param mi_alfabeto Objeto de la clase Alfabeto
 * @param mi_conjunto Objeto de la clase Conjunto
 * @return Objeto de la clase Automata
*/

Automata::Automata(Alfabeto mi_alfabeto, ConjuntoDeEstados mi_conjunto) {
  alfabeto_ = mi_alfabeto;
  conjunto_ = mi_conjunto;
}

/**
 * @brief Función que dice si la cadena que se le pasa por parámetro es aceptada por el autómata
 * @param cadena String que contiene la cadena del fichero
 * @return Devuelve 1 si es aceptada y 0 si es rechazada
*/

bool Automata::EsAceptada(string cadena) {
  return conjunto_.AceptaCadena(cadena);
}

/**
 * @brief Sobrecarga del operador << de la clase Automata
*/

ostream& operator<<(ostream& os, Automata& autom) {
  os << autom.alfabeto_;
  os << autom.conjunto_;
  return os;
}