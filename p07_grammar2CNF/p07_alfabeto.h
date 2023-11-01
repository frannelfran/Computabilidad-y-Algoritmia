#include <iostream>
#include <fstream>
#include <set>
#pragma once

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramáticas en Forma Normal de Chomsky
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 31/10/2023
// Archivo: p07_alfabeto.h
// Descripción: Declaración de la clase Alfabeto

class Alfabeto {
  public:
  Alfabeto(); // Constructor por defecto
  Alfabeto(ifstream&); // Constructor de la clase
  bool IsAlfabeto(char); // Comprobar que los símbolos pertenezcan al alfabeto
  friend ostream& operator<<(ostream& os, Alfabeto& alf); // Sobrecarga del operador de salida
  private:
  set<char> alfabeto_;
};