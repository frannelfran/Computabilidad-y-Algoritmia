#include "p06_automata.h"

Automata::Automata() {} // Constructor por defecto

/**
 * @brief Constructor de la clase Automata
 * @param mi_alfabeto Objeto de la clase Alfabeto
 * @param mi_conjunto Objeto de la clase Conjunto
 * @return Objeto de la clase Automata
*/

Automata::Automata(Alfabeto mi_alfabeto, ConjuntoDeEstados mi_conjunto) {
  alfabeto_ = mi_alfabeto;
  conjunto_ = mi_conjunto;
}

Automata Automata::ConstruirSubconjuntos() {
  set<char> alfabeto = alfabeto_.getAlfabeto(); // Obtener el alfabeto
  ConjuntoDeEstados ConjuntoDeEstados = conjunto_; // Obtener el conjunto de estados

  // Inicializar el DFA
  Automata dfa;
  Alfabeto nuevoAlfabeto;
  int estadoInicial = ConjuntoDeEstados.getEstadoInicial();
  dfa.conjunto_.setEstadoInicial(estadoInicial);

  // Creo una cola para ir procesando los estados
  queue<int> estadosPorProcesar;
  estadosPorProcesar.push(estadoInicial);
  set<set<int>> estadosDFAVisitados; // Conjunto de estados visitados
  map<set<int>, int> mapeoEstados; // Mapa que asocia conjuntos de estados del NFA con estados del DFA

  while(!estadosPorProcesar.empty()) {
    int estadoActual =estadosPorProcesar.front();
    estadosPorProcesar.pop();

    // Obtener el conjunto de estados alcanzable desde estadoActual con cada símbolo del alfabeto
    map<char, set<int>> conjuntoDeEstadosAlcanzable;
    for(char simbolo : alfabeto) {
      set<int> estadosAlcanzable;

    }
  }
}

/**
 * @brief Sobrecarga del operador << de la clase Automata
*/

ostream& operator<<(ostream& os, Automata& autom) {
  os << autom.alfabeto_;
  os << autom.conjunto_;
  return os;
}