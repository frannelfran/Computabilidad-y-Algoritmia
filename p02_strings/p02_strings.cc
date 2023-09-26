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
// Decripción: Implementación de la clase cadena

Cadena::Cadena(const string mi_cadena) { // Constructor de la clase
  for (const char letra : mi_cadena) {
    cadena_.push_back(letra); // Creo la cadena
    alfabeto_.insert(letra); // Creo el alfabeto
  }
}

void Cadena::alfabeto() { //Imprime el alfabeto asociado a la cadena
  cout << "{";
  for(set<char>::iterator it = alfabeto_.begin(); it != alfabeto_.end(); ++it) { // Recorremos el alfabeto
    if (next(it) == alfabeto_.end()) {
      cout << *it;
      break;
    }
    cout << *it << ", ";
  }
  cout << "}" << endl;
}

int Cadena::longitud() { // Devuelve la longitud de cada cadena
  return cadena_.size();
}

void Cadena::inversa() { // Muestra la cadena inversa
  for(int it = cadena_.size(); it >= 0; it--) { // Recorremos la cadena empezando por el último elemento
    cout << cadena_[it]; // Vamos mostrando los elementos de manera inversa
  }
  cout << endl; // Nueva línea
}

ostream& operator<<(std::ostream& os, const Cadena& cadena) { // Sobrecarga del operador "<<"
  for (char c : cadena.cadena_) {
    os << c;
  }
  return os;
}