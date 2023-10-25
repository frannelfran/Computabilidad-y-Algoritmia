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

/**
 * @brief Función para obtener un nuevo estado
 * @return Un nuevo estado
*/

int Automata::obtenerNuevoEstado() {
  return ultimoEstadoDFA++;
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
    int estadoActual = estadosPorProcesar.front();
    estadosPorProcesar.pop();

    // Obtener el conjunto de estados alcanzable desde estadoActual con cada símbolo del alfabeto
    map<char, set<int>> conjuntoDeEstadosAlcanzable;
    for(char simbolo : alfabeto) {
      set<int> estadosAlcanzables = ConjuntoDeEstados.obtenerTransiciones(estadoActual, simbolo);
      conjuntoDeEstadosAlcanzable[simbolo] = estadosAlcanzables;
    }
    // Agregar el conjunto de estados alcanzables al DFA si aún no se ha visitado
    for(const auto& entrada : conjuntoDeEstadosAlcanzable) {
      set<int> nuevoEstadoDFA = entrada.second;
      if(!estadosDFAVisitados.count(nuevoEstadoDFA)) { // Verifica que no se ha visitado
        estadosPorProcesar.push(nuevoEstadoDFA);
        estadosDFAVisitados.insert(nuevoEstadoDFA);
        int nuevoEstadoDFA = dfa.obtenerNuevoEstado();
      }
      dfa.conjunto_.agregarTransiciones(estadoActual, mapeoEstados[nuevoEstadoDFA], entrada.first);
    }
  }
  return dfa;
}

/**
 * @brief Sobrecarga del operador << de la clase Automata
*/

ostream& operator<<(ostream& os, Automata& autom) {
  os << autom.alfabeto_;
  os << autom.conjunto_;
  return os;
}