#include "estados.h"

Estados::Estados() {}

Estados::Estados(ifstream& file) {
  int num_estados;
  file >> num_estados; // Leo el número de estados
  file >> inicial_; // Leo el estado inicial
  file >> aceptacion_; // Leo el estado de aceptación
}

/**
 * @brief Delvolver el estado inicial
 * @return Estado inicial
*/

int Estados::Inicial() {
  return inicial_;
}

/**
 * @brief Comprobar si el estado actual es de aceptación
 * @param estado_actual Estado actual
 * @return 1 si es de aceptación y 0 en caso contrario
*/

bool Estados::Aceptacion(int estado_actual) {
  if (estado_actual == aceptacion_) {
    return true;
  }
  return false;
}