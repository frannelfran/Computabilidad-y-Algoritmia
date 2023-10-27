#include "p07_terminales.h"

Terminales::Terminales() {} // Constructor por defecto

/**
 * @brief Constructor de la clase Terminales
 * @param file Fichero para poder leer los simbolos terminales
 * @return Objeto de la clase Terminales
*/

Terminales::Terminales(ifstream& file) {
  int num_terminales;
  char simbolo_terminal;
  file >> num_terminales; // Compruebo cuantos símbolos terminales hay
  while (num_terminales != 0) {
    file >> simbolo_terminal;
    terminales_.insert(simbolo_terminal); // Inserto los símbolos terminales
    num_terminales--;
  }
}

/**
 * @brief Sobrecarga del operador de salida
*/

ostream& operator<<(ostream& os, Terminales& term) {
  os << "Símbolos terminales: ";
  for(auto it = term.terminales_.begin(); it != term.terminales_.end(); it++) {
    os << *it;
    if(next(it) != term.terminales_.end()) {
      os << " ";
    }
  }
  os << endl;
  return os;
}