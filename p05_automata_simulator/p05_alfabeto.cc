#include "p05_alfabeto.h"

Alfabeto::Alfabeto() {}

/**
 * @brief Constructor de la clase alfabeto.
 * @param file fichero donde solo se lee el alfabeto.
 * @param linea Linea del fichero que contiene los simbolos del alfabeto
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