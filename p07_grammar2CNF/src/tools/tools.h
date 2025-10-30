#ifndef TOOLS_H
#define TOOLS_H

#include "../gramatica/gramatica.h"
#include <fstream> // Para manejar los ficheros
#include <stdexcept>
#include <sstream>

struct Tools {
  Alfabeto terminales;
  set<Simbolo> noTerminales;
  vector<vector<Produccion>> producciones;
  string ficheroSalida;
};

Tools parseArgs(int argc, char* argv[]); // Parsear argumentos de línea de comandos
void printHelp(); // Imprimir ayuda sobre el uso del programa
void leerFichero(const string& nombreFichero); // Leer gramática desde fichero
void leerProducciones(const string& noTerminal, const string& produccion); // Leer producciones desde fichero
bool comprobarSimbolo(const Simbolo& simbolo); // Comprobar si un símbolo es válido
bool esTerminal(const Simbolo& simbolo); // Comprobar si un símbolo es terminal

#endif // TOOLS_H