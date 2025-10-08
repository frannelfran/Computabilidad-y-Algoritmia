// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 08/10/2025
// Archivo: comentario.h
// Descripción: Estructura para representar los comentarios del programa.

#pragma once
#include <string>

using namespace std;

/**
 * @struct Struct para representar los comentarios del programa.
 */
struct Comentario {
  string tipo; // simple, multiple o descripcion
  int principio; // Linea en la que empieza
  int fin = 0; // Linea en la que termina
  string contenido; // Contenido del comentario
};