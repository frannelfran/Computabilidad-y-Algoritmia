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

void Cadena::inversa() { // Muestra la cadena inversa
  vector<char> cadenaInvertida;
  for(int it = cadena_.size() -1; it >= 0; it--) { // Recorremos la cadena empezando por el último elemento
    cadenaInvertida.push_back(cadena_[it]);
  }
  cadena_ = cadenaInvertida; // Cambio a cadena invertida
}

set<string> Cadena::prefijos() { // Crea el conjunto de prefijos de la cadena
  set<string> conjuntoPrefijos; // Creamos el set donde se van a almacenar los prefijos de la cadena
  string prefijo;
  conjuntoPrefijos.insert("&"); // Inserto la cadena vacía
  for(char letra : cadena_) {
    prefijo += letra; // A cada prefijo le vamos agregando una letra
    conjuntoPrefijos.insert(prefijo); // Vamos insertando los prefijos en el set de strings
  }
  return conjuntoPrefijos;
}

set<string> Cadena::sufijos() { // Crea el conjunto de sufijos de la cadena
  set<string> conjuntoSufijos;
  string sufijo;
  conjuntoSufijos.insert("&"); // Inserto la cadena vacía
  for (int it = cadena_.size() - 1; it >= 0; it--) {
    sufijo += cadena_[it];
    conjuntoSufijos.insert(sufijo); // Vamos insertando los sufijos en el set de strings
  }
  return conjuntoSufijos;
}

ostream& operator<<(std::ostream& os, const Cadena& cadena) { // Sobrecarga del operador "<<"
  for (char letra : cadena.cadena_) {
    os << letra;
  }
  return os;
}