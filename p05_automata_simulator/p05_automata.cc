#include "p05_alfabeto.h"
#include "p05_estado.h"
#include "p05_automata.h"

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

Automata::Automata(ifstream& file) {
  string linea, num_estados, est_inicial, estados;
  getline(file, linea);
  Alfabeto alf(linea); // Creo el alfabeto
  alfabeto_ = alf; // Asigno el alfabeto al atributo privado de la clase
  file >> num_estados;
  char estado, aceptacion, transiciones;

}