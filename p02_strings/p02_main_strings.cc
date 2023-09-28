#include "p02_strings.h"
#include "p02_alfabeto.h"
#include "p02_lenguaje.h"

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
  if(argc == 2) {
    string ayuda = argv[1];
    if(ayuda == "--help") { // Muestra el modo de empleo del programa
      cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << endl;
      exit(EXIT_SUCCESS);
    }
  }
  else if(argc != 4) { // Verifica que se ha introducido un fichero como argumento
    cout << "Pruebe ./p02_strings --help para más información" << endl;
    return 1;
  }
  // ARGUMENTOS DE ENTRADA
  string fichero_entrada = argv[1]; // Fichero de entrada como argumento
  string fichero_salida = argv[2]; // FIchero de salida como argumento
  int opcode = stoi(argv[3]); // Opcode
  
  ifstream filein(fichero_entrada); // Leo el fichero de entrada
  ofstream fileout(fichero_salida); // Escribo en el fichero de salida
  string mi_cadena;
  while(filein >> mi_cadena) {
    Cadena c1(mi_cadena);
    // TIPOS DE OPCIONES
    switch(opcode) {
      case 1: { // Muestra el alfabeto de cada cadena
        set<char> mi_alfabeto = c1.alfabeto();
        Alfabeto a1(mi_alfabeto);
        fileout << a1;
        break;
      }
      case 2: // Muestra la longitud de cada cadena
        fileout << c1.longitud() << endl;
        break;
      case 3: // Muestra la cadena inversa 
        c1.inversa();
        fileout << c1 << endl;
        break;
      case 4: { // Muestra los prefijos asociados a cada cadena
        set<string> mi_prefijo = c1.prefijos();
        Lenguaje leng1(mi_prefijo);
        fileout << leng1 << endl;
        break;
      }
      case 5: { // Muestra los sufijos asociados a cada cadena
        set<string> mi_sufijo = c1.sufijos();
        Lenguaje leng2(mi_sufijo);
        fileout << leng2 << endl;
        break;
      }
    }
  }
  filein.close(); // Cerramos el fichero de entrada
  fileout.close(); // Cerramos el fichero de salida
  return 0;
}