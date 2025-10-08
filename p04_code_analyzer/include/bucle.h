// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 08/10/2025
// Archivo: bucle.h
// Descripción: Estructura para representar los bucles del programa.

#pragma once
#include <string>

using namespace std;

/**
 * @struct Enum para representar los bucles del programa.
*/
struct Bucle {
  string tipo; // for o while
  int linea; // Linea en la que se declara
};
