#include "../cadena/cadena.h"
#include "../alfabeto/alfabeto.h"
#include <fstream> // Para los ficheros
#include <vector>
#include <stdexcept> // Para las excepciones

using namespace std;

vector<Cadena> parseArgs(int argc, char* argv[]); // Parsea los argumentos de la línea de comandos
void printHelp();                      // Imprime la ayuda
bool perteneceAlfabeto(const string& cadena, const string& alfabeto); // Comprueba si una cadena pertenece a un alfabeto
void mostrarMenu();              // Muestra el menú de opciones