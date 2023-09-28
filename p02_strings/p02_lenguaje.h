#include <iostream>
#include <string>
#include <set>
using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_lenguaje.h
// Descripción: Declaración de la clase lenguaje

class Lenguaje {
public:
  Lenguaje(set<string>&); // Constructor de la clase
  friend std::ostream& operator<<(std::ostream& os, const Lenguaje& leng); // Sobrecarga del operador "<<"
private:
  set<string> lenguaje_; // Atributo privado de la clase
};