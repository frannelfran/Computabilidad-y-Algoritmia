#include "p02_cadena.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_cadena.cc
// Decripción: Implementación de la clase cadena

Cadena::Cadena(ifstream& filein) { // Cionstructor de la clase
  string simbolo;
  while(filein >> simbolo) {
    for(int it = 0; it < simbolo.size(); it++) {
      cadena_.push_back(simbolo[it]); // Crear la cadena
    }
  }
  filein.close(); // Cerrar el fichero
}

void Cadena::alfabeto() { // Crear el alfabeto
  for(int it = 0; it << cadena_.size(); it++) { // Recorrer la cadena
    alfabeto_.insert(cadena_[it]);
  }
}