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
  string mi_cadena;
  int opcion;
  cin >> opcion;
  while(filein >> mi_cadena) {
    Cadena c1(mi_cadena);
    switch(opcion) {
      case 1: // Muestra el alfabeto asociado a la cadena
      c1.alfabeto();
      break;
      case 2: // Muestra la longitud asociada a cada cadena
      int longitud;
      longitud = c1.longitud();
      cout << longitud << endl;
      break;
      case 3: // Muestra la inversa de la cadena
      c1.inversa();
      break;
    }
  }
}
