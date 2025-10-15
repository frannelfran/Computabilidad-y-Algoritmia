#include "transicion.h"
#include "../estado/estado.h"

/**
 * @brief Constructor de la clase Transicion
 * @param id Identificador de la transición
 * @param lecturaCadena Símbolo que se lee de la cadena de entrada
 * @param siguiente Puntero al estado siguiente
 */
Transicion::Transicion(const int& id, const char& lecturaCadena, Estado* actual, Estado* siguiente) {
  id_ = id;
  lecturaCadena_ = lecturaCadena;
  siguiente_ = siguiente;
  actual_ = actual;
}

/**
 * @brief Ejecuta la transicion, modificando lo que hay en la pila
 * @param cadena Cadena de entrada
 * @return Estado siguiente al que se transita
 */
Estado* Transicion::ejecutar(string& cadena) {
  if (lecturaCadena_ == '&') { // Transición epsilon
    return siguiente_;
  } else {
    cadena.erase(0, 1); // Elimino el primer carácter de la cadena
    return siguiente_;
  }
  return nullptr;
}

/**
 * @overload Sobrecarga del operador de salida para imprimir una transición
 */
ostream& operator<<(ostream& os, const Transicion& transicion) {
  os << "δ(" << transicion.actual_->getId() << ", " << transicion.lecturaCadena_ << ") -> " << transicion.siguiente_->getId();
  return os;
}