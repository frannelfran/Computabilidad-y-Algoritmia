#include <iostream>
#include <fstream> // Para los ficheros
#include <vector>

using namespace std;

struct Tools {
  string filein;
  string fileout;
  int opcion;
};

Tools parseArgs(int argc, char* argv[]); // Parsea los argumentos de la línea de comandos
void printHelp();                      // Imprime la ayuda
