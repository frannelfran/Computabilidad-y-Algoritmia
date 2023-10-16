#include "p05_alfabeto.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un simulador de autómatas finitos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 15/10/2023
// Archivo p05_main_automata_simulator

int main(int argc, char *argv[]) {
  if(argc == 2) {
    string ayuda = argv[1];
    if(ayuda == "--help" ) {
      cout << "Modo de empleo: ./p05_automata_simulator input.fa input.txt" << endl;
      exit(EXIT_SUCCESS);
    }
  }
  else if(argc != 3) {
    cout << "Pruebe ’p05_automata_simulator --help’ para más información." << endl;
    return 1;
  }
  // LECTURA DE LOS FICHEROS DE ENTRADA
  string entrada1 = argv[1];
  string entrada2 = argv[2];
  ifstream filein1(entrada1);
  ifstream filein12(entrada2);
  // Mostrar el alfabeto
  Alfabeto alf(filein1);
  cout << "Alfabeto del automata: " << alf << endl;
  


  return 0;
}