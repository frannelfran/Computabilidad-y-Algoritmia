#include "p02_strings.h"
#include "p02_alfabeto.h"

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
  if(argc != 4) { // Verifica que se ha introducido un fichero como argumento
    cout << "Pruebe ./p02_strings --help para más información" << endl;
    return 1;
  }
  string ayuda = argv[1];
  if(ayuda == "--help") {
    cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << endl;
    exit(EXIT_SUCCESS);
  }
  // ARGUMENTOS DE ENTRADA
  string fichero_entrada = argv[1]; // Fichero de entrada como argumento
  string fichero_salida = argv[2]; // FIchero de salida como argumento
  int opcode = stoi(argv[3]); // Opcode
  
  ifstream filein(fichero_entrada); // Leo el fichero de entrada
  ofstream fileout(fichero_salida);
  string mi_cadena;
  while(filein >> mi_cadena) {
    Cadena c1(mi_cadena);
    switch(opcode) {
      case 1: // Muestra el alfabeto de cada cadena
      set<char> mi_alfabeto;
      mi_alfabeto = c1.alfabeto();
      Alfabeto a1(mi_alfabeto);
      fileout << a1;
    }
  }
  filein.close(); // Cerramos el fichero de entrada
  fileout.close(); // erramos el fichero de salida
  return 0;
}
