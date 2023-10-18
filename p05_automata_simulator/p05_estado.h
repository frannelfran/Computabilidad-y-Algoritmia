#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include "p05_nodo.h"
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
// Archivo p05_estado.h
// Descripción: Declaración de la clase estado

class ConjuntoDeEstado {
  public:
  ConjuntoDeEstado(int, Nodo); // Constructor de la clase
  ConjuntoDeEstado(); // Cosntructor por defecto
  void initial(int, Nodo); // Estado inicial
  friend std::ostream& operator<<(std::ostream& os, const ConjuntoDeEstado& estado);
  
  private:
  map<int, Nodo> estados_;
};