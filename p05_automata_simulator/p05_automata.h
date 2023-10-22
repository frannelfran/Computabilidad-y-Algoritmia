#include <iostream>
#include <fstream>
#include "p05_alfabeto.h"
#include "p05_conjunto_estados.h"
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
// Fecha: 22/10/2023
// Archivo: p05_automata.h
// Descripción: Declaración de la clase autómata

class Automata{
  public:
  Automata(); // Constructor por defecto
  Automata(Alfabeto, ConjuntoDeEstados); // Constructor de la clase automata
  bool EsAceptada(string);
  friend ostream& operator<<(ostream& os, Automata& autom); // Sobrecarga del operador de salida
  private:
  Alfabeto alfabeto_;
  ConjuntoDeEstados conjunto_;
};