#include <iostream>
#include <set>
#include <string>
#include "cinta.h"
#pragma once

class TM {
  public:
  TM();
  TM(Cinta&, set<int>, set<int>, int); // Constructor de la clase
  void Funcionamiento(string&); // Funcionamiento de la máquina
  friend ostream& operator<<(ostream& os, TM& tm);
  private:
  Cinta cinta_; // Cinta de la máquina
  set<int> estados_; // Estados de la máquina
  set<int> aceptacion_; // Estados de aceptación de la máquina
  int inicial_; // Estado inicial
};