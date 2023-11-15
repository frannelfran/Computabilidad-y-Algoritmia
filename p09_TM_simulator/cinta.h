#include <iostream>
#include <fstream>
#include <tuple>
#include <map>
#include <set>
#pragma once

using namespace std;

class Cinta {
  public:
  Cinta();
  Cinta(ifstream&); // Constructor de la clase
  multimap<int, tuple<char, char, char, int>> GetCinta(); // Obtener la cinta de la máquina
  bool Pertenece(string&); // Verificar que la cadena pertenece al alfabeto de la cinta
  friend ostream& operator<<(ostream& os, Cinta& cint); // Sobrecarga del operador <<
  private:
  multimap<int, tuple<char, char, char, int>> cinta_; // Cinta
  set<char> alfabeto_; // Alfabeto de la cinta
};