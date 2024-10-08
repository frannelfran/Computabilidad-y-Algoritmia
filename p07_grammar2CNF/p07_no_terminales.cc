#include "p07_no_terminales.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramáticas en Forma Normal de Chomsky
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 31/10/2023
// Archivo: p07_no_terminales.cc
// Descripción: Implementación de la clase NoTerminales

NoTerminales::NoTerminales() {} // Constructor por defecto

/**
 * @brief Constructor de la clase NoTerminales
 * @param file Fichero para poder leer los simbolos no terminales
 * @return Objeto de la clase NoTerminales
*/

NoTerminales::NoTerminales(ifstream& file) {
  int num_no_terminales;
  char simbolo_no_terminal;
  file >> num_no_terminales; // Compruebo cuantos símbolos no terminales hay en la gramática
  while (num_no_terminales != 0) {
    file >> simbolo_no_terminal;
    no_terminales_.insert(simbolo_no_terminal); // Inserto los símbolos no terminales
    num_no_terminales--;
  }
}

/**
 * @brief Comprobar que los símbolos introducidos en el fichero pertenezcan al conjunto de no terminales
 * @param simbolo Símbolo a comprobar
 * @return true en caso de verdadero y false en el caso contrario
*/

bool NoTerminales::IsTerminal(char simbolo) {
  if (no_terminales_.count(simbolo)) {
    return true;
  }
  return false;
}

/**
 * @brief Función para insertar un no terminal al conjunto de no terminales
 * @param no_terminal No terminal a insertar en el conjunto
*/

void NoTerminales::Insertar(char no_terminal) {
  no_terminal = toupper(no_terminal); // Convierto el char en mayuscula
  no_terminales_.insert(no_terminal);
}

/**
 * @brief Obtener un no_terminal
 * @return Devuelve un char (Símbolo no terminal)
*/

char NoTerminales::ObtenerNoTerminal() {
  char caracter = 'A';
  while (no_terminales_.find(caracter) != no_terminales_.end()) {
    caracter++;
  }
  return caracter;
}

/**
 * @overload Operador <<
*/

ostream& operator<<(ostream& os, NoTerminales& no_term) {
  os << no_term.no_terminales_.size() << endl;
  for (auto it = no_term.no_terminales_.begin(); it != no_term.no_terminales_.end(); it++) {
    os << *it << endl;
  }
  return os;
}