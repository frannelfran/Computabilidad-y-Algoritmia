#include "tools.h"

Tools datos; // Datos para almacenar las propiedades de la gramática

/**
 * @brief Función para tomar los argumentos de la línea de comandos
 * @param argc Número de argumentos
 * @param argv Vector de argumentos
 * @return Estructura Tools con los argumentos parseados
 */

Tools parseArgs(int argc, char* argv[]) {
  Tools tools;
  if (argc < 3 && string(argv[1]) != "--help") {
    cerr << "Modo de empleo: " << argv[0] << " input.gra output.gra" << endl;
    cerr << "Pruebe " << argv[0] << " --help para más información." << endl;
    exit(EXIT_FAILURE);
  } else if (string(argv[1]) == "--help") { // Mostrar ayuda 
    printHelp();
    exit(EXIT_SUCCESS);
  }
  // Almaceno los argumentos
  if (string(argv[1]).find(".gra") == string::npos || string(argv[2]).find(".gra") == string::npos) {
    throw invalid_argument("Los ficheros deben tener extensión .gra.");
  }
  
  leerFichero(argv[1]);
  tools.ficheroSalida = argv[2];
  return tools;
}

/**
 * @brief Función para imprimir la ayuda del programa
 * @return void
 */
void printHelp() {
  cout << "Modo de empleo: ./grammar2CNF input.gra output.gra" << endl;
  cout << "Donde:" << endl;
  cout << "\ninput.gra     Fichero con la gramática ya simplificada." << endl;
  cout << "\noutput.gra    Fichero de salida con la gramática en CNF." << endl;
}

/**
 * @brief Función para leer una gramática desde un fichero
 * @param nombreFichero Nombre del fichero de entrada
 * @return Gramatica Leída desde el fichero
 */
void leerFichero(const string& nombreFichero) {
  ifstream fichero(nombreFichero);
  if (!fichero.is_open()) {
    throw runtime_error("No se pudo abrir el fichero: " + nombreFichero);
  }
  string linea;
  int simbolosterminales = 0, simbolosNoTerminales = 0, producciones = 0;
  // Leer alfabeto
  fichero >> simbolosterminales;
  for (int i = 0; i < simbolosterminales; ++i) {
    fichero >> linea;
    datos.terminales.insertar(Simbolo(linea, true));
  }

  // Leo los símbolos no terminales
  fichero >> simbolosNoTerminales;
  for (int i = 0; i < simbolosNoTerminales; ++i) {
    fichero >> linea;
    datos.noTerminales.insert(Simbolo(linea, false));
  }

  // Leo las producciones
  getline(fichero, linea);
  fichero >> producciones;
  for (int i = 0; i <= producciones; ++i) {
    getline(fichero, linea);
    leerProducciones(istringstream(linea));
  }

  fichero.close();
}

/**
 * @brief Función para leer las producciones desde un flujo de entrada
 * @param is Flujo de entrada
 * @return void
 */
void leerProducciones(istringstream is) {
  string simboloIzqm, produccion;
  is >> simboloIzqm >> produccion;
  comprobarSimbolo();







  cout << produccion << endl;
}

/**
 * @brief Función para comprobar si un simbolo es válido
 * @param simbolo Símbolo a comprobar
 * @return true si el símbolo es válido, false en caso contrario
 */
bool comprobarSimbolo(const string& simbolo) {
  // Compruebo si el simbolo es terminal
  if (!datos.terminales.pertenece(Simbolo(simbolo, true))) {
    cerr << datos.terminales << endl;
    throw invalid_argument("El símbolo " + simbolo + " no pertenece al alfabeto de terminales.");
  }
}