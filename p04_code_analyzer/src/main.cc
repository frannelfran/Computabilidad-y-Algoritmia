// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 08/10/2025
// Archivo: main.cc
// Descripción: Programa principal que utiliza la clase Analizador para analizar un archivo de código fuente.

#include "tools/tools.h"
#include "analizador/analizador.h"

int main(int argc, char* argv[]) {
  try {
    Tools args = parseArgs(argc, argv);
    ifstream filein(args.filein);
    
    // Creo el analizador
    Analizador analizador;
    analizador.analizar(filein);

    ofstream fileout(args.fileout);
    fileout << "PROGRAM: " << args.filein << "\n";
    fileout << analizador;

    cout << "Análisis completado. Resultados guardados en " << args.fileout << endl;

    // Cerramos ficheros
    filein.close();
    fileout.close();
  } catch (const exception& e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }
  return 0;
}