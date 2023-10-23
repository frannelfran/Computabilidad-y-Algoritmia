#include "p06_afd.h"

AFD::AFD() {} // Constructor por defecto de la clase AFD

AFD::AFD(Alfabeto mi_alfabeto, ConjuntoDeEstados mi_conjunto) {
  alfabeto_ = mi_alfabeto;
  conjunto_ = mi_conjunto;
  ConstruirSubconjuntos();
}

void AFD::ConstruirSubconjuntos() {
  cout << "SOPA";
}