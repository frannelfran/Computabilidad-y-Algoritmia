// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 23/10/2025
// Archivo: dfa.h
// Descripción: Declaración de la clase DFA

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