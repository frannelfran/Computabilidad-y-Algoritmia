#include "tools/tools.h"

int main(int argc, char* argv[]) {
  try {
    // Obtengo la gramática a partir del fichero de entrada
    Tools datosGram = parseArgs(argc, argv);


    // Creo la gramática con los datos obtenidos
    Gramatica gramatica(datosGram.terminales, datosGram.noTerminales, datosGram.producciones);
    // Muestro la gramática leída
    cout << "Fichero leído correctamente. \n";
    cout << "Gramática obtenida:\n";
    cout << gramatica;
  } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }
}