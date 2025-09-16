#include "tools.h"

/**
 * @brief FUnción para tomar los argumentos de la línea de comandos
 * @param argc Número de argumentos
 * @param argv Vector de argumentos
 * @return Estructura Tools con los argumentos parseados
 */

Tools parseArgs(int argc, char* argv[]) {
  Tools tools;

  if (argc < 4) {
    cerr << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode "
         << "Pruebe ./p02_strings --help para más información." << endl;
    exit(EXIT_FAILURE);
  } else if (string(argv[1]) == "--help") {
    printHelp();
    exit(EXIT_SUCCESS);
  }
  tools.filein = argv[1];
  tools.fileout = argv[2];
  tools.opcion = stoi(argv[3]);

  return tools;
}

/**
 * @brief Función para imprimir la ayuda
 * @return void
 */
void printHelp() {
  cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n"
       << "Donde:\n"
       << "  filein.txt: Fichero de entrada con el alfabeto y las cadenas.\n"
       << "  fileout.txt: Fichero de salida donde se escribirán los resultados.\n"
       << "  opcode: Operación a realizar (1-4):\n"
       << "    1: Longitud de cada cadena.\n"
       << "    2: Inversa de cada cadena.\n"
       << "    3: Comprobar si cada cadena es palíndroma.\n"
       << "    4: Comprobar si cada cadena pertenece al alfabeto.\n"
       << "Ejemplo:\n"
       << "  ./p02_strings input.txt output.txt 1\n";
}