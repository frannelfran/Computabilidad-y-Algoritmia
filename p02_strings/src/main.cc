#include "alfabeto/alfabeto.h"
#include "cadena/cadena.h"
#include "lenguaje/lenguaje.h"
#include "tools/tools.h"

int main(int argc, char* argv[]) {
  try {
    vector<Cadena> cadenas = parseArgs(argc, argv);

    






    return 0;

  } catch (const exception& e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }




}