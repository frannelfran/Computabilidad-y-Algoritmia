#include "produccion.h"

/**
 * @overload Sobrecarga del operador de salida para mostrar la producción
 * @param os Flujo de salida
 * @param produccion Producción a mostrar
 * @return Flujo de salida con la producción formateada
 */
ostream& operator<<(ostream& os, const Produccion& produccion) {
  os << produccion.simboloIzquierda << " -> ";
  for (size_t i = 0; i < produccion.simbolosDerecha.size(); ++i) {
    for (const auto& simbolo : produccion.simbolosDerecha[i]) {
      os << simbolo;
    }
    if (i < produccion.simbolosDerecha.size() - 1) {
      os << " | ";
    }
  }
  return os;
}