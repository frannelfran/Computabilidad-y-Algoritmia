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
  datos = leerFichero(argv[1]);
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
  // Leo el alfabeto
  leerAlfabeto(istringstream(linea));

  // Leo el numero de estados
  getline(file, linea);
  int numEstados;
  numEstados = stoi(linea);
  crearEstados(numEstados);

  // Leo el estado inicial
  getline(file, linea);
  comprobarEstado(stoi(linea));
  for (Estado* estado : datos.estados) {
    if (estado->getId() == stoi(linea)) {
      estado->setInicial();
      break;
    }
  }

  // Leo las transiciones
  while (getline(file, linea)) {
    if (linea.empty() || linea[0] == '#') {
      continue;
    }
    leerTransiciones(istringstream(linea));
  }
  return datos;
}

/**
 * @brief Función para crear los estados del autómata
 * @param numEstados Número de estados a crear
 * @return void
 */
void crearEstados(const int& numEstados) {
  for (int i = 0; i < numEstados; i++) {
    datos.estados.insert(new Estado(i));
  }
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
  static int id = 0; // ID de la transición
  bool aceptacion = false;
  int numTransiciones, actual, destino;
  char simboloEntrada;
  is >> actual >> aceptacion >> numTransiciones;
  // Compruebo si el estado actual pertenece al conjunto de estados
  comprobarEstado(actual);
  Estado* estadoActual = buscarEstado(actual);
  // Compruebo si es de aceptacion
  if (aceptacion) { 
    estadoActual->setAceptacion(); 
  }
  // Leo las transiciones
  for (int i = 1; i <= numTransiciones; ++i) {
    is >> simboloEntrada >> destino;
    // Compruebo tanto el estado destino como el símbolo de entrada
    comprobarEstado(destino), comprobarSimboloEntrada(simboloEntrada);
    Estado* estadoDestino = buscarEstado(destino);
    estadoActual->agregarTransicion(Transicion(++id, simboloEntrada, estadoActual, estadoDestino));
  }
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
 * @brief Función para comprobar si el automata es un DFA
 * @param estados Conjunto de estados del autómata
 * @return true si es un DFA, false en caso contrario
 */
bool esDfa(const set<Estado*>& estados) {
  for (Estado* estado : estados) {
    set<char> simbolosLeidos;
    for (const Transicion& transicion : estado->getTransiciones()) {
      char simbolo = transicion.getLecturaCadena();
      if (simbolosLeidos.find(simbolo) != simbolosLeidos.end()) {
        return false; // Símbolo repetido, no es un DFA
      }
      simbolosLeidos.insert(simbolo);
    }
  }
  return true;
}

/**
 * @brief Función para comprobar si el simbolo de entrada pertenece al alfabeto
 * @param simbolo Símbolo a comprobar
 * @return void
 */
void comprobarSimboloEntrada(const char& simbolo) {
  if (!datos.alfabeto.pertenece(simbolo)) {
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