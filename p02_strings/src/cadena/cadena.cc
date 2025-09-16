#include "../lenguaje/lenguaje.h"
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
  // Agrego la cadena vacía
  lenguaje.agregar(Cadena("&", alfabeto_));
  string prefijo = "";
  for (int i = 0; i < cadena_.size(); ++i) {
    prefijo += cadena_[i];
    lenguaje.agregar(Cadena(prefijo, alfabeto_));
  }
  return lenguaje;
}

/**
 * @brief Método para hallar los sufijos de una cadena
 * @return Lenguaje con los sufijos de la cadena
 */
Lenguaje Cadena::sufijos() const {
  Lenguaje lenguaje;
  // Agrego la cadena vacía
  lenguaje.agregar(Cadena("&", alfabeto_));
  for (size_t i = 0; i < cadena_.size(); ++i) {
    string sufijo = cadena_.substr(i);
    lenguaje.agregar(Cadena(sufijo, alfabeto_));
  }
  return lenguaje;
}

/**
 * @overload Sobrecarga del operador <
 * @param c1 Cadena 1
 * @param c2 Cadena 2
 * @return true si c1 < c2, false en caso contrario
 */
bool operator<(const Cadena& c1, const Cadena& c2) {
  if (c1.cadena_.size() != c2.cadena_.size())
    return c1.cadena_.size() < c2.cadena_.size();
  return c1.cadena_ < c2.cadena_;
}

/**
 * @overload Sobrecarga del operador de salida
 */
ostream& operator<<(ostream& os, const Cadena& cadena) {
  os << cadena.cadena_;
  return os;
}