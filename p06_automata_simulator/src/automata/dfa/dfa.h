#pragma once
#include "../automata.h"

#ifndef DFA_H
#define DFA_H

class DFA : public Automata {
  public:
    // Constructor y destructor
    DFA(const set<Estado*>& estados, const Alfabeto& alfabetoEntrada) : Automata(estados, alfabetoEntrada) {}
    ~DFA() = default;

    // Métodos
    bool ejecutar(string cadena) override;
    Transicion* obtenerTransicion(char simboloLeido);
};

#endif // DFA_H