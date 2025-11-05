// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 05/11/2025
// Archivo: algoritmo.h
// Descripción: Declaración de la clase Algoritmo

#ifndef ALGORITMO_H
#define ALGORITMO_H

#include "../gramatica/gramatica.h"

class Algoritmo {
  public:
    // Constructor y destructor
    Algoritmo() = default;
    ~Algoritmo() = default;

    // Métodos
    virtual Gramatica ejecutar(const Gramatica& gramatica) = 0;
};

#endif // ALGORITMO_H