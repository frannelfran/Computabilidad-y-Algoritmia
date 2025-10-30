#ifndef PRODUCCION_H
#define PRODUCCION_H

#include "../simbolo/simbolo.h"
#include <vector>

class Produccion {
  public:
  // Constructor y destructor
  Produccion() = default;
  Produccion(const Simbolo& izq) : simboloIzquierda(izq) {};
  ~Produccion() = default;

  // Métodos
  inline void agregarsimboloDerecha(const vector<Simbolo>& simbolos) { simbolosDerecha.push_back(simbolos); }
  
  // Sobrecarga de operadores
  friend ostream& operator<<(ostream& os, const Produccion& produccion);
  
  private:
    Simbolo simboloIzquierda;
    vector<vector<Simbolo>> simbolosDerecha;
};

#endif // PRODUCCION_H