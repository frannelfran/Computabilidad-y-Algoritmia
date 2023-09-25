#include "p02_strings.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 25/09/2023
// Archivo p02_main_strings.cc

int main(int argc, char *argv[]) {
  string elemento;
  if(argc != 2) { // Verifica que se ha introducido un fichero como argumento
    cout << "Pruebe ./p02_strings --help para más información" << endl;
    return 1;
  }
  string ayuda = argv[1];
  if(ayuda == "--help") {
    cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << endl;
    exit(EXIT_SUCCESS);
  } 
  string fichero_entrada = argv[1];
  ifstream filein(fichero_entrada);
  cout << "Abriendo " << fichero_entrada << "..." << endl;
  Language<string> registro(filein);
  registro.alfabeto();
}