#pragma once
#include "../automata.h"
#include <stack>

#ifndef NFA_H
#define NFA_H

class NFA : public Automata {
  public:
    // Constructor y destructor
    NFA(const set<Estado*>& estados, const Alfabeto& alfabetoEntrada) : Automata(estados, alfabetoEntrada) {}
    ~NFA() = default;

    // Métodos
    bool ejecutar(string cadena) override;
    vector<Transicion*> obtenerTransiciones(char simboloLeido);
    set<Estado*> epsilonClausura(Estado* estado);
    
};

#endif // NFA_H