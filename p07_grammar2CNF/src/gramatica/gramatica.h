#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "../alfabeto/alfabeto.h"
#include "../produccion/produccion.h"


class Gramatica {
  public:
    // Constructor y destructor
    Gramatica() = default;
    Gramatica(const Alfabeto& alf, const set<Simbolo>& noTerminales, const vector<Produccion>& prods) : alfabeto_(alf), simbolosNoTerminales_(noTerminales), producciones_(prods) {};
    ~Gramatica() = default;

    // Métodos
    inline void agregarProduccion(const Produccion& produccion) { producciones_.push_back(produccion); }

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Gramatica& gramatica);

  private:
    Alfabeto alfabeto_;
    set<Simbolo> simbolosNoTerminales_;
    vector<Produccion> producciones_;
};

#endif // GRAMATICA_H