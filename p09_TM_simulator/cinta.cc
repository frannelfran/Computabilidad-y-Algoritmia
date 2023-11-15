#include "cinta.h"

Cinta::Cinta() {} // Constructor por defecto

Cinta::Cinta(ifstream& file) {
  int num_tupla, estado_actual, estado_siguiente;
  char simbolo, cambio, direccion;
  file >> num_tupla;
  while (num_tupla != 0) {
    file >> estado_actual; // Leo el estado actual
    file >> simbolo; // Leo el símbolo
    file >> cambio; // Leo la letra por la que hay que cambiar el símbolo
    file >> direccion; // Leo la dirección
    file >> estado_siguiente; // Leo el estado siguiente
    cinta_.insert({estado_actual, make_tuple(simbolo, cambio, direccion, estado_siguiente)}); // Creo la cinta
    alfabeto_.insert(simbolo); // Creo el alfabeto de la cinta
    num_tupla--;
  }
}


set<char> Cinta::GetAlfabeto() {
  return alfabeto_;
}

ostream& operator<<(ostream& os, Cinta& cint) {
  os << "Alfabeto de la cinta: {";
  for (auto it = cint.alfabeto_.begin(); it != cint.alfabeto_.end(); it++) {
    os << *it;
    if (next(it) != cint.alfabeto_.end()) {
      os << ",";
    }
  }
  os << "}" << endl;
  for (auto it2 = cint.cinta_.begin(); it2 != cint.cinta_.end(); it2++) {
    os << "Estado " << it2->first << " -> ";
    os << get<0>(it2->second);
    os << get<1>(it2->second);
    os << get<2>(it2->second);
    os << get<3>(it2->second);
    os << "\n";
  }
  return os;
}