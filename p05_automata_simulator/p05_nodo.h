#include <iostream>
#include <map>
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
// Fecha: 17/10/2023
// Archivo p05_nodo.h
// Descripción: Declaración de la clase nodo

class Nodo {
  public:
  Nodo(char, int, int); // Constructor de la clase nodo
  Nodo(); // Constructor por defecto
  bool aceptacion(); // Saber si un nodo es de aceptación
  const multimap<char, int>& obtenerTransiciones() const; // Método para obtener las transiciones
  friend std::ostream& operator<<(std::ostream& os, const Nodo& nodo); // Sobrecarga del operador de salida
  private: // Atributos privados de la clase
  multimap<char, int> transiciones_;
  int aceptacion_;
};