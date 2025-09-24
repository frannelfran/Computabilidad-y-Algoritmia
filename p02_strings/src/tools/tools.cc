#include "tools.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Lenguajes
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 24/09/2025
// Archivo: tools.cc
// Descripción: Funciones para manejar los argumentos y ficheros

/**
 * @brief Función para tomar los argumentos de la línea de comandos
 * @param argc Número de argumentos
 * @param argv Vector de argumentos
 * @return Estructura Tools con los argumentos parseados
 */

Tools parseArgs(int argc, char* argv[]) {
  if ((argc < 4 || argc > 4) && string(argv[1]) != "--help") {
    cerr << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode " << endl;
    cerr << "Pruebe ./p02_strings --help para más información." << endl;
    exit(EXIT_FAILURE);
  } else if (string(argv[1]) == "--help") { // Mostrar ayuda 
    printHelp();
    exit(EXIT_SUCCESS);
  }
   else if (stoi(argv[3]) < 1 || stoi(argv[3]) > 5) { // Manejar el opcode
    throw invalid_argument("Error: El opcode debe ser un número entre 1 y 5.");
  }

  // Almaceno los argumentos
  Tools tool;
  tool.filein = argv[1];
  tool.fileout = argv[2];
  tool.opcode = stoi(argv[3]);

  return tool;
}

/**
 * @brief Función para leer el fichero de entrada
 * @param filename Nombre del fichero
 * @return Vector de Cadenas leídas del fichero
 */
vector<Cadena> readFile(const string& fileName) {
  ifstream filein(fileName);

  if (filein.fail()) {
    throw invalid_argument("Error: No se pudo abrir el fichero " + fileName);
  }

  string cadena, alfabeto;
  vector<Cadena> cadenas;

  while (filein >> cadena >> alfabeto) {
    if (!perteneceAlfabeto(cadena, alfabeto)) {
      throw invalid_argument("Error: La cadena '" + cadena +
                             "' no pertenece al alfabeto '" + alfabeto + "'.");
    }
    else {
      Cadena c(cadena, Alfabeto(alfabeto));
      cadenas.push_back(c);
    }
  }

  filein.close(); // Cierro el fichero
  return cadenas;
}

/**
 * @brief Función para comprobar si la cadena pertenece al alfabeto
 * @param cadena Cadena a comprobar
 * @param alfabeto Alfabeto
 * @return true si la cadena pertenece al alfabeto, false en caso contrario
 */
bool perteneceAlfabeto(const string& cadena, const string& alfabeto) {
  for (char c : cadena) {
    if (alfabeto.find(c) == string::npos) {
      return false; // Si el carácter no está en el alfabeto, retorna false
    }
  }
  return true; // Todos los caracteres están en el alfabeto
}

/**
 * @brief FUnción para mostrar el menú de opciones
 * @return void
 */
void mostrarMenu() {
  cout << "Seleccionar una opción de las siguientes:\n"
       << "1. Mostrar el alfabeto.\n"
       << "2. Mostrar la longitud de cada cadena.\n"
       << "3. Mostrar la inversa de cada cadena.\n"
       << "4. Calcular los prefijos de cada cadena.\n"
       << "5. Calcular los sufijos de cada cadena.\n";
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
       << "  opcode: Operación a realizar (1-5):\n";
  mostrarMenu();
}