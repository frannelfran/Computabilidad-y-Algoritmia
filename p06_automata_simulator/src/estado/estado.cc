// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 23/10/2025
// Archivo: estado.h
// Descripción: Implementación de la clase Estado

#include "estado.h"
#include "../transicion/transicion.h"

/**
 * @brief Agrega una transición al estado
 * @param transicion La transición a agregar
 */
void Estado::agregarTransicion(const Transicion& transicion) {
  transiciones_.push_back(transicion);
}

/**
 * @overload Sobrecarga del operador <<
 */
ostream& operator<<(ostream& os, const Estado& estado) {
  os << "---- Transiciones del estado " << estado.id_ << " ----" << endl;
  for (auto& it : estado.transiciones_) {
    os << it << endl;
  }
  return os;
}