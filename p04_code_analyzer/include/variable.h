#pragma once
#include <string>

using namespace std;

/**
 * @struct Enum para representar las variables del programa.
*/
struct Variable {
  string tipo; // double o int
  int linea; // Linea en la que se declara
  string nombre; // Nombre de la variable
  bool inicializada; // Si la variable ha sido inicializada en la propia declaracion
};
