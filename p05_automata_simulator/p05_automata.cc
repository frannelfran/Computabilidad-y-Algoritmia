#include "p05_alfabeto.h"
#include "p05_estado.h"
#include "p05_automata.h"
#include "p05_nodo.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 16/10/2023
// Archivo p05_automata.cc
// Descripción: Implementación de la clase autómata

Automata::Automata() {} // Cosntructor por defecto

Automata::Automata(Alfabeto mi_alfabeto, ConjuntoDeEstado mis_estados) {
  alfabeto_ = mi_alfabeto;
  estados_ = mis_estados;
}

int Automata::actual() { // Obtener el estado actual
  return estado_actual_;
}

bool Automata::aceptado(string cadena) {
  int estado_actual = 0;
  for(const char simbolo : cadena) {
    if(!alfabeto_.contiene_alfabeto(simbolo)) { // Si el símbolo no esta contenido en el alfabeto se rechaza
      return false;
    }
    int siguiente;
    if (!estados_.contieneTransicion(estado_actual, simbolo, siguiente)) {
      // No hay transición para el símbolo, la cadena es rechazada
      return false;
    }
    estado_actual = siguiente;
  }
  // Verificar si el estado actual es de aceptación
  if (estados_.contiene_estado(estado_actual)) {
    return estados_.obtener_estado(estado_actual).aceptacion();
  }
  return false;
}