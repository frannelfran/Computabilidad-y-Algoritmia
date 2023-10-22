#include "p06_conjunto_estados.h"
#include "p06_transiciones.h"

ConjuntoDeEstados::ConjuntoDeEstados() {} // Constructor por defecto de la clase

/**
 * @param file Fichero que contiene la información de los estados
*/

ConjuntoDeEstados::ConjuntoDeEstados(int estado, Transiciones transiciones) {
  conjunto_de_estados_.insert(pair<int, Transiciones>(estado, transiciones));
}

ostream& operator<<(ostream& os, ConjuntoDeEstados& conjunto) {
  os << "Conjunto de Estados:" << endl;
  for (const auto& par : conjunto.conjunto_de_estados_) {
    os << "Estado " << par.first << ":" << endl;
    os << par.second << endl; // Suponiendo que Transiciones tenga su sobrecarga de operador <<
  }
  return os;
}