#ifndef FNC_H
#define FNC_H

#include "../algoritmo.h"

class FNC : public Algoritmo {
  public:
    Gramatica ejecutar(const Gramatica& gramatica) override;

  private:
    void sustituirTerminalesEnProducciones(Gramatica& gramatica);
};

#endif // FNC_H