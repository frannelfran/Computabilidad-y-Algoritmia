#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <queue>
#pragma once

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 26/10/2023
// Archivo: p06_alfabeto.h
// Descripción: Declaración de la clase Alfabeto

class Alfabeto {
  public:
  Alfabeto(); // Constructor predeterminado de la clase
  Alfabeto(ifstream&); // Constructor de la clase
  set<char> getAlfabeto(); // Devuelve el alfabeto
  friend ostream& operator<<(ostream& os, const Alfabeto& alfabeto);
  private:
  set<char> alfabeto_;
};