// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 05/11/2025
// Archivo: main.cc
// Descripción: Programa principal para convertir una gramática a FNC

#include "tools/tools.h"
#include "algoritmo/fnc/fnc.h"

int main(int argc, char* argv[]) {
  try {
    // Obtengo la gramática a partir del fichero de entrada
    Tools datosGram = parseArgs(argc, argv);


    // Creo la gramática con los datos obtenidos
    Gramatica gramatica(datosGram.terminales, datosGram.noTerminales, datosGram.producciones);
    // Muestro la gramática leída
    cout << "Fichero leído correctamente. \n";
    cout << "Gramática obtenida:\n";
    cout << gramatica;

    // Aplico el algoritmo de conversión a FNC
    FNC fnc;
    Gramatica gramaticaFNC = fnc.ejecutar(gramatica);

    // Vuelco la gramatica en el fichero
    ofstream ficheroSalida(datosGram.ficheroSalida);
    if (!ficheroSalida.is_open()) {
      throw invalid_argument("No se pudo abrir el fichero de salida.");
    }
    ficheroSalida << gramaticaFNC;
    cout << "Gramática en FNC volcada en el fichero de salida correctamente.\n";
    
    ficheroSalida.close();
  } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }
}