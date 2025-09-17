#include "alfabeto/alfabeto.h"
#include "cadena/cadena.h"
#include "lenguaje/lenguaje.h"
#include "tools/tools.h"

int main(int argc, char* argv[]) {
  try {
    Tools argumentos = parseArgs(argc, argv);
    
    // Leo el fichero de entrada
    vector<Cadena> cadenas = readFile(argumentos.filein);
    ofstream fileout(argumentos.fileout);

    // Ejecutamos las opciones
    switch (argumentos.opcode) {
      case 1: // Mostrar el alfabeto
        for (const auto& cadena : cadenas) {
          fileout << cadena.getAlfabeto() << endl;
        }
        break;
      case 2:
        for (const auto& cadena : cadenas) {
          fileout << cadena.longitud() << endl;
        }
        break;
      case 3:
        for (const auto& cadena : cadenas) {
          fileout << cadena.inversa() << endl;
        }
        break;
      case 4:
        for (const auto& cadena : cadenas) {
          fileout << cadena.prefijos() << endl;
        }
        break;
      case 5:
        for (const auto& cadena : cadenas) {
          fileout << cadena.sufijos() << endl;
        }
        break;
    }
    cout << "Operación realizada con éxito. Resultados en " << argv[2] << endl;
    fileout.close();

    return 0;
  } catch (const exception& e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }
}