#include <iostream>
#include "estados.h"
#include "tupla.h"
#pragma once

class TM {
  public:
  TM();
  TM(Tupla&); // Constructor de la clase
  friend ostream& operator<<(ostream& os, TM& tm);
  private:
  Tupla tupla_;
};