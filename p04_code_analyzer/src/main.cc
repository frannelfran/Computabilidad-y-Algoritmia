#include "tools/tools.h"
#include "analizador/analizador.h"

int main(int argc, char* argv[]) {
  try {
    Tools args = parseArgs(argc, argv);
    ifstream filein(args.filein);
    
    // Creo el analizador
    Analizador analizador;
    analizador.analizar(filein);

    // Cerramos ficheros
    filein.close();

    
  } catch (const exception& e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }
  return 0;
}