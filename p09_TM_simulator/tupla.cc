#include "tupla.h"

Tupla::Tupla() {}

Tupla::Tupla(ifstream& file) {
  int num_tupla;
  file >> num_tupla;
  while (num_tupla != 0) {
    char simbolo, cambio, direccion;
    int estado_actual, estado_siguiente;
    file >> estado_actual; // Leo el estado actual
    file >> simbolo; // Leo el símbolo
    file >> cambio; // Leo el símbolo a cambiar por el símbolo leído
    file >> direccion; // Leo la dirección
    file >> estado_siguiente; // Leo el estado siguiente
    tupla_.insert({estado_actual, make_tuple(simbolo, cambio, direccion, estado_siguiente)});
    num_tupla--;
  }
}

ostream& operator<<(ostream& os, Tupla& tuple) {
  for (auto it = tuple.tupla_.begin(); it != tuple.tupla_.end(); it++) {
    os << "Estado: " << it->first << " -> ";
    os << get<0>(it->second) << " ";
    os << get<1>(it->second) << " ";
    os << get<2>(it->second) << " ";
    os << get<3>(it->second) << endl;
  }
  return os;
}