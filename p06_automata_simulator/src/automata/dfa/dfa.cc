// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 23/10/2025
// Archivo: dfa.h
// Descripción: Implementación de la clase DFA

#include "dfa.h"

/**
 * @brief Método para ejecutar el DFA con una cadena de entrada
 * @param cadena Cadena de entrada
 * @return true si la cadena es aceptada, false en caso contrario
 */
bool DFA::ejecutar(string cadena) {
  if (!esValida(cadena)) {
    return false;
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