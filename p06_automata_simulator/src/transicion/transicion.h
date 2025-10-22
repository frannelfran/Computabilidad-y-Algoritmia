// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 23/10/2025
// Archivo: transicion.h
// Descripción: Declaración de la clase Transicion

#pragma once
#include <string>

#ifndef TRANSICION_H
#define TRANSICION_H

using namespace std;

// Para evitar errores con la dependencia circular
class Estado;

/**
 * @class Transicion
 * @brief Clase que representa una transición en un autómata
 */
class Transicion {
  public:
    // Constructor y destructor
    Transicion() = default;
    Transicion(const int& id, const char& lecturaCadena, Estado* actual, Estado* siguiente);
    ~Transicion() = default;

    // Getters
    inline char getLecturaCadena() const { return lecturaCadena_; }
    inline int getId() const { return id_; }

    // Métodos
    Estado* ejecutar(string& cadena);

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Transicion& transicion);

  private:
    int id_;
    char lecturaCadena_;
    Estado* actual_;
    Estado* siguiente_;
};

#endif // TRANSICION_H