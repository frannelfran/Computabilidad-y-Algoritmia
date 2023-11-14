#include "estados.h"
#include "tupla.h"
#include "turing.h"


int main(int argc, char* argv[]) {
  // LECTURA DEL FICHERO
  ifstream file(argv[1]);
  // CREACIÓN DE LOS ESTADOS
  Estados est(file);
  // CREACIÓN DE LA TUPLA
  Tupla tup(file);
  // CREACIÓN DE LA MT
  TM turing(tup);
  cout << "Máquina de turing creada" << endl;
  cout << "---MENÚ---" << endl;
  cout << "Opción 1: Mostrar TM" << endl;
  cout << "Opción 2: Introducir cadena" << endl;
  cout << "----------" << endl;
  int opcion;
  cin >> opcion;
  switch (opcion) {
    case 1:
      cout << turing;
    break;
    case 2:
      string cadena;
      cin >> cadena;
    break;
  }
  file.close(); // Cerrar el fichero
  return 0;
}