#include "tools/tools.h"

int main(int argc, char* argv[]) {
  try {
    // Obtengo la gramática a partir del fichero de entrada
    Tools datosGram = parseArgs(argc, argv);
  } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }
}