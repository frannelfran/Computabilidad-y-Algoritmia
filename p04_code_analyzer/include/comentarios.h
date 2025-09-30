#pragma once
#include <string>

using namespace std;

/**
 * @struct Struct para representar los comentarios del programa.
 */
struct Comentario {
  string tipo; // simple, multiple o descripcion
  int principio; // Linea en la que empieza
  int fin; // Linea en la que termina
  string contenido; // Contenido del comentario
};