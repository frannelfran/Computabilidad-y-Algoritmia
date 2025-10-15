#include "tools.h"

static Tools datos; // Variable global para almacenar los datos leídos

/**
 * @brief Función para leer los argumentos de la línea de comandos
 * @param argc Número de argumentos
 * @param argv Vector de argumentos
 * @return Estructura Tools con los datos leídos
 */
Tools readData(int argc, char* argv[]) {
  if (argc < 3 && string(argv[1]) != "--help") {
    cerr << "Modo de empleo: " << argv[0] << " <input.fa> <cadenas.txt>" << endl;
    cerr << "Pruebe " << argv[0] << " --help para más información." << endl;
    exit(EXIT_FAILURE);
  } else if (string(argv[1]) == "--help") { // Mostrar ayuda 
    printHelp();
    exit(EXIT_SUCCESS);
  }
  // Almaceno los argumentos
  if (string(argv[1]).find(".fa") == string::npos || string(argv[2]).find(".txt") == string::npos) {
    throw invalid_argument("Los ficheros deben tener extensión .fa y .txt respectivamente");
  }
  datos = leerFichero(string(argv[1]));
  datos.ficheroCadenas = string(argv[2]);
  return datos;
}

/**
 * @brief Función para imprimir la ayuda del programa
 * @return void
 */
void printHelp() {
  cerr << "Uso: automata <input.fa> <cadenas.txt>" << endl;
  cerr << "  <input.fa>    Archivo de descripción del autómata" << endl;
  cerr << "  <cadenas.txt> Archivo con las cadenas a procesar" << endl;
}

/**
 * @brief Dunción para leer el fichero de entrada y almacenar los datos en una estructura Tools
 * @param nombreFichero Nombre del fichero de entrada
 * @return Estructura Tools con los datos del fichero
 */
Tools leerFichero(const string& nombreFichero) {
  ifstream file(nombreFichero);

  if (!file.is_open()) { // Comprobar la lectura del fichero
    throw runtime_error("No se pudo abrir el fichero: " + nombreFichero);
  }

  string linea;
  // Saltar los comentarios y líneas vacías
  while (getline(file, linea)) {
    if (linea.empty() || linea[0] == '#') {
      continue;
    }
    break;
  }

  // Leo el alfabeto de entrada
  getline(file, linea);
  leerAlfabeto(istringstream(linea));

  // Leo el estado inicial
  getline(file, linea);
  comprobarEstado(stoi(linea));
  for (Estado* estado : datos.estados) {
    if (estado->getId() == stoi(linea)) {
      estado->setInicial();
      break;
    }
  }

  while (getline(file, linea)) {
    if (linea.empty() || linea[0] == '#') {
      continue;
    }
    leerTransiciones(istringstream(linea));
  }
  return datos;
}

/**
 * @brief Función para leer el conjunto de estados
 * @param is Stream de entrada
 * @return void
 */
void leerEstados(istringstream is) {
  string linea;
  set<Estado*> estados;
  while (is >> linea) {
    estados.insert(new Estado(stoi(linea)));
  }
  datos.estados = estados;
}

/**
 * @brief Función para leer los alfabetos del fichero
 * @param is Stream de entrada
 * @return void
 */
void leerAlfabeto(istringstream is) {
  string linea;
  while (is >> linea) {
    datos.alfabeto.insertar(linea[0]);
  }
}

/**
 * @brief Función para leer las transiciones del fichero
 * @param is Stream de entrada
 * @return void
 */
void leerTransiciones(istringstream is) {
  
}

/**
 * @brief Método para buscar un estado en el conjunto de estados
 * @param estado Estado a buscar
 * @return Puntero al estado si se encuentra, nullptr en caso contrario
 */
Estado* buscarEstado(const int& estado) {
  for (Estado* e : datos.estados) {
    if (e->getId() == estado) {
      return e;
    }
  }
  return nullptr;
}

/**
 * @brief Función para comprobar si el simbolo de entrada pertenece al alfabeto
 * @param simbolo Símbolo a comprobar
 * @return void
 */
void comprobarSimboloEntrada(const char& simbolo) {
  if (!datos.alfabeto.pertenece(simbolo)) {
    cerr << "Σ -> ";
    cerr << datos.alfabeto << endl;
    throw runtime_error("El símbolo '" + string(1, simbolo) + "' no pertenece al alfabeto de entrada (Σ).");
  }
}

/**
 * @brief Función para comprobar que los estados pertenecen al conjunto de estados
 * @param estado Estado a comprobar
 * @return void
 */
void comprobarEstado(const int& estado) {
  bool encontrado = false;
  for (Estado* e : datos.estados) {
    if (e->getId() == estado) {
      encontrado = true;
    }
  }

  if (!encontrado) {
    cerr << "Q -> {";
    for (auto it = datos.estados.begin(); it != datos.estados.end(); ++it) {
      cerr << (*it)->getId();
      if (next(it) != datos.estados.end()) {
        cerr << ", ";
      }
    }
    cerr << "}" << endl;
    throw runtime_error("El estado " + to_string(estado) + " no está en el conjunto de estados.");
  }
}