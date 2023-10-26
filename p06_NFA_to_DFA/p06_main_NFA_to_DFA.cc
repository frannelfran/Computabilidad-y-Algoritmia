#include "p06_alfabeto.h"
#include "p06_conjunto_estados.h"
#include "p06_automata.h"

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 26/10/2023
// Archivo: p06_main_NFA_to_DFA.cc

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
  ifstream filein(archivo1);
  ofstream fileout(archivo2); // Fichero donde se va a guardar el DFA
  // CONSTRUIR EL ALFABETO
  Alfabeto alf(filein);
  // CREAR EL CONJUNTO DE ESTADOS
  ConjuntoDeEstados conjest(filein);
  // CREAR EL AUTOMATA
  Automata autom(alf, conjest);
  cout << autom;
  Automata DFA = autom.ConstruirSubconjuntos();
  fileout << DFA;

  // CERRAMOS LOS FICHEROS
  filein.close();
  fileout.close();
}