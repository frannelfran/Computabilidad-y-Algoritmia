#include "p05_alfabeto.h"
#include "p05_conjunto_estados.h"
#include "p05_automata.h"

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 22/10/2023
// Archivo: p05_main_automata_simulator.cc
// Descripción: Programa principal

int main(int argc, char* argv[]) {
  if(argc == 2) {
    string ayuda = argv[1];
    if(ayuda == "--help" ) {
      cout << "Modo de empleo: ./p05_automata_simulator input.nfa output.dfa" << endl;
      exit(EXIT_SUCCESS);
    }
  }
  else if(argc != 3) {
    cout << "Pruebe ’p05_automata_simulator --help’ para más información." << endl;
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
    cout << cadena;
    if(autom.EsAceptada(cadena)) {
      cout << " --- Accepted" << endl;
    }
    else {
      cout << " --- Rejected" << endl;
    }
  }

  // CERRAMOS LOS FICHEROS
  filein1.close();
  filein2.close();
}