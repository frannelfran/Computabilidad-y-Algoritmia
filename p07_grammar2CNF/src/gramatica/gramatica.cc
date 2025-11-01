#include "gramatica.h"

/**
 * @brief Constructor de la clase Gramatica
 * @param alf Alfabeto de la gramática
 * @param noTerminales Conjunto de símbolos no terminales
 * @param prods Vector de producciones de la gramática
 */
Gramatica::Gramatica(const Alfabeto& alf, const set<Simbolo>& noTerminales, const vector<vector<Produccion>>& prods)
    : alfabeto_(alf), simbolosNoTerminales_(noTerminales) {
  for (const auto& grupoProducciones : prods) {
    for (const auto& produccion : grupoProducciones) {
      producciones_.push_back(produccion);
    }
  }
}

/**
 * @overload Sobrecarga del operador de salida para mostrar la gramática
 * @param os Flujo de salida
 * @param gramatica Gramática a mostrar
 * @return Flujo de salida con la gramática formateada
 */
ostream& operator<<(ostream& os, const Gramatica& gramatica) {
  os << gramatica.alfabeto_ << endl;
  os << "V -> {";
  for (const auto& simbolo : gramatica.simbolosNoTerminales_) {
    os << simbolo;
    if (&simbolo != &(*gramatica.simbolosNoTerminales_.rbegin())) {
      os << ", ";
    }
  }
  os << "}" << endl;
  os << "--- Producciones ---" << endl;
  for (const auto& produccion : gramatica.producciones_) {
    os << produccion << endl;
  }
  return os;
}