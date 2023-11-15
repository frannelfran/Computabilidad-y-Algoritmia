#include "cinta.h"
#include "turing.h"

int main(int argc, char* argv[]) {
  ifstream file(argv[1]);
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
  cout << "Creando de turing..." << endl;
  cout << "---MENÚ---" << endl;
  cout << "Opción 1: Mostrar máquina de turing" << endl;
  cout << "Opción 2: Introducir una cadena en la máquina" << endl;
  cout << "Opción 0: Salir" << endl;
  cout << "------" << endl;
  int opcion;
  do {
    cin >> opcion;
    switch (opcion) {
      case 0:
      break;
      case 1:
        cout << tm;
      break;
      case 2:
        string cadena;
        cin >> cadena;
        tm.Funcionamiento(cadena);
      break;
    }
  } while (opcion != 0);
  file.close();
  return 0;
}