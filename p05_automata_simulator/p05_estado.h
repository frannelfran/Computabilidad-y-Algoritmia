#include <iostream>
#include <set>
#include <string>
#include <fstream>
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
  ConjuntoDeEstado(ifstream&); // Constructor de la clase
  bool aceptacion(); // Verificar si un estado es de aceptación
  void transicion(char); // Transiciones de estados
  void initial(ifstream&); // Estado inicial
  friend std::ostream& operator<<(std::ostream& os, const ConjuntoDeEstado& estado); // Sobrecarga del operador de salida 
  private:
  set<char> estado_;
  char initial_;
  set<char> final_;
};