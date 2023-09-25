#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

template<class T> class Cadena {
  public:
    Cadena(ifstream&); // Constructor de la clase cadena
  private:
  vector<string> cadena_; // Atributo privado 
};

template<class T> Cadena<T>::Cadena(ifstream& filein) {
  string simbolo;
  while(filein >> simbolo) {
    cadena_.push_back(simbolo);
  }
  filein.close();
}