#include "../cadena/cadena.h"

#ifndef LENGUAJE_H
#define LENGUAJE_H

class Lenguaje {
  public:
    // Constructor y destructor
    Lenguaje() = default;
    ~Lenguaje() = default;

    // Métodos
    inline void agregar(const Cadena& cadena) { cadenas_.insert(cadena); }

  private:
    set<Cadena> cadenas_;
};

#endif // LENGUAJE_H