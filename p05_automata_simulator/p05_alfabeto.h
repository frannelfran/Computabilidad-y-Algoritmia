#include <iostream>
#include <fstream>
#include <set>
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
// Fecha: 15/10/2023
// Archivo alfabeto.h
// Descripción: Declaración de la clase alfabeto

class Alfabeto {
  public:
  Alfabeto(string); // Constructor de la clase
  Alfabeto();
  bool contiene_alfabeto(char); // Verificar si el símbolo de la cadena esta contenido en el alfabeto
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& alf); // Sobrecarga del operador de salida
  private:
  set<char> alfabeto_;
};