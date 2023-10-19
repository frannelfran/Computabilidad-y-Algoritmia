#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "p05_alfabeto.h"
#include "p05_estado.h"
#pragma once

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 16/10/2023
// Archivo p05_automata.h
// Descripción: Declaración de la clase autómata

class Automata {
  public:
  Automata(Alfabeto, ConjuntoDeEstado); // constructor de la clase
  Automata();
  bool aceptado(string);
  int actual(); // Obtener estado actual
  private: // Atributos privados de la clase
  Alfabeto alfabeto_;
  ConjuntoDeEstado estados_;
  int estado_actual;
};