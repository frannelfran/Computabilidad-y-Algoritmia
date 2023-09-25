#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
// Archivo p02_cadena.h
// Decripción: Declaración de la clase cadena

class Cadena {
  public:
    Cadena(ifstream&); // Constructor de la clase cadena
    void alfabeto(); // Crea el alfabeto según la cadena
  private:
  vector<char> cadena_; // Atributo privado de la clase
};