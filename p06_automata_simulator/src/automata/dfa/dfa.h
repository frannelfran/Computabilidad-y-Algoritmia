#pragma once
#include "../automata/automata.h"

#ifndef DFA_H
#define DFA_H

class DFA : public Automata {
  public:
    // Constructor y destructor
    DFA(const set<Estado*>& estados, const Alfabeto& alfabetoEntrada);
    ~DFA() = default;

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const DFA& dfa);

    // Métodos
    bool ejecutar(string cadena) override;
    Transicion* obtenerTransicion(char simboloLeido) const;
};