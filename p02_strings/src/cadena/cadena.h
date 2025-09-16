#include "../alfabeto/alfabeto.h"
#include "../lenguaje/lenguaje.h"
#include <string>
#include <algorithm> // Para reverse
#pragma once

#ifndef CADENA_H
#define CADENA_H

class Cadena {
  public:
    // Constructor y destructor
    Cadena(const string& cadena, const Alfabeto& alfabeto) : cadena_(cadena), alfabeto_(alfabeto) {}
    ~Cadena() = default;

    // Métodos
    inline size_t longitud() const { return cadena_.size(); }
    string inversa() const;
    Lenguaje prefijos() const;
    Lenguaje sufijos() const;

    // Getters
    inline Alfabeto getAlfabeto() const { return alfabeto_; }

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Cadena& cadena);
    inline friend bool operator<(const Cadena& c1, const Cadena& c2) { return c1.cadena_ < c2.cadena_; }

  private:
    string cadena_;
    const Alfabeto alfabeto_;
};

#endif