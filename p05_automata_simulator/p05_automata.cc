#include "p05_alfabeto.h"
#include "p05_estado.h"
#include "p05_automata.h"
#include "p05_nodo.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 16/10/2023
// Archivo p05_automata.cc
// Descripción: Implementación de la clase autómata

Automata::Automata() {} // Cosntructor por defecto

Automata::Automata(Alfabeto mi_alfabeto, ConjuntoDeEstado mis_estados) {
  alfabeto_ = mi_alfabeto;
  estados_ = mis_estados;
}