#include <iostream>
#include <fstream>
#include <map>
#include <vector>
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
// Fecha: 22/10/2023
// Archivo: p05_conjunto_de_estados.cc
// Descripción: Declaración de la clase conjunto de estados

class ConjuntoDeEstados {
  public:
  ConjuntoDeEstados(); // Constructor por defecto
  ConjuntoDeEstados(ifstream&); // Constructor de la clase estado
  void setEstadoInicial(int); // Declarar el estado inicial del automata
  bool AceptaCadena(string); // Verificar que acepta la cadena 
  friend ostream& operator<<(ostream& os, ConjuntoDeEstados& conjunto);

  private:
  map<int, vector<pair<char, int>>> conjunto_de_estados_; // Atributo privado de la clase
  vector<bool> aceptacion_; // Almacena los estados de aceptación
  int initial_; // almacena el estado inicial
};