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
  char term; // símbolo terminal
  string derivaciones; // Derivaciones de cada símbolo
  alfabeto_ = alfabeto;
  no_terminales_ = no_terminales;
  file >> num_producciones;
  while (num_producciones != 0) {
    file >> term;
    file >> derivaciones;
    producciones_[term].push_back(derivaciones);
    num_producciones--;
  }
}

/**
 * @brief Comprobar que el símbolo es terminal
 * @param simbolo Terminal a comprobar
 * @return 1 en caso de que sea terminal y 0 si no es terminal
*/

bool Producciones::EsTerminal(char simbolo) {
  int conversion = static_cast<int>(simbolo); // Convierto el símbolo a entero
  if(simbolo >= 65 || simbolo <= 90) { // Verificar mediante el código ASCII si el símbolo es terminal
    return true;
  }
  return false;
}

void Producciones::AgregarProduccion(char simbolo, const string& produccion) {
  // asegurarse de que el símbolo no terminal exista en la gramática
}

/**
 * @brief Modificar las producciones (Primera parte del algoritmo)
*/

void Producciones::ModificarProducciones() {
  for (auto it = producciones_.begin(); it != producciones_.end(); it++) {
    char no_terminal = it->first;
    for (auto& production : it->second) {
      string nueva_produccion = production;
      for(size_t i = 0; i < nueva_produccion.length(); i++) {
        char simbolo = nueva_produccion[i];
        if (EsTerminal(simbolo)) {

        }
      }
    }
  }

}

ostream& operator<<(ostream& os, Producciones& prod) {
  os << prod.alfabeto_;
  os << prod.no_terminales_;
  os << "Producciones de la gramática" << endl;
  for (auto it = prod.producciones_.begin(); it != prod.producciones_.end(); it++) {
    os << it->first << " → ";
    for (const string& production : it->second) {
      os << production;
      if (production != it->second.back()) {
        os << " | ";
      }
    }
    os << endl;
  }
  return os;
}