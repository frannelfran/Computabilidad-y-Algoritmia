#include "tools/tools.h"
#include "analizador/analizador.h"

int main(int argc, char* argv[]) {
  try {
    Tools args = parseArgs(argc, argv);
    ifstream filein(args.filein);
    
    // Creo el analizador
    Analizador analizador;
    analizador.analizar(filein);

    ofstream fileout(args.fileout);
    fileout << "PROGRAM: " << args.filein << "\n";
    fileout << analizador;

    cout << "Análisis completado. Resultados guardados en " << args.fileout << endl;

    // Cerramos ficheros
    filein.close();
    fileout.close();
  } catch (const exception& e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }
  return 0;
}