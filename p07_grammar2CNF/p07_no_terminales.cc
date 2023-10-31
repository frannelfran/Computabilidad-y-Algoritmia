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
    no_terminales_.insert(simbolo_no_terminal); // Inserto los símbolos no terminales
    num_no_terminales--;
  }
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
  string no_terminal = "ABCDEFGAHJKLMNOPQRSTUVWXYZ";
  for(int it = 0; it < no_terminal.length(); it++) {
    if(no_terminales_.find(no_terminal[it]) == no_terminales_.end()) {
      return no_terminal[it];
    }
  }
  exit(EXIT_FAILURE);
}

/**
 * @brief Sobrecarga del operador de salida
*/

ostream& operator<<(ostream& os, NoTerminales& no_term) {
  os << "Símbolos terminales: ";
  for(auto it = no_term.no_terminales_.begin(); it != no_term.no_terminales_.end(); it++) {
    os << *it;
    if(next(it) != no_term.no_terminales_.end()) {
      os << " ";
    }
  }
  os << endl;
  return os;
}