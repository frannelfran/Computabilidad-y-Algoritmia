#include "dfa.h"

/**
 * @brief Método para ejecutar el DFA con una cadena de entrada
 * @param cadena Cadena de entrada
 * @return true si la cadena es aceptada, false en caso contrario
 */
bool DFA::ejecutar(string cadena) {
  if (!esValida(cadena)) {
    throw invalid_argument("La cadena contiene símbolos no pertenecientes al alfabeto de entrada.");
  }

  while (!cadena.empty()) {
    char simboloLeido = cadena.front();
    
    Transicion* transicion = obtenerTransicion(simboloLeido);

    if (transicion == nullptr) {
      return false; // No hay transición válida
    }

    estadoActual_ = transicion->ejecutar(cadena);
  }

  if (estadoActual_->esAceptacion()) {
    return true; // La cadena es aceptada
  } else {
    return false; // La cadena es rechazada
  }
}

/**
 * @brief Método para obtener la transicion válida desde el estado actual con el símbolo leído
 * @param simboloLeido Símbolo leído de la cadena
 * @return Puntero a la transición válida, o nullptr si no existe
 */
Transicion* DFA::obtenerTransicion(char simboloLeido) {
  Transicion* transicionValida = nullptr;
  for (auto& transicion : estadoActual_->getTransiciones()) {
    if (transicion.getLecturaCadena() == simboloLeido) {
      transicionValida = &transicion;
      break;
    }
  }
  return transicionValida;
}