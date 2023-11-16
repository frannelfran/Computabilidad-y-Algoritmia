#include "cinta.h"
#include "turing.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 15/11/2023
// Archivo:main_TM_simulator.cc

int main(int argc, char* argv[]) {
  if (argc == 2) {
    string ayuda = argv[1];
    if(ayuda == "--help" ) {
      cout << "Modo de empleo: ./TM_simulator ejemplo.tm cadena.tape" << endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc != 3) {
    cout << "Pruebe ‘TM_simulator --help’ para más información." << endl;
    return 1;
  }

  // LECTURA DE FICHEROS
  ifstream file(argv[1]);
  ifstream file_cadena(argv[2]);
  int num_estados, estado{0};
  file >> num_estados;
  // CREO EL CONJUNTO DE ESTADOS
  set<int> estados, aceptance;
  while (num_estados != 0) {
    estados.insert(estado);
    estado++;
    num_estados--;
  }
  // Almaceno el estado inicial y los estados de aceptación
  int inicial;
  string aceptacion;
  file >> inicial;
  getline(file >> ws, aceptacion);
  // Creo el conjunto de estados de aceptación
  for (char simbolo : aceptacion) {
    if (!isspace(simbolo)) {
      aceptance.insert(simbolo - '0');
    }
  }
  // CREAR LA CINTA
  Cinta cint(file);
  // CREAR LA TM
  TM tm(cint, estados, aceptance, inicial);
  string opcion, contenido_cinta;
  cout << "Desea mostrar la máquina ? (Si | No) ";
  cin >> opcion;
  if (opcion == "Si") {
    cout << "---MÁQUINA DE TURING---" << endl;
    cout << tm;
  }
  file_cadena >> contenido_cinta;
  cout << "---PROCESOS DE LA MÁQUINA---" << endl;
  tm.Funcionamiento(contenido_cinta);

  // CERRAR LOS FICHEROS
  file.close();
  file_cadena.close();
  return 0;
}