#include "p02_strings.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_strings.cc
// Definición: Implementación de la clase language

template<class T> Language<T>::Language(ifstream& filein) { // Constructor de la clase lenguaje
  string elemento;
  while(filein >> elemento) {
    lenguaje_.insert(elemento); // Introducir las cadenas al set
  }
  filein.close(); // Cerrar el fichero
}
