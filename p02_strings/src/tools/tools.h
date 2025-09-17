#pragma once
#include "../cadena/cadena.h"
#include "../alfabeto/alfabeto.h"
#include <fstream> // Para los ficheros
#include <vector>
#include <stdexcept> // Para las excepciones

using namespace std;

struct Tools {
  string filein;  // Fichero de entrada
  string fileout; // Fichero de salida
  int opcode;     // Operación a realizar
};

Tools parseArgs(int argc, char* argv[]); // Parsea los argumentos de la línea de comandos
vector<Cadena> readFile(const string& fileName); // Lee el fichero de entrada y devuelve un vector de Cadenas
void printHelp();                      // Imprime la ayuda
bool perteneceAlfabeto(const string& cadena, const string& alfabeto); // Comprueba si una cadena pertenece a un alfabeto
void mostrarMenu();              // Muestra el menú de opciones