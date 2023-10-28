#include "p07_alfabeto.h"
#include "p07_terminales.h"
#include "p07_producciones.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 2) {
    string ayuda = argv[1];
    if(ayuda == "--help" ) {
      cout << "Modo de empleo: ./Grammar2CNF input.gra output.gra" << endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc != 3) {
    cout << "Pruebe ‘Grammar2CNF --help’ para más información." << endl;
    return 1;
  }
  // LECTURA DE FICHEROS
  ifstream filein (argv[1]); // Fichero de entrada
  ofstream fileout (argv[2]); // Fichero de salida
  // CREAR EL ALFABETO
  Alfabeto alf(filein);
  fileout << alf;
  // CREAR LOS SÍMBOLOS TERMINALES
  Terminales term(filein);
  fileout << term;
  // CREAR LAS PRODUCCIONES
  Producciones prod(filein, alf, term);
  fileout << prod;
  
  // CIERRE DE FICHEROS
  filein.close();
  fileout.close();

  return 0;
}