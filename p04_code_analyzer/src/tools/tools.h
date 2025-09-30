#include <iostream>
#include <stdexcept> // Para las excepciones

using namespace std;

/**
 * @struct Struct para almacenar los argumentos de la línea de comandos
 */
struct Tools {
  string filein;  // Fichero de entrada
  string fileout; // Fichero de salida
};

Tools parseArgs(int argc, char* argv[]); // Parsea los argumentos de la línea de comandos
void printHelp();                       // Imprime la ayuda