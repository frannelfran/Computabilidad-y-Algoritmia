#pragma once

#ifndef LENGUAJE_H
#define LENGUAJE_H
#include "../cadena/cadena.h"

class Lenguaje {
  public:
    // Constructor y destructor
    Lenguaje() = default;
    ~Lenguaje() = default;

    // Métodos
    inline void agregar(const Cadena& cadena) { cadenas_.insert(cadena); }

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Lenguaje& lenguaje);

  private:
    set<Cadena> cadenas_;
};

#endif // LENGUAJE_H