#include "p06_alfabeto.h"
#include "p06_conjunto_estados.h"
#include "p06_automata.h"

using namespace std;

int main(int argc, char* argv[]) {
  if(argc == 2) {
    string ayuda = argv[1];
    if(ayuda == "--help" ) {
      cout << "Modo de empleo: ./NFA2DFA input.nfa output.dfa" << endl;
      exit(EXIT_SUCCESS);
    }
  }
  else if(argc != 3) {
    cout << "Pruebe ’NFA2DFA --help’ para más información." << endl;
    return 1;
  }
  // LECTURA DE LOS FICHEROS
  string archivo1 = argv[1];
  string archivo2 = argv[2];
  ifstream filein1(archivo1);
  ifstream filein2(archivo2);
  // CONSTRUIR EL ALFABETO
  Alfabeto alf(filein1);
  // CREAR EL CONJUNTO DE ESTADOS
  ConjuntoDeEstados conjest(filein1);
  // CREAR EL AUTOMATA
  Automata autom(alf, conjest);
  // Comprobar si la cadena es aceptada por el autómata
  string cadena;
  while(filein2 >> cadena) {
    bool aceptada = autom.EsAceptada(cadena);
    cout << cadena << " --- " << (aceptada ? "Accepted" : "Rejected") << endl;
  }

  // CERRAMOS LOS FICHEROS
  filein1.close();
  filein2.close();
  return 0;
}