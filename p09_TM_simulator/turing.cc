#include "turing.h"

TM::TM() {} // Constructor por defecto

TM::TM(Cinta& mi_cinta, set<int> estados, set<int> aceptacion, int inicial) {
  this->cinta_ = mi_cinta; // Cinta de la máquina
  this->estados_ = estados; // estados de la máquina
  this->aceptacion_ = aceptacion; // Estados de aceptación de la máquina
  this->inicial_ = inicial; // Estado inicial de la máquina
}


/**
 * @brief Funcionamiento de la máquina de turing
 * @param cadena Cadena a pasar por la máquina
*/

void TM::Funcionamiento(string& cadena) {
  multimap <int, tuple<char, char, char, int>> mi_cinta = cinta_.GetCinta();
  int estado_actual = inicial_;
  string cinta_contenido = cadena + "$"; // Inicializar la cinta con la cadena
  cout << "$ q" << estado_actual << " " << cinta_contenido << endl;
  for (char letra : cadena) {
    // Buscamos la transición correspondiente en la cinta
    auto transicion = mi_cinta.find(estado_actual);
    while (transicion != mi_cinta.end() && get<0>(transicion->second) != letra) {
      transicion++;
    }
    if (transicion != mi_cinta.end()) {
      // Actualizo la cinta y el estado según la transición
      cinta_contenido[transicion->first] = get<1>(transicion->second);
      estado_actual = get<3>(transicion->second);

      // Imprimo el estado actual de la máquina
      cout << "$" << cinta_contenido.substr(0, transicion->first + 1) << " q" << estado_actual
      << " " << cinta_contenido.substr(transicion->first + 1) << endl;
    }
    else {
      cout << "transición no encontrada para " << letra << " en el estado " << estado_actual << endl;
      break;
    }
  }

  // Verificamos si el estado actual es de aceptación
  if (aceptacion_.find(estado_actual) != aceptacion_.end()) {
    cout << "Cadena ACEPTADA" << endl;
  }
  else {
    cout << "Cadena NO ACEPTADA" << endl;
  }
}


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