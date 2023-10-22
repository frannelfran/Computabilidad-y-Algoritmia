#include "p06_automata.h"

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
bool Automata::EsAceptada(const string& cadena) const {
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