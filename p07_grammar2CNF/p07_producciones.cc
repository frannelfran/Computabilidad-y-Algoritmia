#include "p07_producciones.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramáticas en Forma Normal de Chomsky
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 31/10/2023
// Archivo: p07_producciones.cc
// Descripción: Implemetación de la clase Producciones

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
    // Comprobar si los símbolos no terminales del fichero pertenecen al conjunto de no terminales
    if (!no_terminales_.IsTerminal(term)) {
      cout << "Error en el fichero: Se ha introducido un símbolo que no pertenece al conjunto de no terminales." << endl;
      exit(EXIT_SUCCESS);
    }
    file >> derivaciones;
    // Comprobar que las derivaciónes tengan símbolos del alfabeto y del conjunto de no terminales
    for (char simbolo : derivaciones) {
      if (islower(simbolo)) {
        if(!alfabeto_.IsAlfabeto(simbolo)) { // Comprobar que el símbolo pertenezca al alfabeto
          cout << "Error en el fichero: Se ha introducido un símbolo que no pertenece al alfabeto." << endl;
          exit(EXIT_SUCCESS);
        }
      }
      else if (isupper(simbolo)) {
        if (!no_terminales_.IsTerminal(simbolo)) { // Comprobar que el símbolo pertenezca al conjunto de no terminales
          cout << "Error en el fichero: Se ha introducido un símbolo que no pertenece al conjunto de no terminales." << endl;
          exit(EXIT_SUCCESS);
        }
      }
    }
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
        // Obtener los últimos términos de la cadena
        string subcadena = produc.substr(produc.length() - 2);
        produc.erase(produc.length() - 2);
        // Obtener un nuevo no terminal
        char no_terminal = no_terminales_.ObtenerNoTerminal();
        // Agregar la producción
        AgregarProduccion(no_terminal, subcadena);
        produc += no_terminal;
      }
      // Sustituir las producciones
      producciones_[it->first].erase(*it2);
      producciones_[it->first].insert(produc);
    }
  }
}

/**
 * @overload Operador <<
*/

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