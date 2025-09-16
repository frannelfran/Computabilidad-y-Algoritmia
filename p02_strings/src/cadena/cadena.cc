#include "cadena.h"

/**
 * @brief Método para hallar la inversa de una cadena
 * @return Cadena inversa
 */
string Cadena::inversa() const {
  string inversa = cadena_;
  reverse(inversa.begin(), inversa.end());
  return inversa;
}