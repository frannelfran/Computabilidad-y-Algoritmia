#include "p07_producciones.h"

Producciones::Producciones() {} // Contructor por defecto de la clase

/**
 * @brief Constructor de la clase Producciones
 * @param file Fichero para leer las producciones de la gramática
 * @param alfabeto Alfabeto de la gramática
 * @param no_terminales Símbolos no terminales que tiene la gramática
 * @return Devuelve un objeto de la clase terminal
*/

Producciones::Producciones(ifstream& file, Alfabeto alfabeto, NoTerminales no_terminales) {
  int num_producciones;
  char term; // símbolo terminal
  string derivaciones; // Derivaciones de cada símbolo
  alfabeto_ = alfabeto;
  no_terminales_ = no_terminales;
  file >> num_producciones;
  while (num_producciones != 0) {
    file >> term;
    file >> derivaciones;
    producciones_[term].push_back(derivaciones);
    num_producciones--;
  }
}

ostream& operator<<(ostream& os, Producciones& prod) {
  os << "Producciones de la gramática" << endl;
  for (auto it = prod.producciones_.begin(); it != prod.producciones_.end(); it++) {
    os << it->first << " → ";
    for (const string& production : it->second) {
      os << production;
      if (production != it->second.back()) {
        os << " | ";
      }
    }
    os << endl;
  }
  return os;
}