#include "nfa.h"

/**
 * @brief Ejecuta el autómata NFA con la cadena de entrada dada
 * @param cadena Cadena de entrada
 * @return true si la cadena es aceptada, false en caso contrario
 */
bool NFA::ejecutar(string cadena) {
  if (!esValida(cadena)) {
    return false;
  }

  // Caso base: Cadena vacía
  if (cadena.empty()) {
    set<Estado*> estadosEpsilon = epsilonClausura(estadoActual_);
    for (Estado* estado : estadosEpsilon) {
      if (estado->esAceptacion()) {
        return true;
      }
    }
  }
  
  // Miro las transiciones posibles con el símbolo actual
  vector<Transicion*> transicionesPosibles = obtenerTransiciones(cadena[0]);

  // Si no hay transiciones posibles, rechaza
  if (transicionesPosibles.empty()) {
    return false;
  }

  for (Transicion* transicion : transicionesPosibles) {
    Estado* estadoAnterior = estadoActual_;
    string cadenaAnterior = cadena;

    estadoActual_ = transicion->ejecutar(cadena);

    // Llamada recursiva
    if (ejecutar(cadena)) {
      return true; // Se encontro un camino
    }

    // Backtracking
    estadoActual_ = estadoAnterior;
    cadena = cadenaAnterior;
  }
  return false;
}

/**
 * @brief Método para obtener los estados alcanzables mediante transiciones con el símbolo leído
 * @param estado Estado actual
 * @return Conjunto de estados alcanzables
 */
set<Estado*> NFA::epsilonClausura(Estado* estado) {
  set<Estado*> visitados;
  stack<Estado*> pila;

  pila.push(estado);
  visitados.insert(estado);

  while (!pila.empty()) {
    Estado* actual = pila.top();
    pila.pop();

    for (auto& transicion : actual->getTransiciones()) {
      if (transicion.getLecturaCadena() == '&') {
        string epsilon = "&";
        Estado* destino = transicion.ejecutar(epsilon);
        if (!visitados.count(destino)) {
          visitados.insert(destino);
          pila.push(destino);
        }
      }
    }
  }
  return visitados;
}


vector<Transicion*> NFA::obtenerTransiciones(char simboloLeido) {
  vector<Transicion*> transicionesPosibles;
  for (auto& transicion : estadoActual_->getTransiciones()) {
    if (transicion.getLecturaCadena() == simboloLeido || transicion.getLecturaCadena() == '&') {
      transicionesPosibles.push_back(&transicion);
    }
  }
  return transicionesPosibles;
}