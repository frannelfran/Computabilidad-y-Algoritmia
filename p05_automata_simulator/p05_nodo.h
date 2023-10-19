#include <iostream>
#include <map>
#pragma once

using namespace std;

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