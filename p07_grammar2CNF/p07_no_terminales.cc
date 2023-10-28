#include "p07_no_terminales.h"

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
    terminales_.insert(simbolo_no_terminal); // Inserto los símbolos no terminales
    num_no_terminales--;
  }
}

/**
 * @brief Sobrecarga del operador de salida
*/

ostream& operator<<(ostream& os, NoTerminales& no_term) {
  os << "Símbolos terminales: ";
  for(auto it = no_term.terminales_.begin(); it != no_term.terminales_.end(); it++) {
    os << *it;
    if(next(it) != no_term.terminales_.end()) {
      os << " ";
    }
  }
  os << endl;
  return os;
}