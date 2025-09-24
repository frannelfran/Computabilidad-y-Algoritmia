#pragma once

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Lenguajes
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 24/09/2025
// Archivo: lenguaje.h
// Descripción: Declaración de la clase Lenguaje

#ifndef LENGUAJE_H
#define LENGUAJE_H
#include "../cadena/cadena.h"

class Lenguaje {
  public:
    // Constructor y destructor
    Lenguaje() = default;
    ~Lenguaje() = default;

    // Métodos
    inline void agregar(const Cadena& cadena) { cadenas_.insert(cadena); }

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Lenguaje& lenguaje);

  private:
    set<Cadena> cadenas_;
};

#endif // LENGUAJE_H