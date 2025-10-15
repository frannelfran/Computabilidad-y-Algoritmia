#pragma once
#include "../alfabeto/alfabeto.h"
#include "../transicion/transicion.h"
#include "../estado/estado.h"
#include <vector> // Para std::vector
#include <algorithm> // Para sort

#ifndef Automata_H
#define Automata_H

/**
 * @class Automata
 * @brief Clase que representa un autómata
 */
class Automata {
  public:
    // Constructor y destructor
    Automata(const vector<Estado*>& estados, const Alfabeto& alfabetoEntrada, const Alfabeto& alfabetoCinta, int numCintas);
    ~Automata() = default;

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Automata& maquina);

    // Métodos
    bool ejecutar(string cadena);
    bool esValida(const string& cadena) const;
    void reiniciar();
    void mostrarTraza(const string& cadena, const Transicion* transicion);
    Transicion* obtenerTransicionPosible(vector<char> simbolosLeidos);

  private:
    vector<Estado*> estados_;
    Alfabeto alfabetoEntrada_;
    Estado* estadoActual_;
};

#endif // Automata_H