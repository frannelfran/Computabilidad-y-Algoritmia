#include "tools/tools.h"
#include "automata/dfa/dfa.h"
#include "automata/nfa/nfa.h"
#include <iostream>

using namespace std;

/**
 * @brief Función principal del programa
 * @param argc Número de argumentos
 * @param argv Vector de argumentos
 * @return Código de salida
 */

int main(int argc, char* argv[]) {
  try {
    Tools datos = readData(argc, argv);
    cout << "Fichero leído correctamente." << endl;
    // Creo  el autómata

    Automata* automata;

    if (esDfa(datos.estados)) {
      automata = new DFA(datos.estados, datos.alfabeto);
      cout << "El autómata es un DFA." << endl;
    } else {
      automata = new NFA(datos.estados, datos.alfabeto);
      cout << "El autómata es un NFA." << endl;
    }

    cout << *automata;
    string cadena;

    ifstream cadenas(datos.ficheroCadenas); // Abro el fichero de cadenas
    
    while (cadenas >> cadena) {
      automata->reiniciar(); // Reinicio el autómata antes de cada ejecución
      cout << cadena << " --- ";
      if (automata->ejecutar(cadena)) {
        cout << "Accepted" << endl;
      } else {
        cout << "Rejected" << endl;
      }
    }

    return 0;
  } catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }
}