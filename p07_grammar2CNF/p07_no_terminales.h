#include <iostream>
#include <fstream>
#include <set>
#include <cctype>
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
// Archivo: p07_no_terminales.h
// Descripción: Declaración de la clase NoTerminales

class NoTerminales {
  public:
  NoTerminales(); // Constructor por defecto
  NoTerminales(ifstream&); // Constructor de la clase
  void Insertar(char); // Insertar no terminales
  char ObtenerNoTerminal(); // Obtener un no_terminal
  bool IsTerminal(char); // comprobar que los símbolos sean no terminales
  friend ostream& operator<<(ostream& os, NoTerminales& term); // Sobrecarga del operador de salida
  private:
  set<char> no_terminales_; // Atributo privado de la clase
};