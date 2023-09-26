#include <iostream>
#include <string>
#include <set>

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 26/09/2023
// Archivo p02_alfabeto.h
// Descripción: Declaración de la clase cadena

class Alfabeto {
  public:
  Alfabeto(std::set<char>&); // Constructor de la clase
  private:
  std::set<char> alfabeto_; // Atributo privado de la clase
};