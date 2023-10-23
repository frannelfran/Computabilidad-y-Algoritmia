#include "p06_afd.h"

AFD::AFD() {} // Constructor por defecto de la clase AFD

AFD::AFD(Alfabeto mi_alfabeto, ConjuntoDeEstados mi_conjunto) {
  alfabeto_ = mi_alfabeto;
  conjunto_ = mi_conjunto;
  ConstruirSubconjuntos();
}

void AFD::ConstruirSubconjuntos() {
  queue<set<int>> cola;
  map<set<int>, bool> visitados;
  set<int> estado_inicial_conjunto = {conjunto_.getEstadoInicial()};
  estado_inicial_afd_ = estado_inicial_conjunto;
  cola.push(estado_inicial_conjunto);
  while(!cola.empty()) {
    set<int> estado_actual = cola.front();
    cola.pop();
    for(char simbolo : alfabeto_.getAlfabeto()) {
      set<int> estado_siguiente;
      for(int estado : estado_actual) {
        // Obtén el conjunto de estados alcanzables desde el estado actual con el símbolo dado.
        // Agrega estos estados a estado_siguiente.
      }
      if(!estado_siguiente.empty()) {
        transiciones_afd_[make_pair(estado_actual, simbolo)] = estado_siguiente;
      }
      if(!estados_afd_.count(estado_siguiente)) {
        estados_afd_.insert(estado_siguiente);
        cola.push(estado_siguiente);
      }
    }
  }
}

ostream& operator<<(ostream& os, AFD& afd) {
os << "Alfabeto: "; // Imprime el alfabeto
  // Imprime el contenido del alfabeto (debe definirse en la clase Alfabeto)
  os << afd.alfabeto_;
  os << "Conjunto de Estados del AFD:" << endl;
  // Imprime los estados del AFD
  for (const set<int>& estado : afd.estados_afd_) {
    os << "{ ";
    for (int estado_id : estado) {
      os << estado_id << " ";
    }
    os << "}" << endl;
  }
  // Imprime las transiciones del AFD
  os << "Transiciones del AFD:" << endl;
  for (const auto& entrada_transicion : afd.transiciones_afd_) {
    set<int> estado_actual = entrada_transicion.first.first;
    char simbolo = entrada_transicion.first.second;
    set<int> estado_siguiente = entrada_transicion.second;
    os << "Desde { ";
    for (int estado_id : estado_actual) {
      os << estado_id << " ";
    }
    os << "} con '" << simbolo << "' a { ";
    for (int estado_id : estado_siguiente) {
      os << estado_id << " ";
    }
    os << "}" << endl;
  }
  // Imprime los estados de aceptación
  os << "Estados de Aceptación del AFD:" << endl;
  for (const set<int>& estado_aceptacion : afd.estados_aceptacion_afd_) {
    os << "{ ";
    for (int estado_id : estado_aceptacion) {
      os << estado_id << " ";
    }
    os << "}" << endl;
  }
  // Imprime el estado inicial
  // os << "Estado Inicial del AFD: { " << afd.estado_inicial_afd_ << " }" << endl;
  return os;
}