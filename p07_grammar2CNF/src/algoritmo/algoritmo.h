#ifndef ALGORITMO_H
#define ALGORITMO_H

#include "../gramatica/gramatica.h"

class Algoritmo {
  public:
    // Constructor y destructor
    Algoritmo() = default;
    ~Algoritmo() = default;

    // Métodos
    virtual Gramatica ejecutar(const Gramatica& gramatica) = 0;
};

#endif // ALGORITMO_H