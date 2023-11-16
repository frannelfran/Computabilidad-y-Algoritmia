#include "turing.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 15/11/2023
// Archivo:turing.cc
// Descripción: Implementación de la clase TM

TM::TM() {} // Constructor por defecto

TM::TM(Cinta& mi_cinta, set<int> estados, set<int> aceptacion, int inicial) {
  this->cinta_ = mi_cinta; // Cinta de la máquina
  this->estados_ = estados; // Estados de la máquina
  this->aceptacion_ = aceptacion; // Estados de aceptación de la máquina
  this->inicial_ = inicial; // Estado inicial de la máquina
}

/**
 * @brief Comprobar que el estado de aceptación no contenga una transición saliente
 * @param estado Estado a comprobar
 * @return 1 En caso de que haya una transición y 0 en caso contrario
*/

bool TM::AceptacionSinTransiciones(int estado) const {
  auto mi_cinta = cinta_.GetCinta();
  auto transicion = mi_cinta.find(estado);
  while (transicion != mi_cinta.end()) {
    if (estado == std::get<3>(transicion->second)) {
      return true;  // Transición saliente desde el estado de aceptación
    }
    transicion++;
  }
  return false;  // No se encontraron transiciones salientes desde el estado de aceptación
}

/**
 * @brief Funcionamiento de la máquina de turing
 * @param cadena Cadena a pasar por la máquina
*/

void TM::Funcionamiento(string& cadena) {
  // Comprobar que la cadena pertenece al alfabeto de la cinta
  if (cinta_.Pertenece(cadena)) {
    cout << "La cadena posee un símbolo que no pertenece al alfabeto de la cinta" << endl;
    exit(EXIT_SUCCESS);
  }

  multimap <int, tuple<char, char, char, int>> mi_cinta = cinta_.GetCinta();
  int estado_actual = inicial_;
  string cinta_contenido = cadena + "$"; // Inicializar la cinta con la cadena
  int posicion = 0;
  
  cout << "$ q" << estado_actual << " " << cinta_contenido << endl;
  
  while (posicion < cinta_contenido.size()) {
    char letra = cinta_contenido[posicion];

    // Buscamos la transición correspondiente en la cinta
    auto transicion = mi_cinta.find(estado_actual);
    while (transicion != mi_cinta.end() && get<0>(transicion->second) != letra) {
      transicion++;
    }

    if (transicion != mi_cinta.end()) {
      // Actualizamos la cinta y el estado según la transición
      cinta_contenido[posicion] = get<1>(transicion->second);
      estado_actual = get<3>(transicion->second);

      // Movemos el posicion según la transición
      if (get<2>(transicion->second) == 'R') {
        posicion++;
      }
      else if (get<2>(transicion->second) == 'L') {
        posicion--;
      }
      // Imprimimos el estado actual de la máquina
      cout << "$" << cinta_contenido.substr(0, posicion) << " q" << estado_actual << " " << cinta_contenido[posicion] << cinta_contenido.substr(posicion + 1) << endl;
    }
    // Si no se encuentra una transición para un estado parar
    else {
      break;
    }
  }
  // Verificamos si el estado actual es un estado de aceptación
  if (aceptacion_.find(estado_actual) != aceptacion_.end()) {
    if (AceptacionSinTransiciones(estado_actual)) { // Comprobar que el estado de aceptación no tiene una transición saliente
      cout << "\nEl estado q" << estado_actual << " no puede tener una transición" << endl;
    }
    else {
      cout << "\nCadena ACEPTADA" << endl;
    }
  }
  else {
    cout << "\nCadena RECHAZADA" << endl;
  }
}

/**
 * @overload Operador <<
*/

ostream& operator<<(ostream& os, TM& tm) {
  os << "Estados de la máquina: ";
  for (auto it = tm.estados_.begin(); it != tm.estados_.end(); it++) {
    os << *it;
    if (next(it) != tm.estados_.end()) {
      os << ",";
    }
  }
  os << "\n";
  os << "Estados de aceptación: ";
  for (auto it = tm.aceptacion_.begin(); it != tm.aceptacion_.end(); it++) {
    os << *it;
    if (next(it) != tm.aceptacion_.end()) {
      os << ",";
    }
  }
  os << "\n";
  os << tm.cinta_;
  return os;
}