#ifndef TOOLS_H
#define TOOLS_H

#include "../alfabeto/alfabeto.h"
#include <stdexcept>

struct Tools {
  string ficheroEntrada;
  string ficheroSalida;
};

Tools parseArgs(int argc, char* argv[]); // Parsear argumentos de línea de comandos
void printHelp(); // Imprimir ayuda sobre el uso del programa


#endif // TOOLS_H