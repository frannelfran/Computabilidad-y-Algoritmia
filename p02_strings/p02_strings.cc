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
  }
}

set<char> Cadena::alfabeto() { //Imprime el alfabeto asociado a la cadena
  set<char> mi_alfabeto;
  for(int it = 0; it < cadena_.size(); it++) { // Recorre la cadena para crear el alfabeto
    mi_alfabeto.insert(cadena_[it]);
  }
  return mi_alfabeto;
}

int Cadena::longitud() { // Devuelve la longitud de cada cadena
  return cadena_.size();
}

set<char> Cadena::inversa() { // Muestra la cadena inversa
  set<char> cadenaInvertida;
  for(int it = cadena_.size(); it >= 0; it--) { // Recorremos la cadena empezando por el último elemento
    cadenaInvertida.insert(cadena_[it]); // Vamos mostrando los elementos de manera inversa
  }
  return cadenaInvertida;
}

void Cadena::prefijos(set<string>& conjuntoPrefijos) { // Crea el conjunto de prefijos de la cadena
  string prefijo;
  for(char letra : cadena_) {
    prefijo += letra; // A cada prefijo le vamos agregando una letra
    conjuntoPrefijos.insert(prefijo); // Vamos insertando los prefijos en el set de strings
  }
}

void Cadena::sufijos(set<string>& conjuntoSufijos) { // Crea el conjunto de sufijos de la cadena
  string sufijo;
  for(vector<char>::iterator letra = cadena_.end(); letra != cadena_.begin(); letra--) {
    sufijo += *letra;
    conjuntoSufijos.insert(sufijo);
  }
}

ostream& operator<<(std::ostream& os, const Cadena& cadena) { // Sobrecarga del operador "<<"
  for (char c : cadena.cadena_) {
    os << c;
  }
  return os;
}