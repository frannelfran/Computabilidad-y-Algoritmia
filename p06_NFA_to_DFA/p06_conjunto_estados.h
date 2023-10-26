#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
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
// Archivo: p06_conjunto_estados.h
// Descripción: Declaración de la clase ConjuntoDeEstados

class ConjuntoDeEstados {
  public:
  ConjuntoDeEstados(); // Constructor por defecto
  ConjuntoDeEstados(ifstream&); // Constructor de la clase estado
  void setEstadoInicial(int); // Declarar el estado inicial del automata
  int getEstadoInicial(); // Obtener el estado inicial
  set<int> obtenerTransiciones(set<int>, char); // Obtener las transiciones
  void agregarTransiciones(set<int>, int, char);
  bool esEstadoAceptacion(int); // Verificar si el estado es de aceptación
  friend ostream& operator<<(ostream& os, ConjuntoDeEstados& conjunto);

  private:
  map<int, vector<pair<char, int>>> conjunto_de_estados_; // Atributo privado de la clase
  vector<bool> aceptacion_; // Almacena los estados de aceptación
  int initial_; // Almacena el estado inicial
};