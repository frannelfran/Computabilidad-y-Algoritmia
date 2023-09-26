#include <iostream>
#include <vector>
#include <fstream>
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
// Archivo p02_strings.h
// Decripción: Declaración de la clase cadena

class Cadena {
  public:
    Cadena(const string); // Constructor de la clase cadena
    void alfabeto(); // Crea el alfabeto según la cadena
    int longitud(); // Muestra la longitud que tiene la cadena
    void inversa(); // Muestra la cadena de manera inversa

    friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena); // Sobrecarga del operador "<<"
  private: // Atributos privados de la clase
    vector<char> cadena_;
    set<char> alfabeto_;
};