// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 23/10/2025
// Archivo: nfa.h
// Descripción: Declaración de la clase NFA

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