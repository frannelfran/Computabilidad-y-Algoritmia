// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 08/10/2025
// Archivo: tools.cc
// Descripción: Herramientas para el manejo de argumentos de la línea de comandos.

#include "tools.h"

/**
 * @brief Función para tomar los argumentos de la línea de comandos
 * @param argc Número de argumentos
 * @param argv Vector de argumentos
 * @return Estructura Tools con los argumentos parseados
 */

Tools parseArgs(int argc, char* argv[]) {
  Tools tools;
  if (argc < 3 && string(argv[1]) != "--help") {
    cerr << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode " << endl;
    cerr << "Pruebe ./p02_strings --help para más información." << endl;
    exit(EXIT_FAILURE);
  } else if (string(argv[1]) == "--help") { // Mostrar ayuda 
    printHelp();
    exit(EXIT_SUCCESS);
  }
  // Almaceno los argumentos
  if (string(argv[1]).find(".cc") == string::npos || string(argv[2]).find(".txt") == string::npos) {
    throw invalid_argument("Los ficheros deben tener extensión .cc y .txt respectivamente");
  }
  tools.filein = argv[1];
  tools.fileout = argv[2];
  return tools;
}

/**
 * @brief Función para imprimir la ayuda
 * @returns void
 */
void printHelp() {
  cout << "Modo de empleo: ./p04_code_analyzer code.cc codescheme.txt" << endl;
  cout << "Donde:" << endl;
  cout << "\ncode.cc       Fichero de código fuente a analizar." << endl;
  cout << "\ncodescheme.txt Fichero con el esquema de codificación." << endl;
}