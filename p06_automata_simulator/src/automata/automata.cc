#include "automata.h"

/**
 * @brief Constructor de la clase Automata
 * @param estados Conjunto de estados del autómata
 * @param alfabetoEntrada Alfabeto de entrada del autómata
 */
Automata::Automata(const set<Estado*>& estados, const Alfabeto& alfabetoEntrada) {
  estados_ = estados;
  alfabetoEntrada_ = alfabetoEntrada;

  // Inicializo el estado actual al estado inicial
  for (Estado* estado : estados_) {
    if (estado->esInicial()) {
      estadoActual_ = estado;
      break;
    }
  }
}

/**
 * @brief Método para reiniciar el autómata a su estado inicial
 * @return void
 */
void Automata::reiniciar() {
  // Reinicio el estado actual al estado inicial
  for (Estado* estado : estados_) {
    if (estado->esInicial()) {
      estadoActual_ = estado;
      break;
    }
  }
}

/**
 * @brief Método para comprobar si una cadena es válida para el autómata
 * @param cadena Cadena de entrada
 * @return true si la cadena es válida, false en caso contrario
 */
bool Automata::esValida(const string& cadena) const {
  for (char simbolo : cadena) {
    if (!alfabetoEntrada_.pertenece(simbolo) && simbolo != '&') {
      return false;
    }
  }
  return true;
}

/**
 * @overload Sobrecarga del operador << para mostrar el autómata
 */
ostream& operator<<(ostream& os, const Automata& Automata) {
  os << "Q -> {";
  for (auto it = Automata.estados_.begin(); it != Automata.estados_.end(); ++it) {
    os << (*it)->getId();
    if (next(it) != Automata.estados_.end()) {
      os << ", ";
    }
  }
  os << "}" << endl;
  os << Automata.alfabetoEntrada_ << endl;
  os << "q0 -> " << Automata.estadoActual_->getId() << endl;
  os << "F -> {";
  for (Estado* estado : Automata.estados_) {
    if (estado->esAceptacion()) {
      os << estado->getId();
      // Comrpuebo si es el ultimo estado del conjunto de aceptación
      bool esUltimo = true;
      for (Estado* e : Automata.estados_) {
        if (e->esAceptacion() && e->getId() > estado->getId()) {
          esUltimo = false;
          break;
        }
      }
      if (esUltimo) {
        os << "}" << endl;
        break;
      } else {
        os << ", "; // Si no es el último, añado una coma
      }
    }
  }
  
  // Transiciones
  for (Estado* estado : Automata.estados_) {
    os << *estado << endl;
  }
  return os;
}