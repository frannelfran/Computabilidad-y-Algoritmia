#include <iostream>
#include <set>
#include <fstream>
#include <string>
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
// Archivo: p05_alfabeto.h
// Descripción: Declaración de la clase alfabeto

class Alfabeto {
  public:
  Alfabeto(); // Constructor predeterminado de la clase
  Alfabeto(ifstream&); // Constructor de la clase
  friend ostream& operator<<(ostream& os, const Alfabeto& alfabeto);
  private:
  set<char> alfabeto_;
};