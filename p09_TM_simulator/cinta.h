#include <iostream>
#include <fstream>
#include <tuple>
#include <map>
#include <set>
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
// Archivo:cinta.h
// Descripción: Declaración de la clase Cinta

class Cinta {
  public:
  Cinta();
  Cinta(ifstream&); // Constructor de la clase
  multimap<int, tuple<char, char, char, int>> GetCinta() const; // Obtener la cinta de la máquina
  void MovePosicion(char, int&); // Movernos en la cinta
  bool Pertenece(string&); // Verificar que la cadena pertenece al alfabeto de la cinta
  friend ostream& operator<<(ostream& os, Cinta& cint); // Sobrecarga del operador <<
  private:
  multimap<int, tuple<char, char, char, int>> cinta_; // Cinta
  set<char> alfabeto_; // Alfabeto de la cinta
};