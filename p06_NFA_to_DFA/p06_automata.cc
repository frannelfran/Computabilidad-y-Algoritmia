#include "p06_automata.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 26/10/2023
// Archivo: p06_automata.cc
// Descripción: Implementación de la clase Automata

Automata::Automata() {} // Constructor por defecto

/**
 * @brief Constructor de la clase Automata
 * @param mi_alfabeto Objeto de la clase Alfabeto
 * @param mi_conjunto Objeto de la clase Conjunto
 * @return Objeto de la clase Automata
*/

Automata::Automata(const Alfabeto& mi_alfabeto, const ConjuntoDeEstados& mi_conjunto) {
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

/**
 * @brief Algoritmo de construcción de subconjuntos
 * @return Devuelve un objeto de la clase autómata (DFA)
*/

Automata Automata::ConstruirSubconjuntos() {
  set<char> alfabeto = alfabeto_.getAlfabeto(); // Obtener el alfabeto
  ConjuntoDeEstados ConjuntoDeEstados = conjunto_; // Obtener el conjunto de estados

  // Inicializar el DFA
  Automata dfa;
  Alfabeto nuevoAlfabeto;
  int estadoInicial = ConjuntoDeEstados.getEstadoInicial();
  dfa.conjunto_.setEstadoInicial(estadoInicial);

  // Creo una cola para ir procesando los estados
  queue<set<int>> estadosPorProcesar;
  estadosPorProcesar.push({estadoInicial});
  set<set<int>> estadosDFAVisitados; // Conjunto de estados visitados
  map<set<int>, int> mapeoEstados; // Mapa que asocia conjuntos de estados del NFA con estados del DFA

  while(!estadosPorProcesar.empty()) {
    set<int> conjuntoActual = estadosPorProcesar.front();
    estadosPorProcesar.pop();

    // Obtener el conjunto de estados alcanzable desde conjuntoActual con cada símbolo del alfabeto
    map<char, set<int>> conjuntoDeEstadosAlcanzable;
    for(char simbolo : alfabeto) {
      set<int> estadosAlcanzables = ConjuntoDeEstados.obtenerTransiciones(conjuntoActual, simbolo);
      conjuntoDeEstadosAlcanzable[simbolo] = estadosAlcanzables;
    }
    // Agregar el conjunto de estados alcanzables al DFA si aún no se ha visitado
    for(const auto& entrada : conjuntoDeEstadosAlcanzable) {
      set<int> nuevoEstadoDFA = entrada.second;
      if(!estadosDFAVisitados.count(nuevoEstadoDFA)) { // Verifica que no se ha visitado
        estadosPorProcesar.push(nuevoEstadoDFA);
        estadosDFAVisitados.insert(nuevoEstadoDFA);
        // Obtener un nuevo estado para el DFA
        int nuevoEstadoDFANum = obtenerNuevoEstado();
        // Mapear el conjutno de estados del NFA al DFA
        mapeoEstados[nuevoEstadoDFA] = nuevoEstadoDFANum;
        // agregar transiciones al DFA
        dfa.conjunto_.agregarTransiciones(conjuntoActual, nuevoEstadoDFANum, entrada.first);
      }
      else {
        // si el conjunto de estados ya se visitó, solo agregamos transiciones
        dfa.conjunto_.agregarTransiciones(conjuntoActual, mapeoEstados[nuevoEstadoDFA], entrada.first);
      }
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