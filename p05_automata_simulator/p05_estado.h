#include <iostream>
#include <set>
#include <string>
#include <fstream>

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

class Estado {
  public:
  Estado(ifstream&); // Constructor de la clase
  char initial(ifstream&); // Estado inicial
  friend std::ostream& operator<<(std::ostream& os, const Estado& estado); // Sobrecarga del operador de salida 
  private:
  set<char> estado_; // Atributo privado
};