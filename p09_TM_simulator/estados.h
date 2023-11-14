#include <iostream>
#include <fstream>

using namespace std;

class Estados {
  public:
  Estados(); // Constructor por defecto
  Estados(ifstream&); // Constructor de la clase estados
  int Inicial(); // Estado inicial
  bool Aceptacion(int); // Verificar si el estado es de aceptación

  private:
  int aceptacion_;
  int inicial_;
};