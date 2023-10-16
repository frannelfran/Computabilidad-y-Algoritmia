#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 15/10/2023
// Archivo alfabeto.h
// Descripción: Declaración de la clase alfabeto

class Alfabeto {
  public:
  Alfabeto(ifstream&); // Constructor de la clase
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& alf); // Sobrecarga del operador de salida
  private:
  set<char> alfabeto_;
};