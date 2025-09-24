
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Lenguajes
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 24/09/2025
// Archivo: alfabeto.h
// Descripción: Declaración de la clase Alfabeto

#pragma once
#include <iostream>
#include <fstream>
#include <set>

#ifndef ALFABETO_H
#define ALFABETO_H

using namespace std;

class Alfabeto {
  public:
    // Constructor y destructor
    Alfabeto(const string& alfabeto);
    ~Alfabeto() = default;

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Alfabeto& alfabeto);
  private:
    set<char> simbolos_;
};

#endif // ALFABETO_H