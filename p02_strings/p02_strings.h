#include "cadena.h"
#include <set>

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_strings.h
// Descripción: Definición de la clase languaje

template<class T> class Language {
  public:
    Language(ifstream&); // Constructor de la clase Language
    void alfabeto(); // Mostrar el alfabeto
    int longitud(); // Mostrar la longitud del lenguaje
    void inversa(); // Mostrar la inversa
    void prefijos(); // Mostrar todos los prefijos
    void sufijos(); // Mostrar todos los sufijos

  private:
  set<string> lenguaje_; // Atributo privado de la clase
};