#include <iostream>
#include <fstream>
#include <queue>
#include "p06_alfabeto.h"
#include "p06_conjunto_estados.h"
#pragma once

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 26/10/2023
// Archivo: p06_automata.h
// Descripción: Declaración de la clase Automata

class Automata{
  public:
  Automata(); // Constructor por defecto
  Automata(const Alfabeto&, const ConjuntoDeEstados&); // Constructor de la clase automata
  int obtenerNuevoEstado(); // Obtener un nuevo estado para el DFA
  Automata ConstruirSubconjuntos();
  friend ostream& operator<<(ostream& os, Automata& autom); // Sobrecarga del operador de salida
  private:
  Alfabeto alfabeto_;
  ConjuntoDeEstados conjunto_;
  int ultimoEstadoDFA{0};
};