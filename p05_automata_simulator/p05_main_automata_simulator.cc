#include "p05_nodo.h"
#include "p05_alfabeto.h"
#include "p05_estado.h"
#include "p05_automata.h"

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

Alfabeto crear_alfabeto(ifstream& file) {
  string mi_alfabeto;
  getline(file, mi_alfabeto);
  Alfabeto alf(mi_alfabeto);
  return alf;
}

ConjuntoDeEstado crear_conjunto(ifstream& file) {
  ConjuntoDeEstado sopa;
  int nodo, num_estado, transiciones, inicial, siguiente, aceptacion;
  char caracter;
  file >> num_estado; // Leemos el número de estados
  file >> inicial; // Leemos el nodo inicial
  for(int it = 0; it < num_estado; it++) {
    file >> nodo; // Leemos el nodo
    file >> aceptacion; // Leemos si es de aceptacion
    file >> transiciones; // Leemos el número de transiciones
    for(int it2 = 0; it2 < transiciones; it2++) {
      file >> caracter;
      file >> siguiente;
      Nodo nodo(caracter, siguiente, aceptacion);
    }
    
  }

  
  
  return sopa;





}

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
  ifstream filein2(entrada2);
  // CREAR EL ALFABETO
  Alfabeto alf = crear_alfabeto(filein1);
  // CREAR EL NÚMERO DE ESTADOS CON SUS TRANSICIONES
  ConjuntoDeEstado conjest = crear_conjunto(filein1);



  // Cerrar lops ficheros
  filein1.close();
  filein2.close();

  return 0;
}