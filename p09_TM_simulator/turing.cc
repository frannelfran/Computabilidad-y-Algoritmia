#include "estados.h"
#include "tupla.h"
#include "turing.h"

TM::TM() {} // Constructor por defecto

TM::TM(Tupla& mi_tupla) { // constructor de la clase TM
  tupla_ = mi_tupla;
}

ostream& operator<<(ostream& os, TM& tm) {
  os << tm.tupla_;
  return os;
}