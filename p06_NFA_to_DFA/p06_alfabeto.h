#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <queue>
#pragma once

using namespace std;

class Alfabeto {
  public:
  Alfabeto(); // Constructor predeterminado de la clase
  Alfabeto(ifstream&); // Constructor de la clase
  set<char> getAlfabeto(); // Devuelve el alfabeto
  friend ostream& operator<<(ostream& os, const Alfabeto& alfabeto);
  private:
  set<char> alfabeto_;
};