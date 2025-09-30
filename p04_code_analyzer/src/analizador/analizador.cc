#include "analizador.h"

/**
 * @brief Analiza el archivo fuente en busca de variables, bucles y comentarios.
 * @param archivo Archivo fuente a analizar.
 * @return void
 */
void Analizador::analizar(ifstream& archivo) {
  string linea;
  int numeroLinea = 0;
  while (getline(archivo, linea)) {
    numeroLinea++;
    clasificar(linea, numeroLinea);
  }
}

/**
 * @brief Método para clasificar una línea de código.
 * @param linea Línea de código a clasificar.
 * @param principio Índice de inicio de la línea.
 * @param fin Índice de fin de la línea.
 * @return void
 */
void Analizador::clasificar(const string& linea, int principio, int fin) {
  regex variableSinInicializar(R"(^\s*(int|double)\s+([a-zA-Z_]\w*)\s*;)");
  regex variableInicializada(R"(^\s*(int|double)\s+([a-zA-Z_]\w*)\s*=\s*([^;]+)\s*;)");
  regex bucle(R"(^\s*(for|while)\s*\([^)]*\)\s*\{?)");
  regex main(R"(^\s*int\s+main\s*\([^)]*\)\s*\{?)");
  

  smatch match;

  if (regex_search(linea, match, variableSinInicializar)) {
    crearVariable(match[1], principio, match[2]);
  } else if (regex_search(linea, match, variableInicializada)) {
    crearVariable(match[1], principio, match[2], stoi(match[3]));
  } else if (regex_search(linea, match, bucle)) {
    crearBucle(match[1], principio);
  } else if (regex_search(linea, match, main) && !main_) {
    main_ = true;
  }
}

/**
 * @brief Método para crear una variable y añadirla al vector de variables.
 * @param tipo Tipo de la variable (int o double).
 * @param linea Línea en la que se declara la variable.
 * @param nombre Nombre de la variable.
 * @param valor Valor de la variable (0 por defecto si no está inicializada).
 */
void Analizador::crearVariable(const string& tipo, int linea, const string& nombre, int valor) {
  variables_.push_back(Variable{tipo, linea, nombre, valor});
}

/**
 * @brief Método para crear un bucle y añadirlo al vector de bucles.
 * @param tipo Tipo de bucle (for o while).
 * @param linea Línea en la que se declara el bucle.
 */
void Analizador::crearBucle(const string& tipo, int linea) {
  bucles_.push_back(Bucle{tipo, linea});
}