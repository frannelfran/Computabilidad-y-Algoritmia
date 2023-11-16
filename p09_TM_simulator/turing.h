#include <iostream>
#include <set>
#include <string>
#include "cinta.h"
#pragma once

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 15/11/2023
// Archivo:turing.h
// Descripción: Declaración de la clase TM

class TM {
  public:
  TM();
  TM(Cinta&, set<int>, set<int>, int); // Constructor de la clase
  void Funcionamiento(string&); // Funcionamiento de la máquina
  friend ostream& operator<<(ostream& os, TM& tm); // Sobrecarga del operador <<
  private:
  Cinta cinta_; // Cinta de la máquina
  set<int> estados_; // Estados de la máquina
  set<int> aceptacion_; // Estados de aceptación de la máquina
  int inicial_; // Estado inicial
};