#include "turing.h"

TM::TM() {} // Constructor por defecto

TM::TM(Cinta& mi_cinta, set<int> estados, set<int> aceptacion, int inicial) {
  this->cinta_ = mi_cinta; // Cinta de la máquina
  this->estados_ = estados; // estados de la máquina
  this->aceptacion_ = aceptacion; // Estados de aceptación de la máquina
  this->inicial_ = inicial; // Estado inicial de la máquina
  SetLenguaje(cinta_);
}

void TM::SetLenguaje(Cinta& mi_cinta) {
  set<char> alfabeto = mi_cinta.GetAlfabeto();
  for (auto it = alfabeto.begin(); it != alfabeto.end(); it++) {
    if (islower(*it)) {
      lenguaje_.insert(*it);
    }
  }
}

ostream& operator<<(ostream& os, TM& tm) {
  os << "Estados de la máquina: ";
  for (auto it = tm.estados_.begin(); it != tm.estados_.end(); it++) {
    os << *it;
    if (next(it) != tm.estados_.end()) {
      os << ",";
    }
  }
  os << "\n";
  os << "Estados de aceptación: ";
  for (auto it = tm.aceptacion_.begin(); it != tm.aceptacion_.end(); it++) {
    os << *it;
    if (next(it) != tm.aceptacion_.end()) {
      os << ",";
    }
  }
  os << "\n";
  os << "Lenguaje aceptado por la máquina: {";
  for (auto it = tm.lenguaje_.begin(); it != tm.lenguaje_.end(); it ++) {
    os << *it;
    if (next(it) != tm.lenguaje_.end()) {
      os << ",";
    }
  }
  os << "}\n";
  os << tm.cinta_;
  return os;
}