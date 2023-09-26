#include "p02_alfabeto.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_alfabeto.cc
// Descripción: Implementación de la clase alfabeto

Alfabeto::Alfabeto(std::set<char>& mi_alfabeto) {
  alfabeto_ = mi_alfabeto;
}