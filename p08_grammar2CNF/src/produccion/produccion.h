// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 05/11/2025
// Archivo: produccion.h
// Descripción: Declaración de la clase Produccion

#ifndef PRODUCCION_H
#define PRODUCCION_H

#include "../simbolo/simbolo.h"
#include <vector>

class Produccion {
  public:
  // Constructor y destructor
  Produccion() = default;
  Produccion(const Simbolo& izq) : simboloIzquierda(izq) {};
  ~Produccion() = default;

  // Métodos
  inline void agregarAlternativa(const vector<Simbolo>& simbolos) { simbolosDerecha.push_back(simbolos); }
  
  // Getters
  inline Simbolo& getSimboloIzquierda() { return simboloIzquierda; }
  inline const Simbolo& getSimboloIzquierda() const { return simboloIzquierda; }
  inline vector<vector<Simbolo>>& getSimbolosDerecha() { return simbolosDerecha; }
  inline const vector<vector<Simbolo>>& getSimbolosDerecha() const { return simbolosDerecha; }
  
  // Sobrecarga de operadores
  friend ostream& operator<<(ostream& os, const Produccion& produccion);
  inline bool operator==(const Produccion& otra) const {
    return simboloIzquierda == otra.simboloIzquierda && simbolosDerecha == otra.simbolosDerecha;
  }

  private:
    Simbolo simboloIzquierda;
    vector<vector<Simbolo>> simbolosDerecha;
};

#endif // PRODUCCION_H