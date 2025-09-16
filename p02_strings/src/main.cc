#include "alfabeto/alfabeto.h"
#include "cadena/cadena.h"
#include "lenguaje/lenguaje.h"
#include "tools/tools.h"

int main(int argc, char* argv[]) {
  try {
    vector<Cadena> cadenas = parseArgs(argc, argv);
    ofstream fileout(argv[2]);

    // Ejecutamos las opciones
    switch (stoi(argv[3])) {
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
      


    }

    cout << "Operación realizada con éxito. Resultados en " << argv[2] << endl;
    fileout.close();

    






    return 0;

  } catch (const exception& e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }




}