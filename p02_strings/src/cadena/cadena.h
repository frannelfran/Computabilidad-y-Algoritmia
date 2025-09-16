#include "../alfabeto/alfabeto.h"
#include <string>
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
    

  private:
    string cadena_;
    const Alfabeto& alfabeto_;
};

#endif