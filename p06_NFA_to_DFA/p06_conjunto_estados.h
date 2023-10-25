#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#pragma once

using namespace std;

class ConjuntoDeEstados {
  public:
  ConjuntoDeEstados(); // Constructor por defecto
  ConjuntoDeEstados(ifstream&); // Constructor de la clase estado
  void setEstadoInicial(int); // Declarar el estado inicial del automata
  int getEstadoInicial(); // Obtener el estado inicial
  set<int> obtenerTransiciones(int, char); // Obtener las transiciones
  void agregarTransiciones(int, int, char);
  bool esEstadoAceptacion(int); // Verificar si el estado es de aceptación
  friend ostream& operator<<(ostream& os, ConjuntoDeEstados& conjunto);

  private:
  map<int, vector<pair<char, int>>> conjunto_de_estados_; // Atributo privado de la clase
  vector<bool> aceptacion_; // Almacena los estados de aceptación
  int initial_; // Almacena el estado inicial
};