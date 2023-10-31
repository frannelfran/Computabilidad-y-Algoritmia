#include "p07_producciones.h"

Producciones::Producciones() {} // Contructor por defecto de la clase

/**
 * @brief Constructor de la clase Producciones
 * @param file Fichero para leer las producciones de la gramática
 * @param alfabeto Alfabeto de la gramática
 * @param no_terminales Símbolos no terminales que tiene la gramática
 * @return Devuelve un objeto de la clase terminal
*/

Producciones::Producciones(ifstream& file, Alfabeto alfabeto, NoTerminales no_terminales) {
  int num_producciones;
  char term; // símbolo no terminal
  string derivaciones; // Derivaciones de cada símbolo
  alfabeto_ = alfabeto;
  no_terminales_ = no_terminales;
  file >> num_producciones;
  while (num_producciones != 0) {
    file >> term;
    file >> derivaciones;
    producciones_[term].insert(derivaciones);
    num_producciones--;
  }
}

/**
 * @brief Función para agregar una producción
 * @param simbolo_no_terminal Símbolo no terminal para agregarlo en la gramática
 * @param produccion Producción que genera ese símbolo no terminal
*/

void Producciones::AgregarProduccion(char simbolo_no_terminal, const string& produccion) {
  // Asegurarse de que el símbolo no terminal exista en la gramática
  no_terminales_.Insertar(simbolo_no_terminal);
  producciones_[toupper(simbolo_no_terminal)].insert(produccion);
}

/**
 * @brief Modificar las producciones (Primera parte del algoritmo)
*/

void Producciones::ModificarProducciones() {
  for (auto it = producciones_.begin(); it != producciones_.end(); it++) {
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      string produc = *it2; // Almaceno la producción en un string
      for (int iterator = 0; iterator < produc.length(); iterator++) {
        if (produc.length() == 1) continue;
        char simbolo = produc[iterator];
        if (islower(simbolo)) { // Comprobar que la letra es minúscula
          string to_string(1, simbolo); // Convertir el char a string para agregarlo a la producción
          AgregarProduccion(simbolo, to_string);
          char no_terminal = toupper(simbolo); // Convierto el terminal en no terminal
          produc[iterator] = no_terminal;
        }
      }
      // Remplazar la producción original con la producción modificada
      producciones_[it->first].erase(*it2);
      producciones_[it->first].insert(produc);
    }
  }
}

/**
 * @brief Dividir las producciones (Segunda parte del algoritmo)
*/

void Producciones::DividirProducciones() {
  for (auto it = producciones_.begin(); it != producciones_.end(); it++) {
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      string produc = *it2;
      while (produc.length() >= 3) {
        string subcadena = produc.substr(produc.length() - 2);
        produc.erase(produc.length() - 2);
        char no_terminal = no_terminales_.ObtenerNoTerminal();
        AgregarProduccion(no_terminal, subcadena);
      }
      producciones_[it->first].erase(*it2);
      producciones_[it->first].insert(produc);
    }
  }
}
    


ostream& operator<<(ostream& os, Producciones& prod) {
  os << prod.alfabeto_;
  os << prod.no_terminales_;
  os << "Producciones de la gramática" << endl;
  for (auto it = prod.producciones_.begin(); it != prod.producciones_.end(); it++) {
    os << it->first << " → ";
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      os << *it2;
      if (next(it2) == it->second.end()) {
        os << endl;
        break;
      }
      os << " | ";
    }
  }
  return os;
}