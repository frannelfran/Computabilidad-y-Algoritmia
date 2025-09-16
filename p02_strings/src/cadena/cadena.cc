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

/**
 * @brief Método para hallar los prefijos de una cadena
 * @return Lenguaje con los prefijos de la cadena
 */
Lenguaje Cadena::prefijos() const {
  Lenguaje lenguaje;
  for (size_t i = 0; i <= cadena_.size(); ++i) {
    lenguaje.agregar(Cadena(cadena_.substr(0, i), alfabeto_));
  }
  return lenguaje;
}

/**
 * @brief Método para hallar los sufijos de una cadena
 * @return Lenguaje con los sufijos de la cadena
 */
Lenguaje Cadena::sufijos() const {
  Lenguaje lenguaje;
  for (size_t i = 0; i <= cadena_.size(); ++i) {
    lenguaje.agregar(Cadena(cadena_.substr(i), alfabeto_));
  }
  return lenguaje;
}