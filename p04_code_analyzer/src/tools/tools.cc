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