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
  set<char> GetAlfabeto(); // Obtener la cinta
  friend ostream& operator<<(ostream& os, Cinta& cint);
  private:
  multimap<int, tuple<char, char, char, int>> cinta_;
  set<char> alfabeto_;
};