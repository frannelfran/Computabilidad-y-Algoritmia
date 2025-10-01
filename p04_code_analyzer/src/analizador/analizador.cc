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
    // Comprobar si lo primero del fichero es un comentario
    if (numeroLinea == 1 && (linea.find("/*") != string::npos || linea.find("//") != string::npos)) {
      procesarComentario(archivo, linea, numeroLinea);
      continue;
    }
    clasificar(archivo, linea, numeroLinea);
  }
}

/**
 * @brief Método para procesar el encabezado del archivo.
 * @param archivo Archivo fuente a analizar.
 * @param numLinea Número de línea actual (se actualizará si el comentario es multilínea).
 * @return void
 */
void Analizador::procesarComentario(ifstream& archivo, string linea, int& numLinea) {
  smatch match;
  
  // Si es comentario simple
  if (regex_search(linea, match, expresiones_.comentarioSimple)) {
    string tipo = (numLinea == 1) ? "descripcion" : "simple";
    crearComentario(tipo, numLinea, numLinea, match[0]);
    return;
  }
  
  // Si es comentario multilínea completo en una sola línea
  if (regex_search(linea, match, expresiones_.comentarioMultilinea)) {
    string tipo = (numLinea == 1) ? "descripcion" : "multilinea";
    crearComentario(tipo, numLinea, numLinea, match[0]);
    return;
  }
  
  // Si es inicio de comentario multilínea que continúa en varias líneas
  if (linea.find("/*") != string::npos && linea.find("*/") == string::npos) {
    int lineaInicio = numLinea;
    string comentarioCompleto = linea; // Empezar con la primera línea
    
    // Seguir leyendo líneas hasta encontrar el final
    while (getline(archivo, linea)) {
      numLinea++;
      comentarioCompleto += "\n" + linea; // Concatenar cada línea
      
      // Si encontramos el final del comentario, salir
      if (linea.find("*/") != string::npos) {
        break;
      }
    }
    
    string tipo = (lineaInicio == 1) ? "descripcion" : "multilinea";
    crearComentario(tipo, lineaInicio, numLinea, comentarioCompleto);
  }
}

/**
 * @brief Método para clasificar una línea de código.
 * @param linea Línea de código a clasificar.
 * @param principio Índice de inicio de la línea.
 * @param fin Índice de fin de la línea.
 * @return void
 */
void Analizador::clasificar(ifstream& archivo, const string& linea, int& numeroLinea) {
  smatch match;

  if (regex_search(linea, match, expresiones_.variableSinInicializar)) { // Variable sin inicializar
    crearVariable(match[1], numeroLinea, match[2]);
  } else if (regex_search(linea, match, expresiones_.variableInicializada)) { // Variable inicializada
    crearVariable(match[1], numeroLinea, match[2].str() + '=' + match[3].str(), true);
  } else if (regex_search(linea, match, expresiones_.bucle)) { // Bucles
    crearBucle(match[1], numeroLinea);
  } else if (regex_search(linea, match, expresiones_.main) && !main_) { // Main
    main_ = true;
  } else {
    procesarComentario(archivo, linea, numeroLinea);
  }
}

/**
 * @brief Método para crear una variable y añadirla al vector de variables.
 * @param tipo Tipo de la variable (int o double).
 * @param linea Línea en la que se declara la variable.
 * @param nombre Nombre de la variable.
 * @param valor Valor de la variable (0 por defecto si no está inicializada).
 */
void Analizador::crearVariable(const string& tipo, int linea, const string& nombre, bool inicializada) {
  if (inicializada) {
    string var, valor;
    // Buscar donde empieza el número (no hay '=' en el string)
    size_t pos = nombre.find('=');
    // Separar nombre y valor
    var = nombre.substr(0, pos);
    valor = nombre.substr(pos + 1);
    variables_.push_back(new VariableInicializada(tipo, linea, var, stod(valor)));
  } else {
    variables_.push_back(new Variable(tipo, linea, nombre));
  }
}

/**
 * @brief Método para crear un bucle y añadirlo al vector de bucles.
 * @param tipo Tipo de bucle (for o while).
 * @param linea Línea en la que se declara el bucle.
 */
void Analizador::crearBucle(const string& tipo, int linea) {
  bucles_.push_back(Bucle{tipo, linea});
}

/**
 * @brief Método para crear un comentario y añadirlo al vector de comentarios.
 * @param tipo Tipo de comentario (descripcion, multilinea, simple).
 * @param principio Línea en la que empieza el comentario.
 * @param fin Línea en la que termina el comentario.
 * @param contenido Contenido del comentario.
 */
void Analizador::crearComentario(const string& tipo, int principio, int fin, const string& contenido) {
  comentarios_.push_back(Comentario{tipo, principio, fin, contenido});
}