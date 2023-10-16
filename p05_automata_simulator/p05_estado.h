#include <iostream>
#include <map>
#include <vector>
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
  Estado(fstream&); // Constructor de la clase

  private:
  multimap<char, vector<char>> estado_; // Atributo privado
};