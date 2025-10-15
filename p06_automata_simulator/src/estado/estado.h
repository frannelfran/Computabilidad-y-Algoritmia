#pragma once
#include <iostream>
#include <vector>
#include "../transicion/transicion.h" // Incluir primero Transicion

#ifndef ESTADO_H
#define ESTADO_H

using namespace std;

/**
 * @class Estado
 * @brief Clase que representa un estado en un autómata
 */
class Estado {
  public:
    // Constructor y destructor
    Estado() = default;
    Estado(const int& id, const bool& inicial = false) : id_(id), inicial_(inicial) {}

    // Getters
    inline int getId() const { return id_; }
    inline bool esInicial() const { return inicial_; }
    inline vector<Transicion>& getTransiciones() { return transiciones_; }

    // Setters
    inline void setInicial() { inicial_ = true; }
    inline void setAceptacion() { aceptacion_ = true; }

    // Métodos
    void agregarTransicion(const Transicion& transicion);

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Estado& estado);

  private:
    int id_;
    vector<Transicion> transiciones_;
    bool inicial_;
    bool aceptacion_ = false; // Por defecto, un estado no es de aceptación
};

#endif // ESTADO_H